#include "raylib.h"
#include "game.h"
#include <math.h>

float angle_enemy = 0;

void CreatePlayer(Player* player) {
    player->width = 25;
    player->height = 35;
    player->position.x = 1280/2 - (player->width/2);
    player->position.y = 600;
    player->angle = 0;
}

void DrawPlayer(Player* player) {
    Rectangle player_rect = {player->position.x, player->position.y, player->width, player->height};
    Vector2 player_center = {player->width / 2, player->height / 2};

    if (angle_enemy < 0 && angle_enemy < player->angle) {
        player->angle += - 6.0f;
    } else if (angle_enemy > 0 && angle_enemy > player->angle) {
        player->angle += 6.0f;
    }

    DrawRectanglePro(player_rect, player_center, player->angle, YELLOW);
}

void TurnToEnemy(Player* player, EnemyList* enemy_list) {
    for (int i = 0; i < enemy_list->qty_enemies; i++) {
        Enemy enemy = enemy_list->enemies[i];
        if (enemy.locked) {
            float dx = player->position.x - enemy.position.x;
            float dy = player->position.y - enemy.position.y;
            float angle = atan(dx / dy) * (-180 / PI);
            angle_enemy = angle;
        }
    }
}