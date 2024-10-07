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

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    pause = true;

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

    for (int i = 0; i < numNotes; i++) {
        int lane = rand() % numLanes;
        if (rand() % chanceHold == 0) {
            lanes[lane].notes[lanes[lane].numNotes] = (Note){ (Vector3) { -(noteGap * i + 5.0f),0.0f,lane}, BLUE, 1};
        }
        else {
            lanes[lane].notes[lanes[lane].numNotes] = (Note){ (Vector3) { -(noteGap * i + 5.0f),0.0f,lane}, RED, 0};
            lanes[lane].numNotes++;
            if (rand() % chanceHalf == 0) {
                lane = rand() % numLanes;
                lanes[lane].notes[lanes[lane].numNotes] = (Note){ (Vector3) { -(noteGap * (i + .5f) + 5.0f),0.0f,lane}, RED, 0};
            }
        }
        lanes[lane].numNotes++;
        // laneD[i] = (Note) {0, (int) (noteGap * (i + 5)), RED};
    }
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!

    for (int i = 0; i < numLanes; i++) {
        while (lanes[i].notes[lanes[i].nextNote].position.x > 10.0f) {
            lanes[i].nextNote++;
            printf("skipped a note at lane %d\n", i);
        }
    }

    if (IsKeyPressed(KEY_K))
    {
        if (lanes[0].notes[lanes[0].nextNote].position.x > 7.0f)
        {
            PlaySound(hitSound);
            if (lanes[0].notes[lanes[0].nextNote].holdLength)
            {
                lanes[0].hasHeldNote = true;
                lanes[0].heldNote = lanes[0].notes[lanes[0].nextNote];
            }
            else
            {
                lanes[0].nextNote++;
            }
        }
    }
    if (IsKeyPressed(KEY_J))
    {
        if (lanes[1].notes[lanes[1].nextNote].position.x > 7.0f)
        {
            PlaySound(hitSound);
            if (lanes[1].notes[lanes[1].nextNote].holdLength)
            {
                lanes[1].hasHeldNote = true;
                lanes[1].heldNote = lanes[1].notes[lanes[1].nextNote];
            }
            else
            {
                lanes[1].nextNote++;
            }
        }
    }
    if (IsKeyPressed(KEY_F))
    {
        if (lanes[2].notes[lanes[2].nextNote].position.x > 7.0f)
        {
            PlaySound(hitSound);
            if (lanes[2].notes[lanes[2].nextNote].holdLength)
            {
                lanes[2].hasHeldNote = true;
                lanes[2].heldNote = lanes[2].notes[lanes[2].nextNote];
            }
            else
            {
                lanes[2].nextNote++;
            }
        }
    }
    if (IsKeyPressed(KEY_D))
    {
        if (lanes[3].notes[lanes[3].nextNote].position.x > 7.0f)
        {
            PlaySound(hitSound);
            if (lanes[3].notes[lanes[3].nextNote].holdLength)
            {
                lanes[3].hasHeldNote = true;
                lanes[3].heldNote = lanes[3].notes[lanes[3].nextNote];
            }
            else
            {
                lanes[3].nextNote++;
            }
        }
    }
    if (IsKeyReleased(KEY_K))
    {
        if (lanes[0].hasHeldNote) {
            lanes[0].hasHeldNote = false;
            if (lanes[0].heldNote.position.x > 7.0f + noteGap * lanes[0].heldNote.holdLength) {
                PlaySound(hitSound);
            }
        }
    }
    if (IsKeyReleased(KEY_J))
    {
        if (lanes[1].hasHeldNote) {
            lanes[1].hasHeldNote = false;
            if (lanes[1].heldNote.position.x > 7.0f + noteGap * lanes[1].heldNote.holdLength) {
                PlaySound(hitSound);
            }
        }
    }
    if (IsKeyReleased(KEY_F))
    {
        if (lanes[2].hasHeldNote) {
            lanes[2].hasHeldNote = false;
            if (lanes[2].heldNote.position.x > 7.0f + noteGap * lanes[2].heldNote.holdLength) {
                PlaySound(hitSound);
            }
        }
    }
    if (IsKeyReleased(KEY_D))
    {
        if (lanes[3].hasHeldNote) {
            lanes[3].hasHeldNote = false;
            if (lanes[3].heldNote.position.x > 7.0f + noteGap * lanes[3].heldNote.holdLength) {
                PlaySound(hitSound);
            }
        }
    }
    if (IsKeyPressed(KEY_SPACE))
    {
        if (pause) {
            PlayMusicStream(music);
            pause = false;
        }
        else {
            pause = true;
            for (int i = 0; i < numLanes; i++) {
                printf("Lane %d has nextNote %d with position x of %f\n", i, lanes[i].nextNote, lanes[i].notes[lanes[i].nextNote].position.x);
            }
        }
    }
    else if (IsKeyPressed(KEY_ENTER))
    {
        finishScreen = ENDING;
    }
    // else if (IsKeyPressed(KEY_Z))
    // {
    //     if (notes[nextNote].y > - noteHeight / 2 && notes[nextNote].y < noteHeight / 2) {
    //         nextNote++;
    //         PlaySound(hitsound);
    //     }
    // }

    if (!pause) {
        for (int i = 0; i < numLanes; i++) {
            for (int j = lanes[i].nextNote; j < lanes[i].numNotes; j++) {
                lanes[i].notes[j].position.x += noteSpeed;
            }
            if (lanes[i].hasHeldNote) {
                lanes[i].heldNote.position.x += noteSpeed;
            }
        }
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // TODO: Draw GAMEPLAY screen here!
    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
    // DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
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

    // DrawGrid(40, 1.0f);
    for (int i = 0; i < 4; i++) DrawCube((Vector3){0.0f, 0.0f, 0.0f+i},20,0.05f,0.05f, GRAY);

    EndMode3D();
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
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