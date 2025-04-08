#include "raylib.h"
#include "game.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size_enemies[3] = {100, 100, 110};
char shortwords[200][15]; 
char mediumwords[100][15];
char longwords[100][15];

float wave_timer = 0.0f;
float wave_interval = 10.0f;
int enemies_per_wave = 4;
int enemies_spawned_this_wave = 0;

Texture2D enemy_textures[3];


float enemy_speed_multiplier = 1.0f;
float medium_word_chance = 0.2f;
float long_word_chance = 0.1f;

void InitTexts(void) {
    FILE *fileshort = fopen("txt_files/shortwords.txt", "r");
    FILE *filemedium = fopen("txt_files/mediumwords.txt", "r");
    FILE *filelong = fopen("txt_files/longwords.txt", "r");

    for (int i = 0; i < 200; i++) {
        fscanf(fileshort, "%s\n", shortwords[i]);
        if (i < 100) {
            fscanf(filemedium, "%s\n", mediumwords[i]);
            fscanf(filelong, "%s\n", longwords[i]);
        }
    }
    fclose(fileshort);
    fclose(filemedium);
    fclose(filelong);
}

bool IsPositionFree(EnemyList* enemy_list, Rectangle new_enemy_rect) {
    for (int i = 0; i < enemy_list->qty_enemies; i++) {
        if (CheckCollisionRecs(new_enemy_rect, enemy_list->enemies[i].rect)) {
            return false;
        }
    }
    return true;
}

void DrawEnemies(EnemyList* enemy_list, Font myfont, Texture2D enemyTextures[]) {
    for (int i = 0; i < enemy_list->qty_enemies; i++) {
        Enemy enemy = enemy_list->enemies[i];
        Texture2D texture = enemyTextures[enemy.texture_index];

        Vector2 center = {
            enemy.rect.x + enemy.rect.width / 2.0f,
            enemy.rect.y + enemy.rect.height / 2.0f
        };
        Vector2 origin = { texture.width / 2.0f, texture.height / 2.0f };

        DrawTexturePro(texture,
            (Rectangle){ 0, 0, (float)texture.width, (float)texture.height },
            (Rectangle){ center.x, center.y, enemy.rect.width, enemy.rect.height },
            origin,
            enemy.angle,
            WHITE
        );

        int word_size = strlen(enemy.word);
        float text_size = 30.0f;
        float spacing = 0;
        Vector2 word_size_measure = MeasureTextEx(myfont, enemy.word, text_size, spacing);
        float text_x = center.x - word_size_measure.x / 2;
        float text_y = center.y + enemy.rect.height / 2.0f;

        if (enemy.index_typing == 0) {
            DrawTextEx(myfont, enemy.word, (Vector2){ text_x, text_y }, text_size, spacing, WHITE);
        } else {
            for (int j = 0; j < word_size; j++) {
                if (j < enemy.index_typing) continue;
                Color letterColor = enemy.locked ? BLUE : WHITE;
                DrawTextEx(myfont, TextFormat("%c", enemy.word[j]),
                           (Vector2){ text_x + (15 * j), text_y }, text_size, spacing, letterColor);
            }
        }
    }
}

