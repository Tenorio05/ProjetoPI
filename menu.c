#include "raylib.h"
#include "menu.h"
#include "button.h"
#include <string.h>

Menu menu;
const int screenWidth = 1280;
const int screenHeight = 720;

const int recWidth = 400;
const int recHeight = 80;
Rectangle borderRec = {0, 0, screenWidth, screenHeight};

void createMenu() {
    strcpy(menu.title.text, "<NOME DO JOGO>");
    menu.title.textLen = strlen(menu.title.text);
    for (int i = 0; i < menu.title.textLen; i++) {(menu.title.text[i] != ' ')?(menu.title.textWidth += 70):(menu.title.textWidth += 30);} menu.title.textWidth--;
    menu.title.x = (screenWidth - menu.title.textWidth)/2;
    menu.title.y = (screenHeight - 100)/2;
    menu.title.textColor = LIGHTGRAY;
    menu.backgroundColor = BLACK;

    createButton(menu.playButton, "Play", screenWidth, screenHeight, recWidth, recHeight, 50, -40);
    createButton(menu.settButton, "Settings", screenWidth, screenHeight, recWidth, recHeight, 50, 60);
    createButton(menu.playButton, "Credits", screenWidth, screenHeight, recWidth, recHeight, 50, 160);
    createButton(menu.playButton, "Quit", screenWidth, screenHeight, recWidth, recHeight, 50, 260);
    
}

void updateMenu() {
    createMenu();
    updateButton(&menu.playButton, LIGHTGRAY, BLACK);
    updateButton(&menu.settButton, LIGHTGRAY, BLACK);
    updateButton(&menu.credButton, LIGHTGRAY, BLACK);
    updateButton(&menu.quitButton, LIGHTGRAY, BLACK);
}

void drawMenu() {

    ClearBackground(menu.backgroundColor);
    DrawRectangleLinesEx(borderRec, 5, LIGHTGRAY);

    DrawText(menu.title.text, menu.title.x, menu.title.y, 100, menu.title.textColor);
    drawButton(menu.playButton);
    drawButton(menu.settButton);
    drawButton(menu.credButton);
    drawButton(menu.quitButton);
}