#include "raylib.h"
#include "game.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int spawn_interval = 2.0f;
float spawn_timer = 0.0f;
int size_enemies[3] = {20, 30, 40};
char shortwords[200][15]; 

void InitTexts(void) {
    FILE *file = fopen("shortwords.txt", "r");
    for (int i = 0; i < 100; i++) {
        fscanf(file, "%s\n", shortwords[i]);
    }
    fclose(file);
}

void DrawEnemies(EnemyList* enemy_list, Font myfont) {
    for (int i = 0; i < enemy_list->qty_enemies; i++) {
        Enemy enemy = enemy_list->enemies[i];
        int word_size = strlen(enemy.word);
        Vector2 word_size_measure = MeasureTextEx(myfont, enemy.word, 30, 0);
        float center_x_enemy = enemy.position.x + (enemy.width / 2); 

        float position_text_x = center_x_enemy - (word_size_measure.x / 2);
        float position_text_y = enemy.position.y + (enemy.height * 0.9);

        DrawRectangle(enemy.position.x, enemy.position.y, enemy.width, enemy.height, RED);
        if (enemy.index_typing == -1) {
            DrawTextEx(myfont, enemy.word, ((Vector2){ position_text_x, position_text_y }), 30, 0, WHITE);
        } else {
            for (int i = 0; i < word_size; i++) {
                if (i <= enemy.index_typing) {
                    DrawTextEx(myfont, TextFormat("%c", enemy.word[i]), ((Vector2){ position_text_x + (15*i), position_text_y }), 30, 0, YELLOW);
                } else {
                    DrawTextEx(myfont, TextFormat("%c", enemy.word[i]), ((Vector2){ position_text_x + (15*i), position_text_y }), 30, 0, RED);
                }
            }
        }
    }
}

void SpawnEnemy(EnemyList* enemy_list) {
    if (spawn_timer >= spawn_interval) {
        int i = GetRandomValue(0, 2);
        int size_chosen = size_enemies[i];
        spawn_timer = 0;

        Enemy enemy;
        enemy.width = size_chosen;
        enemy.height = size_chosen;
        enemy.speed = 1.5;
        enemy.position.x = GetRandomValue(0, 1280);
        enemy.position.y = -100;
        enemy.locked = 0;
        enemy.index_typing = -1;
        strcpy(enemy.word, shortwords[GetRandomValue(0,99)]);
        int same_initial = 1;
        while (same_initial) {
            same_initial = 0;
            for (int i = 0; i < enemy_list->qty_enemies; i++) {
                if (enemy_list->enemies[i].word[0] == enemy.word[0]) {
                    same_initial = 1;
                    strcpy(enemy.word, shortwords[GetRandomValue(0,99)]);
                    break;
                }
            }
        }

        enemy_list->enemies[enemy_list->qty_enemies] = enemy;
        enemy_list->qty_enemies = enemy_list->qty_enemies + 1;
    } else {
        spawn_timer += GetFrameTime();
    }
}

void RemoveEnemy(EnemyList* enemy_list, int index_enemy) {
    for (int i = index_enemy; i < enemy_list->qty_enemies; i++) {
        enemy_list->enemies[i] = enemy_list->enemies[i + 1];
    }
    enemy_list->qty_enemies--;
} 

void MoveEnemies(EnemyList* enemy_list, Player* player) {
    for (int i = 0; i < enemy_list->qty_enemies; i++) {
        Enemy enemy = enemy_list->enemies[i];
        Vector2 enemy_center = {enemy.position.x + enemy.width / 2, enemy.position.y + enemy.height / 2};
        float dx = player->position.x - enemy_center.x;
        float dy = player->position.y - enemy_center.y;
        float distance = sqrt(dx*dx + dy*dy);

        if (distance > 30) {
            enemy_list->enemies[i].position.x += (dx / distance) * enemy.speed;
            enemy_list->enemies[i].position.y += (dy / distance) * enemy.speed;
        } else {
            if (enemy_list->enemies[i].locked) {
                state = NOTLOCKED;
            }
            RemoveEnemy(enemy_list, i);
            i--;
        }
    }
}
