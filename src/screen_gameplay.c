/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
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
#include <stdlib.h>
#include <stdio.h>
#include "raymath.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------

typedef struct Note {
    Vector3 position;
    Color color;
    int holdLength;
} Note;

typedef struct Lane {
    Note* notes;
    int nextNote;
    int numNotes;
    Note heldNote;
    bool hasHeldNote;
} Lane;

static int framesCounter = 0;
static int finishScreen = 0;

static const int noteWidth = 50;
static const int noteHeight = 20;

static Vector3 noteSize = { .9f, .9f, .9f };

static Lane* lanes;
static const int numNotes = 800;
static const double noteSpeed = .2f;
static const int chanceHold = 10;
static const int chanceHalf = 5;
static const int bpm = 138;
static const int numLanes = 4;

double noteGap;
static bool pause = true;

// New variables
int combo = 0;
int highestCombo = 0;
int score = 0;
float health = 100.0f;
static bool gameOver = false;
bool victory = false;
static bool testingMode = false;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
    pause = true;

    combo = 0;
    score = 0;
    health = 100.0f;
    gameOver = false;
    victory = false;
    testingMode = false;

    // basic calculation on note distance per beat
    noteGap = noteSpeed * fps * 60 / bpm;

    // init lanes
    lanes = malloc(sizeof(Lane) * numLanes);

    for (int i = 0; i < numLanes; i++) {
        lanes[i].notes = malloc(sizeof(Note) * numNotes);
        lanes[i].nextNote = 0;
        lanes[i].numNotes = 0;
        lanes[i].hasHeldNote = false;
    }

    int lastHoldLane = -1;  //track the last lane that had a hold note
    float holdDelay = 0;    //delay counter after a hold note

    for (float i = 0; i < numNotes; i += 1.0f) {
        if (holdDelay > 0) {
            holdDelay -= 1.0f;
            continue;
        }

        int lane;
        do {
            lane = rand() % numLanes;
        } while (lane == lastHoldLane);  //ensure we don't select the same lane as the last hold note

        if (rand() % chanceHold == 0) {
            lanes[lane].notes[lanes[lane].numNotes] = (Note){ (Vector3) { -(noteGap * i + 5.0f), 0.0f, lane}, BLUE, 1};
            lanes[lane].numNotes++;
            lastHoldLane = lane; 
            holdDelay = noteGap * 0.25f;  //quarter beat delay before any other note, this is for future modifications if we want to adjust difficulty
        }
        else {
            lanes[lane].notes[lanes[lane].numNotes] = (Note){ (Vector3) { -(noteGap * i + 5.0f), 0.0f, lane}, RED, 0};
            lanes[lane].numNotes++;
            lastHoldLane = -1;  //clear the last hold lane
            if (rand() % chanceHalf == 0) {
                i += 0.5f;  //advance by half a beat for the next note
                do {
                    lane = rand() % numLanes;
                } while (lane == lastHoldLane);  //ensure we don't select the same lane as the last hold note
                lanes[lane].notes[lanes[lane].numNotes] = (Note){ (Vector3) { -(noteGap * i + 5.0f), 0.0f, lane}, RED, 0};
                lanes[lane].numNotes++;
            }
        }
    }
}

void HandleKeyPress(int lane)
{
    if (lanes[lane].nextNote < lanes[lane].numNotes &&
        lanes[lane].notes[lanes[lane].nextNote].position.x > 7.0f &&
        lanes[lane].notes[lanes[lane].nextNote].position.x < 9.5f) {
        PlaySound(hitSound);
        combo++;
        if (combo > highestCombo) highestCombo = combo;  //update highest combo
        score += 100 * combo;
        if (!testingMode) {
            health = Clamp(health + 5.0f, 0.0f, 100.0f);
        }
        if (lanes[lane].notes[lanes[lane].nextNote].holdLength) {
            lanes[lane].hasHeldNote = true;
            lanes[lane].heldNote = lanes[lane].notes[lanes[lane].nextNote];
        }
        lanes[lane].nextNote++; 
    }
}

