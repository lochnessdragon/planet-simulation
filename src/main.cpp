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
    std::cout << "\t./planetary [options] - a planet simulator" << std::endl;
    std::cout << "\t--help : prints this message" << std::endl;
    std::cout << "\t--fullscreen : displays the window in fullscreen" << std::endl;
    std::cout << "\t--width <int> : choose the window width" << std::endl;
    std::cout << "\t--height <int> : choose the window height" << std::endl;
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
        } else if (strncmp(argv[i], "--width", strlen(argv[i])) == 0) {
            // try to parse the second argument
            i++;
            if(i < argc) {
                if (isdigit(argv[i][0])) {
                    initArgs.width = atoi(argv[i]);
                } else {
                    std::cerr << "Arg: --width must be followed by a valid number!" << std::endl;
                }
            } else {
                std::cerr << "Arg: --width must be followed by a number!" << std::endl;
                usage();
                exit(0);
            }
        } else if (strncmp(argv[i], "--height", strlen(argv[i])) == 0) {
            // try to parse the second argument
            i++;
            if(i < argc) {
                if (isdigit(argv[i][0])) {
                    initArgs.height = atoi(argv[i]);
                } else {
                    std::cerr << "Arg: --height must be followed by a valid number!" << std::endl;
                }
            } else {
                std::cerr << "Arg: --height must be followed by a number!" << std::endl;
                usage();
                exit(0);
            }
        }
    }

    // allow the window to be resized
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    InitWindow(initArgs.width, initArgs.height, "Planetary");

    // read in initialization params
    if(initArgs.fullscreen) {
        std::cout << "Maximizing window" << std::endl;
        MaximizeWindow();
    }

        // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type
    SetCameraMode(camera, CAMERA_ORBITAL);

    
    SetTargetFPS(60); // Run at 60 fps

    while(!WindowShouldClose()) // Detect window close or escape key
    {
        // update
        UpdateCamera(&camera);
        
        // draw
        BeginDrawing();
        ClearBackground(SKYBLUE);
        BeginMode3D(camera);
        
            DrawSphere({0, 0, 0}, 1, RAYWHITE);
        
        EndMode3D();
        
        EndDrawing();
    }

    CloseWindow();

    return 0;
}