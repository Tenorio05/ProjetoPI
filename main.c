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

// Declaração dos sons como variáveis globais para que sejam usadas nos outros módulos
Sound morteSound;
Sound menuJogoSound;
Sound tiroSound;
Sound botaoSound;

void UpdateDrawFrame(void); // Responsável por desenhar na tela o player, inimigos, menu...
void UpdateGame(void); // Atualiza a movimentação dos inimigos, player, etc.

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Projeto FPI");
    InitAudioDevice(); // Inicializa o sistema de áudio do Raylib
    SetTargetFPS(60);
    CreatePlayer(&player);
    InitTexts();
    myfont = LoadFont("COUR.TTF");

    // Carrega os arquivos de som
    // Aqui, tem que ter baixado os arquivos mp3, dai vou deixar um link de um drive com todos os arquivos
    morteSound = LoadSound("sounds/morte.mp3");
    menuJogoSound = LoadSound("sounds/menu_jogo.mp3");
    tiroSound = LoadSound("sounds/tiro.mp3");
    botaoSound = LoadSound("sounds/botao.mp3");

    while (!WindowShouldClose() && quitting == 0)
    {
        UpdateGame();
        UpdateDrawFrame();
        DrawText(TextFormat("%d", j), 500,0,40,WHITE);
        for (int i = 0; i < 20; i++) {
            DrawText(TextFormat("W: %s", enemy_list.enemies[i].word), 0, 25 * i, 20, WHITE);
        }
        j++;

    }
    // Libera os recursos de áudio
    UnloadSound(morteSound);
    UnloadSound(menuJogoSound);
    UnloadSound(tiroSound);
    UnloadSound(botaoSound);
    CloseAudioDevice(); // Fecha o sistema de áudio
    UnloadFont(myfont);
    CloseWindow();

    return 0;
}

void UpdateGame() {
    
    // Toca a música de fundo sem parar
    if (!IsSoundPlaying(menuJogoSound)) {
        PlaySound(menuJogoSound);
    }

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
