#include "raylib.h"
#include "game.h"
#include "player.h"
#include "enemy.h"
#include "typing.h"


void DrawGame(Player player, EnemyList enemy_list, Font myfont) {
    ClearBackground(BLACK);
    DrawPlayer(player);
    DrawEnemies(enemy_list, myfont);
}

void UpdateGameplay(Player* player, EnemyList* enemy_list) {
    int key_pressed = GetCharPressed();
    if (key_pressed >= 32 && key_pressed <= 125) {
        HandleTyping(enemy_list, key_pressed);
    }
    
    SpawnEnemy(enemy_list);
    MoveEnemies(enemy_list, player);
}