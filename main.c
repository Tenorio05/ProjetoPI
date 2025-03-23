#include "raylib.h"
#include "menu.h"
#include "game.h"
#include "player.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

GameScreen currentScreen = MENU; // Determina em que cenário o jogador está (MENU, GAMEPLAY, QUIT)
Player player;
EnemyList enemy_list;
Font myfont;

int quitting = 0;

void UpdateDrawFrame(void); // Responsável por desenhar na tela o player, inimigos, menu...
void UpdateGame(void); // Atualiza a movimentação dos inimigos, player, etc.

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Projeto FPI");
    SetTargetFPS(60);
    CreatePlayer(&player);
    InitTexts();
    myfont = LoadFont("Minecraftia-Regular.ttf");

    while (!WindowShouldClose() && quitting == 0)
    {
        UpdateGame();
        UpdateDrawFrame();
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
            UpdateGameplay(&player, &enemy_list); // Lida com a lógica do player e inimigos
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
            DrawGame(player, enemy_list, myfont); // Desenha na tela o player e inimigos
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
