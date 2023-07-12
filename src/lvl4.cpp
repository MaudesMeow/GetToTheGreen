#include "../Header/working.hpp"
#include <vector>


 
      
int leftX = 0;
int rightX = screenWidth;
int topY = 0;
int bottomY = screenHeight;
bool movingLeftToRight = true;
bool movingRighttoLeft = false;
bool movingUpDown = false;
bool movingDownUp = false;

void SquarePattern(Rectangle& adRec,int speed, int leftX, int rightX, int topY, int bottomY)
{
    
     if(adRec.y <= topY+40 && adRec.x >= leftX )
     {
        movingDownUp = false;
        adRec.y = topY+40;
        adRec.x += speed*GetFrameTime();
        movingUpDown = true;
        
     }
     if (adRec.x >= rightX-60 && adRec.y <= bottomY )
    {
        movingLeftToRight = false;
        
        adRec.x = rightX-60;
        adRec.y += speed*GetFrameTime();
        movingRighttoLeft = true;
        
    }

    if(adRec.y >= bottomY-60 && adRec.x > leftX-60 )
    {
        movingUpDown = false;
        adRec.y = bottomY-60;
        adRec.x += speed*GetFrameTime()*-1;
        movingDownUp = true;   
    }

    if(adRec.y <= bottomY-40 && adRec.x <= leftX+25 )
    {
        movingRighttoLeft = false;
        adRec.x = leftX+25;
        adRec.y += speed*GetFrameTime()*-1;
        movingLeftToRight = true;
        
    }
}




void GenerateLvlFour()
{
    endPoint = GenerateEndPoint(Vector2{screenWidth-20,screenHeight/2},Vector2{20,20},0,true);
    
    //create the enemies
    int numOfEnemies =6;
    if (generateAdver)
    {
        cout << numOfEnemies << endl;
        for (int ii =0; ii < numOfEnemies;ii++)
            {
                if (ii == 0) 
                {
                    adversaries.push_back(GenerateAdversary(Vector2{0,40}, Vector2{40,40}, 1200.f));
                }
                if (ii ==1)
                {
                    adversaries.push_back(GenerateAdversary(Vector2{0,80}, Vector2{40,40}, 540.f));
                }
                if (ii ==2)
                {
                    adversaries.push_back(GenerateAdversary(Vector2{screenWidth-40,screenHeight-250}, Vector2{40,250}, 540.f));
                }if (ii ==3)
                {
                    adversaries.push_back(GenerateAdversary(Vector2{0,0}, Vector2{40,40}, 540.f));
                }
                if (ii ==4)
                {
                    adversaries.push_back(GenerateAdversary(Vector2{screenWidth-40,0}, Vector2{40,250}, 540.f));
                }
                if (ii ==6)
                {
                    adversaries.push_back(GenerateAdversary(Vector2{0,120}, Vector2{40,80}, 540.f));
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
    DrawRectangleRec(adversaries[1].adversaryRepresent, BLUE);
    DrawRectangleRec(adversaries[2].adversaryRepresent, BLUE);
    DrawRectangleRec(adversaries[3].adversaryRepresent, BLUE);
    DrawRectangleRec(adversaries[4].adversaryRepresent, BLUE);
    DrawRectangleRec(adversaries[5].adversaryRepresent, BLUE);

    DrawRectangleRec(endPoint.endPointRepresent,GREEN);    
    DrawRectangleRec(player->playerRectangle, RED);

    //-------------MOVEMENT-----------------------------------------------------//


    SquarePattern(adversaries[0].adversaryRepresent,adversaries[0].adversarySpeed,leftX,rightX-30,topY,bottomY);

    SquarePattern(adversaries[1].adversaryRepresent,adversaries[1].adversarySpeed,leftX+50,rightX-50,50,screenHeight-60);


    SquarePattern(adversaries[5].adversaryRepresent,adversaries[5].adversarySpeed,leftX+80,rightX-80,80,screenHeight-80);

    
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

