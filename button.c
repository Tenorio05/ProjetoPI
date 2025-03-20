#include "button.h"

void CreateButton(Button *button, Color color1, Color color2) { // Criar um char state

    if (CheckCollisionPointRec(GetMousePosition(), button->rec)) {
        button->recColor = color2;
        button->textColor = color1;
        //if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) state = s;
    } else {
        button->recColor = color1;
        button->textColor = color2;
    }
}

void DrawButton(Button *button) {
    DrawRectangleRounded(button->rec, 0.5, 10, button->recColor);
}