void SpawnEnemy(EnemyList* enemy_list) {
    int i;
    float chance = GetRandomValue(0, 100) / 100.0f;

    if (chance < long_word_chance) {
        i = 2;
    } else if (chance < long_word_chance + medium_word_chance) {
        i = 1;
    } else {
        i = 0;
    }

    int size_chosen = size_enemies[i];

    Enemy enemy;
    enemy.color = RED;
    enemy.rect.width = size_chosen;
    enemy.rect.height = size_chosen;
    enemy.speed = 2.0f * enemy_speed_multiplier;
    enemy.locked = 0;
    enemy.index_typing = 0;
    enemy.delay_speed = 0;

    Rectangle new_enemy_rect;
    int attempts = 0;
    do {
        new_enemy_rect = (Rectangle){
            GetRandomValue(0, 1280 - size_chosen),
            -100,
            size_chosen,
            size_chosen
        };
        attempts++;
    } while (!IsPositionFree(enemy_list, new_enemy_rect) && attempts < 10);

    enemy.rect = new_enemy_rect;

    if (i == 0) {
        strcpy(enemy.word, shortwords[GetRandomValue(0,199)]);
    } else if (i == 1) {
        strcpy(enemy.word, mediumwords[GetRandomValue(0,99)]);
    } else {
        strcpy(enemy.word, longwords[GetRandomValue(0,99)]);
    }

    int same_initial = 1;
    while (same_initial) {
        same_initial = 0;
        for (int i = 0; i < enemy_list->qty_enemies; i++) {
            if (enemy_list->enemies[i].word[0] == enemy.word[0]) {
                same_initial = 1;
                if (size_chosen == size_enemies[0]) {
                    strcpy(enemy.word, shortwords[GetRandomValue(0,199)]);
                } else if (size_chosen == size_enemies[1]) {
                    strcpy(enemy.word, mediumwords[GetRandomValue(0,99)]);
                } else {
                    strcpy(enemy.word, longwords[GetRandomValue(0,99)]);
                }
                break;
            }
        }
    }

    enemy.texture_index = i;
    enemy.angle = 0.0f;
    enemy.health = strlen(enemy.word);
    enemy_list->enemies[enemy_list->qty_enemies] = enemy;
    enemy_list->qty_enemies++;
}

void UpdateEnemyWaves(EnemyList* enemy_list) {
    wave_timer += GetFrameTime();

    if (wave_timer >= wave_interval) {
        wave_timer = 0.0f;
        enemies_spawned_this_wave = 0;

        
        enemy_speed_multiplier += 0.1f;
        if (medium_word_chance < 0.5f) medium_word_chance += 0.05f;
        if (long_word_chance < 0.3f) long_word_chance += 0.03f;
    }

    if (enemies_spawned_this_wave < enemies_per_wave) {
        SpawnEnemy(enemy_list);
        enemies_spawned_this_wave++;
    }
}

void RemoveEnemy(EnemyList* enemy_list, int index_enemy) {
    PlaySound(morteSound);
    for (int i = index_enemy; i < enemy_list->qty_enemies - 1; i++) {
        enemy_list->enemies[i] = enemy_list->enemies[i + 1];
    }
    enemy_list->qty_enemies--;
} 

void MoveEnemies(EnemyList* enemy_list, Player* player) {
    for (int i = 0; i < enemy_list->qty_enemies; i++) {
        Enemy enemy = enemy_list->enemies[i];
        Vector2 enemy_center = {enemy.rect.x + enemy.rect.width / 2, enemy.rect.y + enemy.rect.height / 2};
        float dx = player->rect.x - enemy_center.x;
        float dy = player->rect.y - enemy_center.y;
        float distance = sqrt(dx*dx + dy*dy);

        if (enemy.health == 0) {
            RemoveEnemy(enemy_list, i);
            i--;
            continue;
        }

        if (!CheckCollisionRecs(player->rect, enemy.rect)) {
            enemy_list->enemies[i].rect.x += (dx / distance) * enemy.speed;
            enemy_list->enemies[i].rect.y += (dy / distance) * enemy.speed;
        } else {
            if (enemy_list->enemies[i].locked) {
                state = NOTLOCKED;
            }
            RemoveEnemy(enemy_list, i);
            i--;
        }
    }
}

void DelayEnemies(EnemyList* enemy_list) {
    for (int i = 0; i < enemy_list->qty_enemies; i++) {
        Enemy* enemy = &enemy_list->enemies[i];
        if (enemy->delay_speed > 0) {
            enemy->speed = 0.5f;
            enemy->delay_speed -= GetFrameTime();
        } else {
            enemy->speed = 2.0f * enemy_speed_multiplier;
        }
    }
}
