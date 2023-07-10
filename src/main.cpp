#include "../Header/working.hpp"

using namespace std;

int playGame = 1;
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
            
            if (playGame == 0 && !playerWin)
            {
                DrawText("play again? oyu lost...", screenWidth/2, screenHeight/2, 20, WHITE);
                if (IsKeyDown(KEY_Y))
                {
                    playGame = 1;
                    adversaries.clear();
                    generateAdver = true;
                }
            } 
            else if (playGame == 0 && playerWin)
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
                
                LevelGenerator(2);

            }
                         
        EndDrawing();

    }
    CloseWindow();        
    

    return 0;
}





//lose game
            // if (CheckCollisionPointRec(position, enemyRect))
            // {
            //     position = {20,20};
            //     playGame = false;
                
            //     enemyPosition = {(float)screenWidth/2, (float)screenHeight/2};
            //     playerRect.x = SquarePosition.x;
            //     playerRect.y = SquarePosition.y;
            //     if (playerScore > 0)
            //     {
            //         playerScore--;
            //         enemySpeed /= 2;
            //     }
            //     s = to_string(playerScore);
            //     pchar = s.c_str();
            //     gameOver = "You lose! Play again?  Y or N";
            //     gameOverChar = gameOver.c_str();
                
            // }

            //win game
            // if (CheckCollisionPointRec(position, winBlock) ) 
            // {
            //     position = {20,20};
            //     playGame = false;
            //     enemyPosition = {(float)screenWidth/2, (float)screenHeight/2};
            //     playerRect.x = SquarePosition.x;
            //     playerRect.y = SquarePosition.y;
            //     playerScore ++;
            //     s = to_string(playerScore);
            //     pchar = s.c_str();
            //     if (enemySpeed < 540) 
            //     {
            //         enemySpeed *=2;
            //     }
                
            //     gameOver = "You win! Play again? \n Y or N";
            //     gameOverChar = gameOver.c_str();
                
                
            // }

            // if (playGame) 
            // {
               
                
                
            //     // DrawRectangleRec(playerRect, RED);
            //     // DrawRectangleRec(enemyRect, BLUE);
            //     DrawRectangleRec(winBlock,GREEN);
            //     DrawText(pchar,(screenWidth -30),20,20,WHITE);
            // } 
            
            // else {
            //     DrawText(gameOverChar, screenWidth/2,screenHeight/2,20, WHITE);
            //     if (IsKeyDown(KEY_Y))
            //     {
                    
            //         playGame = true;
            //     }
            // }