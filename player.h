#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
    Vector2 position;
    float width;
    float height;
} Player;

void CreatePlayer(Player* player);
void DrawPlayer(Player player);

#include "player.c"
#endif

