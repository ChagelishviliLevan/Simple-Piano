#include "raylib.h"

#define button_numbers 8

const int screen_width = 690;
const int screen_height = 270;
const int button_width = 70;
const int button_height = 160;

int button_y = screen_height - button_height - 30;
int button_x[button_numbers];
Sound piano_sounds[8]; 

int main(void) {
    InitWindow(screen_width, screen_height, "Simple Piano");
    InitAudioDevice();

    // Load sounds
    piano_sounds[0] = LoadSound("sounds/C.mp3");   
    piano_sounds[1] = LoadSound("sounds/D.mp3");   
    piano_sounds[2] = LoadSound("sounds/E.mp3");   
    piano_sounds[3] = LoadSound("sounds/F.mp3");  
    piano_sounds[4] = LoadSound("sounds/G.mp3");   
    piano_sounds[5] = LoadSound("sounds/A.mp3");   
    piano_sounds[6] = LoadSound("sounds/B.mp3");   
    piano_sounds[7] = LoadSound("sounds/C2.mp3");

    for(int i = 0; i < button_numbers; i++) {
        button_x[i] = 25*(i+1) + i*button_width;
    }

    while(!WindowShouldClose()) {
        Vector2 mouse_position = GetMousePosition();

        for(int i = 0; i < button_numbers; i++) {
            Rectangle button = {button_x[i], button_y, button_width, button_height};
            
            if (CheckCollisionPointRec(mouse_position, button) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                PlaySound(piano_sounds[i]);
            }
        }
        
        BeginDrawing();
            ClearBackground(BLACK);
            for(int i = 0; i < button_numbers; i++) {
                DrawRectangle(button_x[i], button_y, button_width, button_height, WHITE);
            }
        EndDrawing();
    }


    for(int i = 0; i < button_numbers; i++) {
        UnloadSound(piano_sounds[i]);
    }
    
    CloseAudioDevice();
    CloseWindow();

    return 0;
}