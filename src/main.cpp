#include <iostream>
#include <cstring>
#include <cstdlib>

#include <raylib.h>

struct InitParams {
    bool fullscreen = false;
    int width = 800;
    int height = 450;
};

void usage() {
    std::cout << "Usage:" << std::endl;
    std::cout << "\t./planetary - a planet simulator" << std::endl;
    std::cout << "\t--help : prints this message" << std::endl;
    std::cout << "\t--fullscreen : displays the window in fullscreen" << std::endl;
}

int main(int argc, const char** argv) {
    InitParams initArgs;
    
    // read arguments
    for (int i = 0; i < argc; i++) {
        if(strncmp(argv[i], "--help", strlen(argv[i])) == 0) {
            usage();
            exit(0);
        } else if (strncmp(argv[i], "--fullscreen", strlen(argv[i])) == 0) {
            initArgs.fullscreen = true;
        }
    }

    SetWindowState(FLAG_WINDOW_RESIZABLE);
    InitWindow(initArgs.width, initArgs.height, "Planetary");
    if(initArgs.fullscreen) {
        std::cout << "Maximizing window" << std::endl;
        MaximizeWindow();
    }
    
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