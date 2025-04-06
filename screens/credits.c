#include "raylib.h"
#include "game.h"

void SetCredits(void) {
    
}

void DrawCredits(void) {
    ClearBackground(BLACK);
    DrawText("Créditos", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 50, RAYWHITE);
    //DrawText("................................................................................................................................", 0, back.rec.y - 10, 50, RED); // DEBUG
    //DrawText("_____________________________________________________________________________________________", 0, back.rec.y - 15, 50, RED); // DEBUG
}

void UpdateCredits(void) {
    if (IsKeyPressed(KEY_BACKSPACE)) {
        currentScreen = MENU;
    }
}
