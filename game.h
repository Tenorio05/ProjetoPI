#ifndef GAME_H
#define GAME_H

typedef struct Player {
    Vector2 position;
    float width;
    float height;
} Player;

void DrawGame(Player player);
void UpdateGameplay(void);
void CreatePlayer(Player* player);
void DrawPlayer(Player player);

#include "game.c"
#endif