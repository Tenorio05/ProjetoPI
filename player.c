#include "raylib.h"
#include "game.h"
#include <math.h>

float angle_enemy = 0.0f;

void CreatePlayer(Player* player) {
    player->rect = (Rectangle) {1280/2, 600 + (35/2), 25, 35};
    player->angle = 0;
    player->color = YELLOW;
}

void DrawPlayer(Player* player) {
    Vector2 player_center = {player->rect.width / 2, player->rect.height / 2};

    if (abs(angle_enemy - player->angle) > 6) {
        if (angle_enemy < player->angle) {
            player->angle += - 6.0f;
        } else if (angle_enemy > player->angle) {
            player->angle += 6.0f;
        }
    } else {
        player->angle = angle_enemy;
    }
    
    DrawRectanglePro(player->rect, player_center, player->angle, player->color);
    DrawCircle(player->rect.x, player->rect.y, 3, GREEN);
}

void TurnToEnemy(Player* player, EnemyList* enemy_list) {
    for (int i = 0; i < enemy_list->qty_enemies; i++) {
        Enemy enemy = enemy_list->enemies[i];
        Vector2 enemy_center = {enemy.rect.x + enemy.rect.width / 2, enemy.rect.y + enemy.rect.height / 2};
        Vector2 player_center = {player->rect.x, player->rect.y};
        if (enemy.locked) {
            float dx = player_center.x - enemy_center.x;
            float dy = player_center.y - enemy_center.y;
            int angle = atan(dx / dy) * (-180 / PI);
            angle_enemy = angle;
        }
    }
}
