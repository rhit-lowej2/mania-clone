// /*
// Raylib example file.
// This is an example main file for a simple raylib project.
// Use this as a starting point or replace it with your code.

// For a C++ project simply rename the file to .cpp and re-run the build script 

// -- Copyright (c) 2020-2024 Jeffery Myers
// --
// --This software is provided "as-is", without any express or implied warranty. In no event 
// --will the authors be held liable for any damages arising from the use of this software.

// --Permission is granted to anyone to use this software for any purpose, including commercial 
// --applications, and to alter it and redistribute it freely, subject to the following restrictions:

// --  1. The origin of this software must not be misrepresented; you must not claim that you 
// --  wrote the original software. If you use this software in a product, an acknowledgment 
// --  in the product documentation would be appreciated but is not required.
// --
// --  2. Altered source versions must be plainly marked as such, and must not be misrepresented
// --  as being the original software.
// --
// --  3. This notice may not be removed or altered from any source distribution.

// */

// #include "raylib.h"
// #include "screens.h"
// #include <stdlib.h>
// #include <stdio.h>

// #include "resource_dir.h"	// utility header for SearchAndSetResourceDir

// typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

// typedef struct Note {
//     Vector3 position;
//     Color color;
// } Note;

// typedef struct Lane {
//     Note* notes;
//     int nextNote;
//     int numNotes;
// } Lane;

// int main ()
// {
//     Camera camera = { 0 };
//     camera.position = (Vector3){ 11.0f, 2.0f, 1.5f };    // Camera position
//     camera.target = (Vector3){ 0.0f, 0.0f, 1.5f };      // Camera looking at point
//     camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
//     camera.fovy = 100.0f;                                // Camera field-of-view Y
//     camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

//     const int screenWidth = 800;
//     const int screenHeight = 450;
//     const int noteWidth = 50;
//     const int noteHeight = 20;
//     Vector3 noteSize = { .9f, .9f, .9f };

// 	// Tell the window to use vysnc and work on high DPI displays
// 	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

// 	// Create the window and OpenGL context
// 	InitWindow(screenWidth, screenHeight, "Hello Raylib");

//     InitAudioDevice();              // Initialize audio device

//     Music music = LoadMusicStream("resources/foolmoon.mp3");
//     PlayMusicStream(music);
//     StopMusicStream(music);

//     Sound hitsound = LoadSound("resources/drum-hitnormal.wav");

// 	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
// 	SearchAndSetResourceDir("resources");

// 	// Load a texture from the resources directory
// 	Texture wabbit = LoadTexture("wabbit_alpha.png");
	
// 	int framesCounter = 0;	// a counter to keep track of how many frames have passed
//     bool pause = true;     // Music pause control flag
//     GameScreen currentScreen = LOGO;	// the current screen we are on
//     int fps = 60;

//     // map specific information
//     int numNotes = 800;
//     int noteSpeed = 40;
//     int bpm = 138;
//     int numLanes = 4;

//     // basic calculation on note distance per beat
//     double noteGap = noteSpeed * fps / bpm;

//     // init lanes
//     Lane* lanes = malloc(sizeof(Lane) * numLanes);

//     for (int i = 0; i < numLanes; i++) {
//         lanes[i].notes = malloc(sizeof(Note) * numNotes);
//         lanes[i].nextNote = 0;
//         lanes[i].numNotes = 0;
//     }

//     for (int i = 0; i < numNotes; i++) {
//         int lane = rand() % numLanes;
//         lanes[lane].notes[lanes[lane].numNotes] = (Note){ (Vector3) { -(noteGap * i+5.0f),0.0f,lane}, RED};
//         lanes[lane].numNotes++;
//         // laneD[i] = (Note) {0, (int) (noteGap * (i + 5)), RED};
//     }

// 	SetTargetFPS(fps);	// set the target frame rate to 60 frames per second
	
// 	// game loop
// 	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
// 	{
//         UpdateMusicStream(music);
// 		switch(currentScreen)
//         {
//             case LOGO:
//             {
//                 // TODO: Update LOGO screen variables here!

//                 framesCounter++;    // Count frames

//                 // Wait for 2 seconds (120 frames) before jumping to TITLE screen
//                 if (framesCounter > 0)
//                 {
//                     currentScreen = TITLE;
//                 }
//             } break;
//             case TITLE:
//             {
//                 // TODO: Update TITLE screen variables here!

//                 // Press enter to change to GAMEPLAY screen
//                 if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
//                 {
//                     currentScreen = GAMEPLAY;
//                 }
//             } break;
//             case GAMEPLAY:
//             {
//                 // TODO: Update GAMEPLAY screen variables here!
//                 // Press enter to change to ENDING screen
//                 for (int i = 0; i < numLanes; i++) {
//                     while (lanes[i].notes[lanes[i].nextNote].position.x > 10.0f) {
//                         lanes[i].nextNote++;
//                         printf("skipped a note at lane %d\n", i);
//                     }
//                 }

