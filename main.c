#include "raylib.h"
#include "menu.h"
#include "game.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

GameScreen currentScreen = MENU;
Player player; 
int quitting = 0;

void UpdateDrawFrame(void);
void UpdateGame(void);


int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Projeto FPI");
    SetTargetFPS(60);
    CreatePlayer(&player);

    while (!WindowShouldClose() && quitting == 0)
    {
        UpdateGame();
        UpdateDrawFrame();
    }
    
    CloseWindow();

    return 0;
}

void UpdateGame() {
    switch (currentScreen) {
        case MENU: 
            UpdateMenu(); 
            break;
        case GAMEPLAY: 
            UpdateGameplay();
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
            DrawMenu(); 
            break;
        case GAMEPLAY: 
            DrawGame(player); 
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



