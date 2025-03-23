#include "raylib.h"
#include "enemy.h"
#include "player.h"
#include "menu.h"
#include "typing.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int spawn_interval = 1.0f;
float spawn_timer = 0.0f;
int tamanho_inimigos[3] = {20, 30, 40};
char shortwords[200][15]; 

void InitTexts(void) {
    FILE *file = fopen("shortwords.txt", "r");
    for (int i = 0; i < 100; i++) {
        fscanf(file, "%s\n", shortwords[i]);
    }
    fclose(file);
}

void DrawEnemies(EnemyList enemy_list, Font myfont) {
    for (int i = 0; i < enemy_list.qty_enemies; i++) {
        Enemy enemy = enemy_list.enemies[i];
        int word_size = strlen(enemy.word);
        DrawRectangle(enemy.position.x, enemy.position.y, enemy.width, enemy.height, RED);
        if (enemy.index_typing == -1) {
            DrawText(enemy.word, enemy.position.x, enemy.position.y + 30, 30, WHITE);
        } else {
            for (int i = 0; i < word_size; i++) {
                if (i <= enemy.index_typing) {
                    DrawTextEx(myfont, TextFormat("%c", enemy.word[i]), ((Vector2){ enemy.position.x + (18 * i), enemy.position.y + 30 }), 30, 10, YELLOW);
                } else {
                    DrawTextEx(myfont, TextFormat("%c", enemy.word[i]), ((Vector2){ enemy.position.x + (18 * i), enemy.position.y + 30 }), 30, 10, RED);
                }
            }
        }
    }
}

void SpawnEnemy(EnemyList* enemy_list) {
    if (spawn_timer >= spawn_interval) {
        int i = GetRandomValue(0, 2);
        int tamanho_inimigo = tamanho_inimigos[i];
        spawn_timer = 0;

        Enemy enemy;
        enemy.width = tamanho_inimigo;
        enemy.height = tamanho_inimigo;
        enemy.speed = 2.5;
        enemy.position.x = GetRandomValue(-200, 1380);
        enemy.position.y = -100;
        strcpy(enemy.word, shortwords[GetRandomValue(0, 49)]);
        enemy.locked = 0;
        enemy.index_typing = -1;

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
        float dx = player->position.x - enemy.position.x;
        float dy = player->position.y - enemy.position.y;
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
