#include "button->h"

void createButton(Button *button, char *text, int screenWidth, int screenHeight, int smallRecWidth, int smallRecHeight, int fontSize, int space) {
    strcpy(button->text, text);
    button->textLen = strlen(button->text);
    button->textWidth = 0;
    for (int i = 0; i < button->textLen; i++) {(button->text[i] != ' ')?(button->textWidth += 7):(button->textWidth += 3);} button->textWidth--;
    button->x = (screenWidth - button->textWidth)/2;
    button->y = (screenHeight - fontSize)/2;
    button->rec.width = smallRecWidth;
    button->rec.height = smallRecHeight;
    button->rec.x = (screenWidth - smallRecWidth)/2;
    button->rec.y = (screenHeight - smallRecHeight)/2 + space;
}

void updateButton(Button *button, Color color1, Color color2) { // Criar um char state

    if (CheckCollisionPointRec(GetMousePosition(), button->rec)) {
        button->recColor = color2;
        button->textColor = color1;
        //if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) state = s;
    } else {
        button->recColor = color1;
        button->textColor = color2;
    }
}

void drawButton(Button button) {
    DrawText(button->text, button->x, button->y, 50, button->textColor);
    DrawRectangleRounded(button->rec, 0.5, 10, button->recColor);
}