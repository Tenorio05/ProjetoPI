#include "raylib.h"
#include "game.h"

Button credit;

void SetCredits(void) {
    credit.rec = (Rectangle) {rec.x - 30, rec.y - 240, rec.width, rec.height};
    strcpy(credit.text, "Créditos");  credit.text_color = RAYWHITE;
}

void DrawCredits(void) {
    SetCredits();
    ClearBackground(BLACK);

    DrawText(credit.text, (SCREEN_WIDTH - 77*5)/2, credit.rec.y + (credit.rec.height - 100)/2, 100, credit.text_color);
    DrawText(back.text,   (SCREEN_WIDTH - 33*5)/2, back.rec.y  + (back.rec.height - font_size)/2, font_size, back.text_color);

    if (CheckCollisionPointRec(GetMousePosition(), back.rec)) {
        DrawText(back.text, (SCREEN_WIDTH - 33*5)/2, back.rec.y  + (back.rec.height - font_size)/2, font_size, GRAY);
    }
}

void UpdateCredits(void) {
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), back.rec)) currentScreen = MENU;
}
