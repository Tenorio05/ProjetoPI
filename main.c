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
Power_up_list power_up_list;

int quitting = 0;
int j = 0;
double time_pass; // variável usada para o tempo de congelamento
int freeze = 0; // ativar ou não o congelamento

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
    Inicializar_power_up_list(&power_up_list); // inicia a lista com os power ups

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
    }
    // Libera os recursos de áudio
    UnloadSound(morteSound);
    UnloadSound(menuJogoSound);
    UnloadSound(tiroSound);
    UnloadSound(botaoSound);
    CloseAudioDevice();

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
                case MENU: UpdateMenu(); break;
        case GAMEPLAY: UpdateGameplay(&player, &enemy_list, &projectile_list, &time_pass, &freeze, &power_up_list); break;
        case GAME_OVER: ResetGame(&player, &enemy_list, &projectile_list); UpdateGameOver(); break;
        case PAUSE: UpdatePause(&player, &enemy_list, &projectile_list); break;
        case SETTINGS: UpdateSettings(); break;
        case CREDITS: UpdateCredits(); break;
        case QUIT: break;
    }
}

void UpdateDrawFrame(void) {
    BeginDrawing();

    switch (currentScreen) {
        case MENU: DrawMenu(); break;
        case GAMEPLAY: DrawGame(&player, &enemy_list, &projectile_list, myfont, power_up_list); break;
        case GAME_OVER: DrawGameOver(); break;
        case PAUSE: DrawPause(); break;
        case SETTINGS: DrawSettings(); break;
        case CREDITS: DrawCredits(); break;
        case QUIT: quitting = 1; break;
    }
    
    EndDrawing();
}
