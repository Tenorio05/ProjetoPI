#ifndef MENU_H
#define MENU_H

typedef enum GameScreen {
    MENU = 0,
    GAMEPLAY = 1,
    SETTINGS = 2,
    CREDITS = 3,
    QUIT = 4
} GameScreen;

extern GameScreen currentScreen;

void DrawMenu(void);
void DrawSettings(void);
void DrawCredits(void);
void UpdateMenu(void);
void UpdateGameplay(void);
void UpdateSettings(void);
void UpdateCredits(void);

#include "menu.c"
#endif