void HandleKeyRelease(int lane)
{
    if (lanes[lane].hasHeldNote) {
        lanes[lane].hasHeldNote = false;
        if (lanes[lane].heldNote.position.x > 7.0f + noteGap * lanes[lane].heldNote.holdLength) {
            PlaySound(hitSound);
            combo++;
            if (combo > highestCombo) highestCombo = combo;  //update highest combo
            score += 100 * combo;
            if (!testingMode) {
                health = Clamp(health + 5.0f, 0.0f, 100.0f);
            }
            
            if (lanes[lane].nextNote < lanes[lane].numNotes &&
                lanes[lane].notes[lanes[lane].nextNote].position.x > 7.0f &&
                lanes[lane].notes[lanes[lane].nextNote].position.x < 9.5f) {
                lanes[lane].nextNote++;
            }
        } else {
            combo = 0;
        }
    }
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    if (gameOver || victory) {
        if (IsKeyPressed(KEY_ENTER)) {
            finishScreen = 1;  //this will trigger the transition to the ENDING screen
        }
        return;
    }

    if (IsKeyPressed(KEY_SPACE)) {
        if (pause) {
            PlayMusicStream(music);
            pause = false;
        } else {
            pause = true;
            PauseMusicStream(music);
        }
    }

    // adding a testing mode so you can step away from the rhythm game and it'll keep playing til the end of the song (victory)
    if (IsKeyPressed(KEY_T)) {
        testingMode = !testingMode;
        if (testingMode) {
            health = 100.0f;  //reset health to full when entering testing mode
        }
    }

    if (!pause) {
        UpdateMusicStream(music);

        if (health <= 0 && !testingMode) {
            gameOver = true;
            StopMusicStream(music);
        }

        //check for victory condition
        if (!IsMusicStreamPlaying(music) || GetMusicTimePlayed(music) >= GetMusicTimeLength(music) - 0.1f) {
            victory = true;
            StopMusicStream(music);
        }

        // Update note positions
        for (int i = 0; i < numLanes; i++) {
            for (int j = lanes[i].nextNote; j < lanes[i].numNotes; j++) {
                lanes[i].notes[j].position.x += noteSpeed;
            }
            if (lanes[i].hasHeldNote) {
                lanes[i].heldNote.position.x += noteSpeed;
            }
        }

        // Handle input and scoring
        if (IsKeyPressed(KEY_D)) HandleKeyPress(3);
        if (IsKeyPressed(KEY_F)) HandleKeyPress(2);
        if (IsKeyPressed(KEY_J)) HandleKeyPress(1);
        if (IsKeyPressed(KEY_K)) HandleKeyPress(0);

        if (IsKeyReleased(KEY_D)) HandleKeyRelease(3);
        if (IsKeyReleased(KEY_F)) HandleKeyRelease(2);
        if (IsKeyReleased(KEY_J)) HandleKeyRelease(1);
        if (IsKeyReleased(KEY_K)) HandleKeyRelease(0);

        // Check for missed notes
        for (int i = 0; i < numLanes; i++) {
            while (lanes[i].nextNote < lanes[i].numNotes && lanes[i].notes[lanes[i].nextNote].position.x > 10.0f) {
                lanes[i].nextNote++;
                combo = 0;
                if (!testingMode) {
                    health = Clamp(health - 5.0f, 0.0f, 100.0f);
                }
            }
        }
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);

    if (pause) {
        DrawText("PRESS SPACE TO START", 240, 220, 20, MAROON);
    }

    BeginMode3D(camera);
    DrawCubeWires((Vector3){9.0f, 0.0f, 0.0f},0.5f, 1.0f, 1.0f, RED);
    DrawCubeWires((Vector3) { 9.0f, 0.0f, 1.0f }, .5f, 1.0f, 1.0f, RED);
    DrawCubeWires((Vector3) { 9.0f, 0.0f, 2.0f }, .5f, 1.0f, 1.0f, RED);
    DrawCubeWires((Vector3){9.0f, 0.0f, 3.0f},.5f, 1.0f, 1.0f, RED);

    for (int i = 0; i < numLanes; i++) {
        for (int j = lanes[i].nextNote; j < lanes[i].numNotes; j++) {
            if (lanes[i].notes[j].holdLength && !lanes[i].hasHeldNote) {
                int newX = lanes[i].notes[j].position.x - noteGap * lanes[i].notes[j].holdLength / 2;
                Vector3 newPos = {newX, lanes[i].notes[j].position.y, lanes[i].notes[j].position.z};
                DrawCubeV(newPos, (Vector3){noteGap * lanes[i].notes[j].holdLength + noteSize.x, noteSize.y, noteSize.z}, lanes[i].notes[j].color);
            }
            else {
                DrawCubeV(lanes[i].notes[j].position, noteSize, lanes[i].notes[j].color);
            }
        }
        if (lanes[i].hasHeldNote) {
            int newX = lanes[i].heldNote.position.x - noteGap * lanes[i].heldNote.holdLength / 2;
            Vector3 newPos = {newX, lanes[i].heldNote.position.y, lanes[i].heldNote.position.z};
            DrawCubeV(newPos, (Vector3){noteGap * lanes[i].heldNote.holdLength + noteSize.x, noteSize.y, noteSize.z}, lanes[i].heldNote.color);
        }
    }

    for (int i = 0; i < 4; i++) DrawCube((Vector3){0.0f, 0.0f, 0.0f+i},20,0.05f,0.05f, GRAY);

    EndMode3D();

    //draw UI
    DrawText(TextFormat("Combo: %d", combo), 10, 10, 20, WHITE);
    DrawText(TextFormat("Score: %d", score), 10, 40, 20, WHITE);
    
    //draw health bar
    DrawRectangle(10, 70, 200, 20, RED);
    DrawRectangle(10, 70, (int)(health * 2), 20, GREEN);
    DrawRectangleLines(10, 70, 200, 20, WHITE);

    //show testing mode indicator
    if (testingMode) {
        DrawText("TESTING MODE", screenWidth - MeasureText("TESTING MODE", 20) - 10, 10, 20, YELLOW);
    }

    if (gameOver) {
        DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.7f));
        DrawText("GAME OVER", screenWidth/2 - MeasureText("GAME OVER", 40)/2, screenHeight/2 - 40, 40, RED);
        DrawText("Press ENTER to return to title", screenWidth/2 - MeasureText("Press ENTER to return to title", 20)/2, screenHeight/2 + 20, 20, WHITE);
    } else if (victory) {
        DrawRectangle(0, 0, screenWidth, screenHeight, Fade(WHITE, 0.7f));
        DrawText("VICTORY!", screenWidth/2 - MeasureText("VICTORY!", 40)/2, screenHeight/2 - 40, 40, GREEN);
        //DrawText(TextFormat("Final Score: %d", score), screenWidth/2 - MeasureText("Final Score: 0000000", 20)/2, screenHeight/2, 20, BLACK);
        //DrawText(TextFormat("Highest Combo: %d", highestCombo), screenWidth/2 - MeasureText("Highest Combo: 0000", 20)/2, screenHeight/2 + 30, 20, BLACK);
        DrawText("Press ENTER to show gameplay results", screenWidth/2 - MeasureText("Press ENTER to show gameplay results", 20)/2, screenHeight/2 + 60, 20, BLACK);
    }
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    for (int i = 0; i < numLanes; i++) {
        free(lanes[i].notes);
    }
    free(lanes);
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}