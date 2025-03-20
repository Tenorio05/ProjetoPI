#ifndef BUTTON
#define BUTTON
#include "raylib.h"

typedef struct Button {
    Rectangle rec;
    Color recColor;
    Color textColor;
    char text[100];
    int x, y;
    int textSize;
    int textLen;
    int textWidth;
} Button;

#include "button.c"
#endif