#include "raylib.h"
#include "enemy.h"
#include <string.h>
#include "player.h"

StateTyping state = NOTLOCKED;

void HandleTyping(Player* player, EnemyList* enemy_list, int key_pressed) {
    if (state == NOTLOCKED) {
        for (int i = 0; i < enemy_list->qty_enemies; i++) {
            Enemy enemy = enemy_list->enemies[i];
            if (enemy.word[0] == (char) key_pressed) {
                state = LOCKONENEMY;
                enemy_list->enemies[i].locked = 1;
                enemy_list->enemies[i].index_typing = 0;
                break;
            }
        }
    } else {
        for (int i = 0; i < enemy_list->qty_enemies; i++) {
            if (enemy_list->enemies[i].locked) {
                if (key_pressed == 259) {
                    state = NOTLOCKED;
                    enemy_list->enemies[i].index_typing = -1;
                    enemy_list->enemies[i].locked = 0;
                } else if (enemy_list->enemies[i].word[enemy_list->enemies[i].index_typing + 1] == key_pressed) {
                    enemy_list->enemies[i].index_typing++;
                    if (enemy_list->enemies[i].index_typing == strlen(enemy_list->enemies[i].word) - 1) {
                        state = NOTLOCKED;
                        RemoveEnemy(enemy_list, i);
                    }
                }
            }
        }
    }
}