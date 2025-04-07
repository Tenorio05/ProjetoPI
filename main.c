#include "raylib.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GameScreen currentScreen = MENU; // Determina em que cenário o jogador está (MENU, GAMEPLAY, QUIT)
Player player;
EnemyList enemy_list;
Font myfont;
ProjectileList projectile_list = {.qty_projectiles = 0};

int quitting = 0;
int j = 0;

void UpdateDrawFrame(void); // Responsável por desenhar na tela o player, inimigos, menu...
void UpdateGame(void); // Atualiza a movimentação dos inimigos, player, etc.

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Projeto PI");
    SetTargetFPS(60);
    CreatePlayer(&player);
    InitTexts();
    InitBackground();
    
    myfont = LoadFont("COUR.TTF");

    while (!WindowShouldClose() && quitting == 0)
    {
        UpdateGame();
        UpdateDrawFrame();
        DrawText(TextFormat("%d", j), 0, 0, 30, WHITE);
        j++;
    }
    
    UnloadFont(myfont);
    CloseWindow();

    return 0;
}

void UpdateGame() {
    switch (currentScreen) {
        case MENU:            
            UpdateMenu(); // Lida com a lógica do MENU (Funcionamento dos botões)
            break;
        case GAMEPLAY: 
            UpdateGameplay(&player, &enemy_list, &projectile_list); // Lida com a lógica do player e inimigos
            break;
        case SETTINGS: 
            UpdateSettings(); 
            break;
        case CREDITS: 
            UpdateCredits(); 
            break;
        case QUIT: 
            break;
    }
}

void UpdateDrawFrame(void) {
    BeginDrawing();

    switch (currentScreen) {
        case MENU: 
            DrawMenu(); // Printa na tela o menu 
            break;
        case GAMEPLAY: 
            DrawGame(&player, &enemy_list, &projectile_list, myfont); // Desenha na tela o player e inimigos
            break;
        case SETTINGS: 
            DrawSettings(); 
            break;
        case CREDITS: 
            DrawCredits(); 
            break;
        case QUIT: 
            quitting = 1; 
            break;
    }
    
    EndDrawing();
}
