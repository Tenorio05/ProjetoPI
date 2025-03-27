#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
    Vector2 position;
    float width;
    float height;
    float angle;
} Player;

#include "enemy.h"

void CreatePlayer(Player* player);
void DrawPlayer(Player* player);

#include "player.c"
#endif

