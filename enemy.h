#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

typedef struct Enemy {
    Vector2 position;
    float width;
    float height;
    float speed;
    char word[50];
    int index_typing;
    int locked;
} Enemy;

typedef struct EnemyList {
    Enemy enemies[20];
    int qty_enemies;
} EnemyList;

void InitTexts(void);
void DrawEnemies(EnemyList* enemy_list, Font myfont);
void SpawnEnemy(EnemyList* enemy_list);
void MoveEnemies(EnemyList* enemy_list, Player* player);
void RemoveEnemy(EnemyList* enemy_list, int index_enemy);
void CreateShortWordsList(char shortwords[200][15]);

#include "enemy.c"
#endif

