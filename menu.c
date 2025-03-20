#include "raylib.h"
#include "menu.h"
#include "button.h"
#include <string.h>

Menu menu;
const int screenWidth = 1280;
const int screenHeight = 720;

const int smallRecWidth = 400;
const int smallRecHeight = 80;

void createMenu() {
    strcpy(menu.title.text, "<NOME DO JOGO>");
    menu.title.textLen = strlen(menu.title.text);
    menu.title.textSize = 100;
    for (int i = 0; i < menu.title.textLen; i++) {(menu.title.text[i] != ' ')?(menu.title.textWidth += 70):(menu.title.textWidth += 30);} menu.title.textWidth--;
    menu.title.rec.x = (screenWidth - menu.title.textWidth)/2;
    menu.title.rec.y = (screenHeight - menu.title.textSize)/2;
    menu.title.textColor = LIGHTGRAY;
    menu.title.recColor = BLACK;
    menu.backgroundColor = BLACK;

    strcpy(menu.playButton.text, "Play");
    menu.playButton.textLen = strlen(menu.playButton.text);
    menu.playButton.textSize = 50;
    for (int i = 0; i < menu.playButton.textLen; i++) {(menu.playButton.text[i] != ' ')?(menu.playButton.textWidth += 7):(menu.playButton.textWidth += 3);} menu.playButton.textWidth--;
    menu.playButton.x = (screenWidth - menu.playButton.textWidth)/2;
    menu.playButton.y = (screenHeight - menu.playButton.textSize)/2;

    strcpy(menu.settButton.text, "Settings");
    menu.settButton.textLen = strlen(menu.settButton.text);
    menu.settButton.textSize = 50;
    for (int i = 0; i < menu.settButton.textLen; i++) {(menu.settButton.text[i] != ' ')?(menu.settButton.textWidth += 7):(menu.settButton.textWidth += 3);} menu.settButton.textWidth--;
    menu.settButton.x = (screenWidth - menu.settButton.textWidth)/2;
    menu.settButton.y = (screenHeight - menu.settButton.textSize)/2;

    strcpy(menu.credButton.text, "Credits");
    menu.credButton.textLen = strlen(menu.credButton.text);
    menu.credButton.textSize = 50;
    for (int i = 0; i < menu.credButton.textLen; i++) {(menu.credButton.text[i] != ' ')?(menu.credButton.textWidth += 7):(menu.credButton.textWidth += 3);} menu.credButton.textWidth--;
    menu.credButton.x = (screenWidth - menu.credButton.textWidth)/2;
    menu.credButton.y = (screenHeight - menu.credButton.textSize)/2;

    strcpy(menu.quitButton.text, "Quit");
    menu.quitButton.textLen = strlen(menu.quitButton.text);
    menu.quitButton.textSize = 50;
    for (int i = 0; i < menu.quitButton.textLen; i++) {(menu.quitButton.text[i] != ' ')?(menu.quitButton.textWidth += 7):(menu.quitButton.textWidth += 3);} menu.quitButton.textWidth--;
    menu.quitButton.x = (screenWidth - menu.quitButton.textWidth)/2;
    menu.quitButton.y = (screenHeight - menu.quitButton.textSize)/2;
    
    // Falta colocar o tamanho e a posicao dos retangulos
}

void updateMenu() {

}

void drawMenu() {

}