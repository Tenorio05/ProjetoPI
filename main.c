#include "raylib.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    const int screenWidth = 1366;
    const int screenHeight = 768;

    const int recWidth = 1366;
    const int recHeight = 768;
    
    const int textHeight = 100;
    const int smallTextHeight = 50;
    
    const int smallRecWidth = 400;
    const int smallRecHeight = 80;
    
    char text[] = "<NOME DO JOGO>";
    int textWidth = 0;
    int textLength = strlen(text);
    for (int i = 0; i < textLength; i++) {(text[i] != ' ')?(textWidth += 70):(textWidth += 30);} textWidth--;
    int textPosX = (screenWidth - textWidth)/2;
    int textPosY = (screenHeight - textHeight)/2;
    
    char smallText1[] = "Play";
    int smallText1Width = strlen(smallText1)*29;
    int smallText1PosX = (screenWidth - smallText1Width)/2;
    int smallText1PosY = (screenHeight - smallTextHeight)/2;
    
    char smallText2[] = "Settings";
    int smallText2Width = strlen(smallText2)*26;
    int smallText2PosX = (screenWidth - smallText2Width)/2;
    int smallText2PosY = (screenHeight - smallTextHeight)/2;
    
    char smallText3[] = "Credits";
    int smallText3Width = strlen(smallText3)*26;
    int smallText3PosX = (screenWidth - smallText3Width)/2;
    int smallText3PosY = (screenHeight - smallTextHeight)/2;
    
    char smallText4[] = "Quit";
    int smallText4Width = strlen(smallText4)*24;
    int smallText4PosX = (screenWidth - smallText4Width)/2;
    int smallText4PosY = (screenHeight - smallTextHeight)/2;
    
    Rectangle rec = {(screenWidth - recWidth)/2, (screenHeight - recHeight)/2, recWidth, recHeight};
    Rectangle smallRec0 = {(screenWidth - smallRecWidth)/2, (screenHeight - smallRecHeight)/2 - 40, smallRecWidth, smallRecHeight};
    Rectangle smallRec1 = {smallRec0.x, smallRec0.y + 100, smallRec0.width, smallRec0.height};
    Rectangle smallRec2 = {smallRec0.x, smallRec0.y + 200, smallRec0.width, smallRec0.height};
    Rectangle smallRec3 = {smallRec0.x, smallRec0.y + 300, smallRec0.width, smallRec0.height};

    int clickedSmallRec0 = 0;
    int clickedSmallRec1 = 0;
    int clickedSmallRec2 = 0;
    int clickedSmallRec3 = 0;

    InitWindow(screenWidth, screenHeight, "Projeto FPI");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(BLACK);
            DrawRectangleLinesEx(rec, 5, LIGHTGRAY);

            DrawText(text, textPosX, textPosY - 240, textHeight, LIGHTGRAY);
            DrawRectangleRounded(smallRec0, 0.5, 10, LIGHTGRAY);
            DrawRectangleRounded(smallRec1, 0.5, 10, LIGHTGRAY);
            DrawRectangleRounded(smallRec2, 0.5, 10, LIGHTGRAY);
            DrawRectangleRounded(smallRec3, 0.5, 10, LIGHTGRAY);
            DrawText(smallText1, smallText1PosX, smallText1PosY - 40, smallTextHeight, BLACK);
            DrawText(smallText2, smallText2PosX, smallText2PosY + 60, smallTextHeight, BLACK);
            DrawText(smallText3, smallText3PosX, smallText3PosY + 160, smallTextHeight, BLACK);
            DrawText(smallText4, smallText4PosX, smallText4PosY + 260, smallTextHeight, BLACK);
            
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                clickedSmallRec0 = CheckCollisionPointRec(GetMousePosition(), smallRec0);
                clickedSmallRec1 = CheckCollisionPointRec(GetMousePosition(), smallRec1);
                clickedSmallRec2 = CheckCollisionPointRec(GetMousePosition(), smallRec2);
                clickedSmallRec3 = CheckCollisionPointRec(GetMousePosition(), smallRec3);
            }
            
            if (clickedSmallRec0 && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                DrawRectangleRounded(smallRec0, 0.5, 10, BLACK);
                DrawText(smallText1, smallText1PosX, smallText1PosY - 40, smallTextHeight, LIGHTGRAY);
            }
            if (clickedSmallRec1 && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                DrawRectangleRounded(smallRec1, 0.5, 10, BLACK);
                DrawText(smallText2, smallText2PosX, smallText2PosY + 60, smallTextHeight, LIGHTGRAY);
            }
            if (clickedSmallRec2 && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                DrawRectangleRounded(smallRec2, 0.5, 10, BLACK);
                DrawText(smallText3, smallText3PosX, smallText3PosY + 160, smallTextHeight, LIGHTGRAY);
            }
            if (clickedSmallRec3 && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                DrawRectangleRounded(smallRec3, 0.5, 10, BLACK);
                DrawText(smallText4, smallText4PosX, smallText4PosY + 260, smallTextHeight, LIGHTGRAY);
            }


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
