#include "raylib.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

int spawn_interval = 2.0f;
float spawn_timer = 0.0f;

void DrawGame(Player player, EnemyList enemy_list) {
    ClearBackground(BLACK);
    DrawPlayer(player);
    DrawEnemies(enemy_list);
}

void CreatePlayer(Player* player) {
    player->width = 25;
    player->height = 25;
    player->position.x = 1280/2 - (player->width/2);
    player->position.y = 600;
}

void DrawPlayer(Player player) {
    DrawRectangle(player.position.x, player.position.y, player.width, player.height, YELLOW);
}

void DrawEnemies(EnemyList enemy_list) {
    for (int i = 0; i < enemy_list.qty_enemies; i++) {
        Enemy enemy = enemy_list.enemies[i];
        DrawRectangle(enemy.position.x, enemy.position.y, enemy.width, enemy.height, RED);
    }
}

void UpdateGameplay(Player* player, EnemyList* enemy_list) {
    if (spawn_timer >= spawn_interval) {
        spawn_timer = 0;

        Enemy enemy;
        enemy.width = 20;
        enemy.height = 20;
        enemy.speed = 10;
        enemy.position.x = 200;
        enemy.position.y = 0;

        enemy_list->enemies[enemy_list->qty_enemies] = enemy;
        enemy_list->qty_enemies++;
    } else {
        spawn_timer += GetFrameTime();
    }

    for (int i = 0; i < enemy_list->qty_enemies; i++) {
        enemy_list->enemies[i].position.y += enemy_list->enemies[i].speed;
        if (enemy_list->enemies[i].position.y >= 720) {
            for (int j = i; j < enemy_list->qty_enemies - 1; j++) {
                enemy_list->enemies[j] = enemy_list->enemies[j + 1];
            }
            enemy_list->qty_enemies--;
            i--;
        }
    }
}