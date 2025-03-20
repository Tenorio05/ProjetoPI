#ifndef MAIN
#define MAIN

#include "raylib.h"
#include "button.h"

typedef struct Menu {
    Button title, playButton, settButton, credButton, quitButton;
    Color backgroundColor;
} Menu;

#include "main.c"
#endif