#include "../Header/working.hpp"

using namespace std;

int playGame = 0;
int levelSelection = 0;
bool generateAdver = true;



int main(void)
{

    
    

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        
        
            BeginDrawing();
       
            ClearBackground(BLACK);
            
            if (levelSelection == 0 && playGame == 0)
            {
                DrawText("Welcome to the game, friend. here's a simple one for ya. \n (Y to continue, ESC to leave)", 16, screenHeight/2, 18, WHITE);
                if (IsKeyDown(KEY_Y))
                {
                    levelSelection++;
                    playGame = 1;
                }
            }

            if (playGame == 0 && !playerWin && levelSelection > 0)
            {
                DrawText("play again? oyu lost...", screenWidth/2, screenHeight/2, 20, WHITE);
                if (IsKeyDown(KEY_Y))
                {
                    playGame = 1;
                    adversaries.clear();
                    generateAdver = true;
                }
            } 
            else if (playGame == 0 && playerWin && levelSelection > 0)
            {
                DrawText("play again? oyu won!...", screenWidth/2, screenHeight/2, 20, WHITE);
                if (IsKeyDown(KEY_Y))
                {
                    playGame = 1;
                    generateAdver = true;
                    adversaries.clear();
                }
            }
            else 
            {
                
                LevelGenerator(4);

            }
                         
        EndDrawing();

    }
    CloseWindow();        
    

    return 0;
};







