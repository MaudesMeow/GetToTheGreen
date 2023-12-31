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
                DrawText("play again? you lost... \n (Y)es or (ESC) no", screenWidth/2, screenHeight/2, 20, WHITE);
                if (IsKeyDown(KEY_Y))
                {
                    playGame = 1;
                    adversaries.clear();
                    generateAdver = true;
                    adversaries.clear();
                }
            } 
            else if (playGame == 0 && playerWin && levelSelection > 0)
            {
                switch(levelSelection)
                {
                    case 2:
                        DrawText("This one is a little tougher, careful of the ol'switcharoo!", 0, screenHeight/2, 20, WHITE);
                        break;
                    case 3:
                        DrawText("third verse, more clastrophobic than the last!", 0, screenHeight/2, 20, WHITE);
                        break;
                    case 4:
                        DrawText("Sorry, this might make you dizzy.", 0, screenHeight/2, 20, WHITE);
                        break;
                        
                    default:
                        DrawText("play again? oyu won!...", screenWidth/2, screenHeight/2, 20, WHITE);
                        break;

                }
                if (IsKeyDown(KEY_Y))
                {
                    playGame = 1;
                    generateAdver = true;
                    adversaries.clear();
                }
            }
            else if (playGame == 0 && playerWin && levelSelection == 5)
            {   
                DrawText("Congrats, you beat the game! Play Again? \n (Y)es or (ESC) No?", screenWidth/2, screenHeight/2, 20, WHITE);
                if (IsKeyDown(KEY_Y))
                {
                    levelSelection = 1;
                }    
            }
            
            else 
            {
                
                
                LevelGenerator(levelSelection);

            }
                         
        EndDrawing();

    }
    CloseWindow();        
    

    return 0;
};







