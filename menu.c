#include "raylib.h"
#include "game.h"

void DrawMenu(void) {
    ClearBackground(BLACK);
    DrawText("Menu Principal", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 50, RAYWHITE);
}

void DrawSettings(void) {
    ClearBackground(BLACK);
    DrawText("Configurações", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 50, RAYWHITE);
}

void DrawCredits(void) {
    ClearBackground(BLACK);
    DrawText("Créditos", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 50, RAYWHITE);
}

void UpdateMenu(void) {
    if (IsKeyPressed(KEY_ONE)) {
        currentScreen = GAMEPLAY;
    } else if (IsKeyPressed(KEY_TWO)) {
        currentScreen = SETTINGS;
    } else if (IsKeyPressed(KEY_THREE)) {
        currentScreen = CREDITS;
    } else if (IsKeyPressed(KEY_FOUR)) {
        currentScreen = QUIT;
    }
}

void UpdateSettings(void) {
    if (IsKeyPressed(KEY_BACKSPACE)) {
        currentScreen = MENU;
    }
}

void UpdateCredits(void) {
    if (IsKeyPressed(KEY_BACKSPACE)) {
        currentScreen = MENU;
    }
}
