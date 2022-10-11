#include <iostream>
#include <raylib.h>

int main(int argc, const char** argv) {
    InitWindow(800, 450, "Planetary");
    SetTargetFPS(60); // Run at 60 fps

    while(!WindowShouldClose()) // Detect window close or escape key
    {
        // update

        // draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("The first window", 200, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}