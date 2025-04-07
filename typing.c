#include "raylib.h"
#include "game.h"
#include <string.h>


void HandleTyping(Player* player, EnemyList* enemy_list, ProjectileList* projectile_list, int key_pressed) {
    DrawText(TextFormat("%d", player->state), 400, 400, 40, WHITE);
    if (player->state == NOTLOCKED) {
        for (int i = 0; i < enemy_list->qty_enemies; i++) {
            Enemy enemy = enemy_list->enemies[i];
            if (enemy.word[enemy.index_typing] == (char) key_pressed) {
                player->state = LOCKONENEMY;
                enemy_list->enemies[i].locked = 1;
                enemy_list->enemies[i].index_typing++;
                TurnToEnemy(player, enemy_list);
                CreateProjectile(projectile_list, player, enemy_list, i);

                if (enemy_list->enemies[i].index_typing - 1 == strlen(enemy_list->enemies[i].word) - 1) {
                    player->state = NOTLOCKED;
                    enemy_list->enemies[i].locked = 0;
                }
                break;
            }
        }
    } else if (player->state == LOCKONENEMY){
        for (int i = 0; i < enemy_list->qty_enemies; i++) {
            if (enemy_list->enemies[i].locked) {
                if (key_pressed == 259) {
                    player->state = NOTLOCKED;
                    enemy_list->enemies[i].locked = 0;
                } else if (enemy_list->enemies[i].word[enemy_list->enemies[i].index_typing] == key_pressed) {
                    enemy_list->enemies[i].index_typing++;
                    TurnToEnemy(player, enemy_list);
                    CreateProjectile(projectile_list, player, enemy_list, i);
                    
                    if (enemy_list->enemies[i].index_typing - 1 == strlen(enemy_list->enemies[i].word) - 1) {
                        player->state = NOTLOCKED;
                        enemy_list->enemies[i].locked = 0;
                    }
                }
            }
        }
    }
}