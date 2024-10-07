/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Ending Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

//----------------------------------------------------------------------------------
// Ending Screen Functions Definition
//----------------------------------------------------------------------------------

// Ending Screen Initialization logic
void InitEndingScreen(void)
{
    // TODO: Initialize ENDING screen variables here!
    framesCounter = 0;
    finishScreen = 0;
}

// Ending Screen Update logic
void UpdateEndingScreen(void)
{
    // TODO: Update ENDING screen variables here!

    // Press enter or tap to return to TITLE screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1;
        PlaySound(hitSound);
    }
}

// Ending Screen Draw logic
void DrawEndingScreen(void)
{
    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
    
    if (victory)
    {
        DrawText("VICTORY!", screenWidth/2 - MeasureText("VICTORY!", 40)/2, screenHeight/2 - 60, 40, GREEN);
    }
    else
    {
        DrawText("GAME OVER", screenWidth/2 - MeasureText("GAME OVER", 40)/2, screenHeight/2 - 60, 40, RED);
    }
    
    //display final score and highest combo for both victory and game over
    DrawText(TextFormat("Final Score: %d", score), screenWidth/2 - MeasureText("Final Score: 0000000", 20)/2, screenHeight/2, 20, WHITE);
    DrawText(TextFormat("Highest Combo: %d", highestCombo), screenWidth/2 - MeasureText("Highest Combo: 0000", 20)/2, screenHeight/2 + 30, 20, WHITE);
    
    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", screenWidth/2 - MeasureText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 20)/2, screenHeight - 50, 20, DARKBLUE);
}
// Ending Screen Unload logic
void UnloadEndingScreen(void)
{
    // TODO: Unload ENDING screen variables here!
}

// Ending Screen should finish?
int FinishEndingScreen(void)
{
    return finishScreen;
}