//                 if (IsKeyPressed(KEY_K))
//                 {
//                     if (lanes[0].notes[lanes[0].nextNote].position.x > 7.0f) {
//                         lanes[0].nextNote++;
//                         PlaySound(hitsound);
//                     }
//                 }
//                 if (IsKeyPressed(KEY_J))
//                 {
//                     if (lanes[1].notes[lanes[1].nextNote].position.x > 7.0f) {
//                         lanes[1].nextNote++;
//                         PlaySound(hitsound);
//                     }
//                 }
//                 if (IsKeyPressed(KEY_F))
//                 {
//                     if (lanes[2].notes[lanes[2].nextNote].position.x > 7.0f) {
//                         lanes[2].nextNote++;
//                         PlaySound(hitsound);
//                     }
//                 }
//                 if (IsKeyPressed(KEY_D))
//                 {
//                     if (lanes[3].notes[lanes[3].nextNote].position.x > 7.0f) {
//                         lanes[3].nextNote++;
//                         PlaySound(hitsound);
//                     }
//                 }
//                 if (IsKeyPressed(KEY_SPACE))
//                 {
//                     if (pause) {
//                         PlayMusicStream(music);
//                         pause = false;
//                     }
//                     else {
//                         pause = true;
//                         for (int i = 0; i < numLanes; i++) {
//                             printf("Lane %d has nextNote %d with position x of %f\n", i, lanes[i].nextNote, lanes[i].notes[lanes[i].nextNote].position.x);
//                         }
//                     }
//                 }
//                 else if (IsKeyPressed(KEY_ENTER))
//                 {
//                     currentScreen = ENDING;
//                 }
//                 // else if (IsKeyPressed(KEY_Z))
//                 // {
//                 //     if (notes[nextNote].y > - noteHeight / 2 && notes[nextNote].y < noteHeight / 2) {
//                 //         nextNote++;
//                 //         PlaySound(hitsound);
//                 //     }
//                 // }

//                 if (!pause) {
//                     for (int i = 0; i < numLanes; i++) {
//                         for (int j = lanes[i].nextNote; j < lanes[i].numNotes; j++) {
//                             lanes[i].notes[j].position.x += .2f;
//                         }
//                     }
//                 }
//             } break;
//             case ENDING:
//             {
//                 // TODO: Update ENDING screen variables here!

//                 // Press enter to return to TITLE screen
//                 if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
//                 {
//                     currentScreen = TITLE;
//                 }
//             } break;
//             default: break;
//         }
// 		// drawing
// 		BeginDrawing();

// 		// Setup the backbuffer for drawing (clear color and depth buffers)
// 		ClearBackground(WHITE);

// 		switch(currentScreen)
//             {
//                 case LOGO:
//                 {
//                     // TODO: Draw LOGO screen here!
//                     DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
//                     DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

//                 } break;
//                 case TITLE:
//                 {
//                     // TODO: Draw TITLE screen here!
//                     DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
//                     DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
//                     DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

//                 } break;
//                 case GAMEPLAY:
//                 {
//                     // TODO: Draw GAMEPLAY screen here!
//                     DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
//                     // DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
//                     if (pause) {
//                         DrawText("PRESS SPACE TO START", 240, 220, 20, MAROON);
//                     }

//                     BeginMode3D(camera);
//                     DrawCubeWires((Vector3){9.0f, 0.0f, 0.0f},0.5f, 1.0f, 1.0f, RED);
//                     DrawCubeWires((Vector3) { 9.0f, 0.0f, 1.0f }, .5f, 1.0f, 1.0f, RED);
//                     DrawCubeWires((Vector3) { 9.0f, 0.0f, 2.0f }, .5f, 1.0f, 1.0f, RED);
//                     DrawCubeWires((Vector3){9.0f, 0.0f, 3.0f},.5f, 1.0f, 1.0f, RED);

//                     for (int i = 0; i < numLanes; i++) {
//                         for (int j = lanes[i].nextNote; j < lanes[i].numNotes; j++) {
//                             DrawCubeV(lanes[i].notes[j].position, noteSize, lanes[i].notes[j].color);
//                         }
//                     }

//                     DrawGrid(40, 1.0f);

//                     EndMode3D();

//                 } break;
//                 case ENDING:
//                 {
//                     // TODO: Draw ENDING screen here!
//                     DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
//                     DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
//                     DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

//                 } break;
//                 default: break;
//             }   
		
// 		// end the frame and get ready for the next one  (display frame, poll input, etc...)
// 		EndDrawing();
// 	}

// 	// cleanup
// 	// unload our texture so it can be cleaned up
// 	UnloadTexture(wabbit);

//     for (int i = 0; i < numLanes; i++) {
//         free(lanes[i].notes);
//     }
//     free(lanes);

// 	// destory the window and cleanup the OpenGL context
// 	CloseWindow();
// 	return 0;
// }