#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "player.h"
#include "enemy.h"

void DrawGame(Player player, EnemyList enemy_list, Font myfont);
void UpdateGameplay(Player* player, EnemyList* enemy_list);

#include "game.c"
#endif