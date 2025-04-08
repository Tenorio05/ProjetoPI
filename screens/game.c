#include "raylib.h"
#include "game.h"


void DrawGame(Player* player, EnemyList* enemy_list, ProjectileList* projectile_list, Font myfont,Power_up_list power_up_list) {
    Texture2D background = LoadTexture("sprites/background.png");
    ClearBackground(BLACK);    
    DrawTexturePro(background,
    (Rectangle){ 0, 0, background.width, background.height },
    (Rectangle){ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT },
    (Vector2){ 0, 0 },
    0.0f,
    WHITE);
    DrawProjectiles(projectile_list);
    DrawPlayer(player);
    Texture2D enemyTextures[3];
    enemyTextures[0] = LoadTexture("sprites/inimigo1.png");
    enemyTextures[1] = LoadTexture("sprites/inimigo2.png");
    enemyTextures[2] = LoadTexture("sprites/inimigo3.png");
    DrawEnemies(enemy_list, myfont, enemyTextures);
    print_power_up_bar(power_up_list); // printa a barra de power ups
        
}

void UpdateGameplay(Player* player, EnemyList* enemy_list, ProjectileList* projectile_list, double* time_pass, int *freeze, Power_up_list* power_up_list) {
    int key_pressed = GetCharPressed();
    if (key_pressed >= 32 && key_pressed <= 125) {
        HandleTyping(player, enemy_list, projectile_list, key_pressed);
    } else if (IsKeyPressed(KEY_BACKSPACE)) {
        HandleTyping(player, enemy_list, projectile_list, 259);
    }
    
    UpdateEnemyWaves(enemy_list);
    MoveEnemies(enemy_list, player, freeze, time_pass, power_up_list);
    UpdateProjectile(projectile_list, enemy_list);
    DelayEnemies(enemy_list);
    activate_power_up(power_up_list, enemy_list, time_pass, freeze);
}
