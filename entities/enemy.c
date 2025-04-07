#include "raylib.h"
#include "game.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size_enemies[3] = {20, 40, 60};
char shortwords[200][15]; 
char mediumwords[100][15];
char longwords[100][15];

float wave_timer = 0.0f;
float wave_interval = 10.0f;
int enemies_per_wave = 5;
int enemies_spawned_this_wave = 0;

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

void DrawEnemies(EnemyList* enemy_list, Font myfont) {
    for (int i = 0; i < enemy_list->qty_enemies; i++) {
        Enemy enemy = enemy_list->enemies[i];
        int word_size = strlen(enemy.word);
        Vector2 word_size_measure = MeasureTextEx(myfont, enemy.word, 30, 0);
        float center_x_enemy = enemy.rect.x + (enemy.rect.width / 2); 

        float position_text_x = center_x_enemy - (word_size_measure.x / 2);
        float position_text_y = enemy.rect.y + (enemy.rect.height * 0.9);

        DrawRectangleRec(enemy.rect, enemy.color);
        if (enemy.index_typing == 0) {
            DrawTextEx(myfont, enemy.word, ((Vector2){ position_text_x, position_text_y }), 30, 0, WHITE);
        } else {
            for (int i = 0; i < word_size; i++) {
                if (i < enemy.index_typing) {
                    DrawCircle(-1,-1, 0, BLACK);
                } else {
                    DrawTextEx(myfont, TextFormat("%c", enemy.word[i]), ((Vector2){ position_text_x + (15*i), position_text_y }), 30, 0, (enemy.locked) ? RED : WHITE);
                }
            }
        }
    }
}

void SpawnEnemy(EnemyList* enemy_list) {
    int i = GetRandomValue(0, 2);
    int size_chosen = size_enemies[i];

    Enemy enemy;
    enemy.color = RED;
    enemy.rect = (Rectangle) {GetRandomValue(0, 1280), -100, size_chosen, size_chosen};
    enemy.speed = 2.0;
    enemy.locked = 0;
    enemy.index_typing = 0;
    enemy.delay_speed = 0;
    
    if (size_chosen == size_enemies[0]) {
        strcpy(enemy.word, shortwords[GetRandomValue(0,199)]);
    } else if (size_chosen == size_enemies[1]) {
        strcpy(enemy.word, mediumwords[GetRandomValue(0,99)]);
    } else if (size_chosen == size_enemies[2]) {
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
                } else if (size_chosen == size_enemies[2]) {
                    strcpy(enemy.word, longwords[GetRandomValue(0,99)]);
                }
                break;
            }
        }
    }

    enemy.health = strlen(enemy.word);
    enemy_list->enemies[enemy_list->qty_enemies] = enemy;
    enemy_list->qty_enemies++;
}
void UpdateEnemyWaves(EnemyList* enemy_list) {
    wave_timer += GetFrameTime();

    if (wave_timer >= wave_interval) {
        wave_timer = 0.0f;
        enemies_spawned_this_wave = 0;
    }
    if (enemies_spawned_this_wave < enemies_per_wave) {
        SpawnEnemy(enemy_list);
        enemies_spawned_this_wave++;
    }
}

void RemoveEnemy(EnemyList* enemy_list, int index_enemy) {
    PlaySound(morteSound); // Toca o som de morte quando inimigo morre
    for (int i = index_enemy; i < enemy_list->qty_enemies; i++) {
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
        Enemy enemy = enemy_list->enemies[i];
        if (enemy.delay_speed > 0) {
            enemy_list->enemies[i].speed = 0.5;
            enemy_list->enemies[i].delay_speed -= GetFrameTime();
        } else {
            enemy_list->enemies[i].speed = 2.0;
        }
    }
}

