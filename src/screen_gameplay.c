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
} Note;

typedef struct Lane {
    Note* notes;
    int nextNote;
    int numNotes;
} Lane;

static int framesCounter = 0;
static int finishScreen = 0;
static Camera camera = { 0 };

static const int noteWidth = 50;
static const int noteHeight = 20;

static Vector3 noteSize = { .9f, .9f, .9f };

static Lane* lanes;
static const int numNotes = 800;
static const int noteSpeed = 40;
static const int bpm = 138;
static const int numLanes = 4;
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

    Camera camera = { 0 };
    camera.position = (Vector3){ 11.0f, 2.0f, 1.5f };   // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 1.5f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 100.0f;                               // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    // map specific information

    // basic calculation on note distance per beat
    double noteGap = noteSpeed * fps / bpm;

    // init lanes
    Lane* lanes = malloc(sizeof(Lane) * numLanes);

    for (int i = 0; i < numLanes; i++) {
        lanes[i].notes = malloc(sizeof(Note) * numNotes);
        lanes[i].nextNote = 0;
        lanes[i].numNotes = 0;
    }

    for (int i = 0; i < numNotes; i++) {
        int lane = rand() % numLanes;
        lanes[lane].notes[lanes[lane].numNotes] = (Note){ (Vector3) { -(noteGap * i+5.0f),0.0f,lane}, RED};
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
        if (lanes[0].notes[lanes[0].nextNote].position.x > 7.0f) {
            lanes[0].nextNote++;
            PlaySound(hitSound);
        }
    }
    if (IsKeyPressed(KEY_J))
    {
        if (lanes[1].notes[lanes[1].nextNote].position.x > 7.0f) {
            lanes[1].nextNote++;
            PlaySound(hitSound);
        }
    }
    if (IsKeyPressed(KEY_F))
    {
        if (lanes[2].notes[lanes[2].nextNote].position.x > 7.0f) {
            lanes[2].nextNote++;
            PlaySound(hitSound);
        }
    }
    if (IsKeyPressed(KEY_D))
    {
        if (lanes[3].notes[lanes[3].nextNote].position.x > 7.0f) {
            lanes[3].nextNote++;
            PlaySound(hitSound);
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
                lanes[i].notes[j].position.x += .2f;
            }
        }
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    printf("Draw lane %d %p\n", 0, &lanes[0]);
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
        printf("Draw lane %d %p\n", i, &lanes[i]);
        for (int j = lanes[i].nextNote; j < lanes[i].numNotes; j++) {
            printf("\tDraw note %d\n", j);
            DrawCubeV(lanes[i].notes[j].position, noteSize, lanes[i].notes[j].color);
        }
    }

    DrawGrid(40, 1.0f);

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