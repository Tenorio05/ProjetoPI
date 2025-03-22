#include "raylib.h"
#include "game.h"

void DrawGame(Player player) {
    ClearBackground(BLACK);
    DrawPlayer(player);
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

void UpdateGameplay(void) {
    //...
}