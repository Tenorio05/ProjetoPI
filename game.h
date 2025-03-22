#ifndef GAME_H
#define GAME_H

#include "raylib.h"

typedef struct Player {
    Vector2 position;
    float width;
    float height;
} Player;

typedef struct Enemy {
    Vector2 position;
    float width;
    float height;
    float speed;
} Enemy;

typedef struct EnemyList {
    Enemy enemies[20];
    int qty_enemies;
} EnemyList;

void DrawGame(Player player, EnemyList enemy_list);
void UpdateGameplay(Player* player, EnemyList* enemy_list);
void CreatePlayer(Player* player);
void DrawPlayer(Player player);
void DrawEnemies(EnemyList enemy_list);

#include "game.c"
#endif