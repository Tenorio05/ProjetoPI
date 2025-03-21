#ifndef MENU
#define MENU

#include "raylib.h"
#include "button.h"

typedef struct Menu {
    Button title, playButton, settButton, credButton, quitButton;
    Color backgroundColor;
} Menu;

#include "menu.c"
#endif