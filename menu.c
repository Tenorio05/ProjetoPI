#include "raylib.h"
#include "menu.h"

void DrawMenu(void) {
    ClearBackground(RAYWHITE);
    DrawText("Menu Principal", 400, 200, 40, BLACK);
}

void DrawSettings(void) {
    ClearBackground(BLUE);
    DrawText("Configurações", 400, 200, 40, BLACK);
}

void DrawCredits(void) {
    ClearBackground(YELLOW);
    DrawText("Créditos", 400, 200, 40, BLACK);
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
