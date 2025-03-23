#include "raylib.h"
#include "game.h"
#include "player.h"
#include "enemy.h"


void DrawGame(Player player, EnemyList enemy_list) {
    ClearBackground(BLACK);
    DrawPlayer(player);
    DrawEnemies(enemy_list);
}

void UpdateGameplay(Player* player, EnemyList* enemy_list) {
    SpawnEnemy(enemy_list);
    MoveEnemies(enemy_list, player);
}