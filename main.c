#include "raylib.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    const int screenWidth = 1366;
    const int screenHeight = 768;

    const int bigTextHeight = 100;
    const int smallTextHeight = 50;
    
    const int smallRecWidth = 400;
    const int smallRecHeight = 80;
    
    char nameText[] = "<NOME DO JOGO>";
    int nameTextWidth = 0;
    int nameTextLength = strlen(nameText);
    for (int i = 0; i < nameTextLength; i++) {(nameText[i] != ' ')?(nameTextWidth += 70):(nameTextWidth += 30);} nameTextWidth--;
    int nameTextPosX = (screenWidth - nameTextWidth)/2;
    int nameTextPosY = (screenHeight - bigTextHeight)/2;
    
    char playText[] = "Play";
    int playTextWidth = strlen(playText)*29;
    int playTextPosX = (screenWidth - playTextWidth)/2;
    int playTextPosY = (screenHeight - smallTextHeight)/2 - 40;
    
    char settText[] = "Settings";
    int settTextWidth = strlen(settText)*26;
    int settTextPosX = (screenWidth - settTextWidth)/2;
    int settTextPosY = (screenHeight - smallTextHeight)/2 + 60;
    
    char credText[] = "Credits";
    int credTextWidth = strlen(credText)*26;
    int credTextPosX = (screenWidth - credTextWidth)/2;
    int credTextPosY = (screenHeight - smallTextHeight)/2 + 160;
    
    char quitText[] = "Quit";
    int quitTextWidth = strlen(quitText)*24;
    int quitTextPosX = (screenWidth - quitTextWidth)/2;
    int quitTextPosY = (screenHeight - smallTextHeight)/2 + 260;
    
    Rectangle smallRec = {(screenWidth - smallRecWidth)/2, (screenHeight - smallRecHeight)/2 - 140, smallRecWidth, smallRecHeight};
    Rectangle borderRec = {0, 0, screenWidth, screenHeight};
    Rectangle playRec = {smallRec.x, smallRec.y + 100, smallRec.width, smallRec.height};
    Rectangle settRec = {smallRec.x, smallRec.y + 200, smallRec.width, smallRec.height};
    Rectangle credRec = {smallRec.x, smallRec.y + 300, smallRec.width, smallRec.height};
    Rectangle quitRec = {smallRec.x, smallRec.y + 400, smallRec.width, smallRec.height};

    int clickedPlayRec = 0;
    int clickedSettRec = 0;
    int clickedCredRec = 0;
    int clickedQuitRec = 0;
    
    int isDownPlayRec = 0;
    int isDownSettRec = 0;
    int isDownCredRec = 0;
    int isDownQuitRec = 0;

    int playGame = 0;
    int settGame = 0;
    int credGame = 0;
    int quitGame = 0;

    InitWindow(screenWidth, screenHeight, "Projeto FPI");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(BLACK);
            DrawRectangleLinesEx(borderRec, 5, LIGHTGRAY);

            DrawText(nameText, nameTextPosX, nameTextPosY - 240, bigTextHeight, LIGHTGRAY);
            DrawRectangleRounded(playRec, 0.5, 10, LIGHTGRAY);
            DrawRectangleRounded(settRec, 0.5, 10, LIGHTGRAY);
            DrawRectangleRounded(credRec, 0.5, 10, LIGHTGRAY);
            DrawRectangleRounded(quitRec, 0.5, 10, LIGHTGRAY);
            DrawText(playText, playTextPosX, playTextPosY, smallTextHeight, BLACK);
            DrawText(settText, settTextPosX, settTextPosY, smallTextHeight, BLACK);
            DrawText(credText, credTextPosX, credTextPosY, smallTextHeight, BLACK);
            DrawText(quitText, quitTextPosX, quitTextPosY, smallTextHeight, BLACK);
            
            if (playGame);
            if (settGame);
            if (credGame);
            if (quitGame) break;

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                clickedPlayRec = CheckCollisionPointRec(GetMousePosition(), playRec);
                clickedSettRec = CheckCollisionPointRec(GetMousePosition(), settRec);
                clickedCredRec = CheckCollisionPointRec(GetMousePosition(), credRec);
                clickedQuitRec = CheckCollisionPointRec(GetMousePosition(), quitRec);
            }
            
            if (clickedPlayRec && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                DrawRectangleRounded(playRec, 0.5, 10, BLACK);
                DrawText(playText, playTextPosX, playTextPosY, smallTextHeight, LIGHTGRAY);
                isDownPlayRec = 1;
            }
            if (clickedSettRec && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                DrawRectangleRounded(settRec, 0.5, 10, BLACK);
                DrawText(settText, settTextPosX, settTextPosY, smallTextHeight, LIGHTGRAY);
                isDownSettRec = 1;
            }
            if (clickedCredRec && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                DrawRectangleRounded(credRec, 0.5, 10, BLACK);
                DrawText(credText, credTextPosX, credTextPosY, smallTextHeight, LIGHTGRAY);
                isDownCredRec = 1;
            }
            if (clickedQuitRec && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                DrawRectangleRounded(quitRec, 0.5, 10, BLACK);
                DrawText(quitText, quitTextPosX, quitTextPosY, smallTextHeight, LIGHTGRAY);
                isDownQuitRec = 1;
            }

            if (isDownPlayRec && IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), playRec)) playGame = 1;
            if (isDownSettRec && IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), settRec)) settGame = 1;
            if (isDownCredRec && IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), credRec)) credGame = 1;
            if (isDownQuitRec && IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), quitRec)) quitGame = 1;

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
