#include "raylib.h"
#include "enemy.h"
#include "player.h"
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
    for (int i = 0; i < 50; i++) {
        fscanf(file, "%s\n", shortwords[i]);
    }
    fclose(file);
}

void DrawEnemies(EnemyList enemy_list) {
    for (int i = 0; i < enemy_list.qty_enemies; i++) {
        Enemy enemy = enemy_list.enemies[i];
        DrawRectangle(enemy.position.x, enemy.position.y, enemy.width, enemy.height, RED);
        DrawText(enemy.word, enemy.position.x, enemy.position.y + 30, 30, WHITE);
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
        enemy.speed = 5;
        enemy.position.x = GetRandomValue(0, 1280);
        enemy.position.y = 0;
        strcpy(enemy.word, shortwords[GetRandomValue(0, 49)]);

        enemy_list->enemies[enemy_list->qty_enemies] = enemy;
        enemy_list->qty_enemies++;
    } else {
        spawn_timer += GetFrameTime();
    }
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
            for (int j = i; j < enemy_list->qty_enemies - 1; j++) {
                enemy_list->enemies[j] = enemy_list->enemies[j + 1];
            }
            enemy_list->qty_enemies--;
            i--;
        }
    }
}