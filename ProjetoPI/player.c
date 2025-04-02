#include "raylib.h"
#include "game.h"
#include <math.h>

float angle_enemy = 0.0f;

void CreatePlayer(Player* player) {
    player->width = 25;
    player->height = 35;
    player->position.x = 1280/2;
    player->position.y = 600 + (player->height/2);
    player->angle = 0;
}

void DrawPlayer(Player* player) {
    Rectangle player_rect = {player->position.x, player->position.y, player->width, player->height};
    Vector2 player_center = {player->width / 2, player->height / 2};
    DrawText(TextFormat("%f", angle_enemy), 0, 0, 30, WHITE);
    DrawText(TextFormat("%f", player->angle), 40, 40, 30, RED);

    if (abs(angle_enemy - player->angle) > 6) {
        if (angle_enemy < player->angle) {
            player->angle += - 6.0f;
        } else if (angle_enemy > player->angle) {
            player->angle += 6.0f;
        }
    } else {
        player->angle = angle_enemy;
    }

    DrawRectanglePro(player_rect, player_center, player->angle, RED);
}

void TurnToEnemy(Player* player, EnemyList* enemy_list) {
    for (int i = 0; i < enemy_list->qty_enemies; i++) {
        Enemy enemy = enemy_list->enemies[i];
        Vector2 enemy_center = {enemy.position.x + enemy.width / 2, enemy.position.y - enemy.height / 2};
        Vector2 player_center = {player->position.x + player->width / 2, player->position.y - player->height / 2};
        if (enemy.locked) {
            float dx = player_center.x - enemy_center.x;
            float dy = player_center.y - enemy_center.y;
            int angle = atan(dx / dy) * (-180 / PI);
            angle_enemy = angle;
        }
    }
}
