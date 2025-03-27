#include "raylib.h"
#include "game.h"

void CreatePlayer(Player* player) {
    player->width = 25;
    player->height = 35;
    player->position.x = 1280/2 - (player->width/2);
    player->position.y = 600;
    player->angle = 0;
}

void DrawPlayer(Player* player) {
    DrawRectangle(player->position.x, player->position.y, player->width, player->height, YELLOW);
}
