#include "../Header/working.hpp"
#include <vector>


 
      
int bottomX = 0;
int topX = screenWidth;
int leftY = 0;
int rightY = screenHeight;
bool movingLeftToRight = true;
bool movingRighttoLeft = false;
bool movingUpDown = false;
bool movingDownUp = false;

void ahh()
{
    cout << "I don't fricken know" << endl;
}


void GenerateLvlFour()
{
    endPoint = GenerateEndPoint(Vector2{screenWidth-20,screenHeight/2},Vector2{20,20},0,true);
    
    //create the enemies
    int numOfEnemies = 4;
    if (generateAdver)
    {
        cout << numOfEnemies << endl;
        for (int ii =0; ii < numOfEnemies;ii++)
            {
                if (ii == 0) 
                {
                    adversaries.push_back(GenerateAdversary(Vector2{0,0}, Vector2{60,60}, 180.f));
                }
                if (ii ==1)
                {
                    adversaries.push_back(GenerateAdversary(Vector2{200,300}, Vector2{60,60}, 540.f));
                }
                if (ii ==2)
                {
                    adversaries.push_back(GenerateAdversary(Vector2{1,screenHeight-600}, Vector2{100,120}, 540.f));
                }if (ii ==3)
                {
                    adversaries.push_back(GenerateAdversary(Vector2{1,screenHeight-120}, Vector2{100,120}, 540.f));
                }
                
                
                if (ii == 1)
                {
                    generateAdver = false;
                }
                
            }
    }
            
    
    PlayerMovment(*player);
    //draw my adversaries
    
    DrawRectangleRec(adversaries[0].adversaryRepresent, BLUE);
    DrawRectangleRec(endPoint.endPointRepresent,GREEN);    
    DrawRectangleRec(player->playerRectangle, RED);

    //-------------MOVEMENT-----------------------------------------------------//
    if(adversaries[0].adversaryRepresent.y <= leftY && adversaries[0].adversaryRepresent.x >= bottomX && movingLeftToRight)
    {
        movingDownUp = false;
        adversaries[0].adversaryRepresent.y = leftY;
        adversaries[0].adversaryRepresent.x += adversaries[0].adversarySpeed*GetFrameTime();
        movingUpDown = true;
        ahh();
        
    }
    if (adversaries[0].adversaryRepresent.x >= topX-60 && adversaries[0].adversaryRepresent.y <= rightY &&movingUpDown)
    {
        movingLeftToRight = false;
        
        adversaries[0].adversaryRepresent.x = topX-60;
        adversaries[0].adversaryRepresent.y += adversaries[0].adversarySpeed*GetFrameTime();
        movingRighttoLeft = true;
        
    }
    if(adversaries[0].adversaryRepresent.y >= rightY-60 && adversaries[0].adversaryRepresent.x > bottomX-60 &&movingRighttoLeft )
    {
        movingUpDown = false;
        adversaries[0].adversaryRepresent.y = rightY-60;
        adversaries[0].adversaryRepresent.x += adversaries[0].adversarySpeed*GetFrameTime()*-1;
        movingDownUp = true;
        

        
    }

    if(adversaries[0].adversaryRepresent.y <= rightY-60 && adversaries[0].adversaryRepresent.x <= bottomX && movingDownUp)
    {
        movingRighttoLeft = false;
        adversaries[0].adversaryRepresent.x = bottomX;
        adversaries[0].adversaryRepresent.y += adversaries[0].adversarySpeed*GetFrameTime()*-1;
        movingLeftToRight = true;
        
    }


    
    
        
        
    
     //-----------------losing or winning game!--------------------//
    if (CheckCollisionRecs(player->playerRectangle, adversaries[0].adversaryRepresent))
    {
        playGame = 0;
        playerWin = false;
        adversaries[0].adversaryRepresent.x = 0;
        adversaries[0].adversaryRepresent.y = 0;
        

        playerPos = {0,screenHeight/2};
        playerSize = {20,20};
        
        
        player = GeneratePlayer(playerPos, playerSize, 4.f);
    }
    
    //win game
    if (CheckCollisionRecs(player->playerRectangle, endPoint.endPointRepresent))
    {
        playerWin = true;
        playGame = 0;
        levelSelection++;
        player->playerRectangle.x = 200;
        player->playerRectangle.y = 20;
    }

    
        

        

}

