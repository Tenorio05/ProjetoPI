#include "raylib.h"
#include "game.h"


void DrawGame(Player* player, EnemyList* enemy_list, Font myfont) {
    ClearBackground(BLACK);
    DrawPlayer(player);
    DrawEnemies(enemy_list, myfont);
}

void UpdateGameplay(Player* player, EnemyList* enemy_list) {
    int key_pressed = GetCharPressed();
    if (key_pressed >= 32 && key_pressed <= 125) {
        HandleTyping(player, enemy_list, key_pressed);
    } else if (IsKeyPressed(KEY_BACKSPACE)) {
        HandleTyping(player, enemy_list, 259);
    }
    
    SpawnEnemy(enemy_list);
    MoveEnemies(enemy_list, player);
}