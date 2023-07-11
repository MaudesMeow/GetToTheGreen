#include "../Header/working.hpp"
#include <vector>


 

void SwapPosition(Rectangle rect1, Rectangle rect2, Rectangle rect3)
{
    rect1 = adversaries[0].adversaryRepresent;
    rect2 = adversaries[1].adversaryRepresent;
    rect3 = player->playerRectangle;


    if (rect2.x < screenWidth-200 )
    {
         if (rect3.x > rect2.x && rect2.x > rect1.x) 
        {
            adversaries[0].adversaryRepresent.x = adversaries[1].adversaryRepresent.x + 100; 
            adversaries[1].adversarySpeed *= 2;  
        }
        if (rect3.x > rect1.x && rect1.x > rect2.x)
        {
            adversaries[1].adversaryRepresent.x = adversaries[0].adversaryRepresent.x + 100;
            adversaries[0].adversarySpeed *= 2; 
        }
    }
    



}

void GenerateLvlTwo()
{
    endPoint = GenerateEndPoint(Vector2{screenWidth-120,screenHeight-40},Vector2{40,40},0,true);
    
    int numOfEnemies = 2;
    if (generateAdver)
    {
        cout << numOfEnemies << endl;
        for (int ii =0; ii < numOfEnemies;ii++)
            {
                if (ii == 0) 
                {
                    adversaries.push_back(GenerateAdversary(Vector2{45,200}, Vector2{60,60}, 720.f));
                }
                adversaries.push_back(GenerateAdversary(Vector2{200,300}, Vector2{60,60}, 720.f));
                string val = to_string(ii);
                cout << "here is enemy " << val << endl;
                if (ii == 1)
                {
                    generateAdver = false;
                }
                
            }
    }
            
    
    PlayerMovment(*player);
    // DrawRectangleRec(adversary.adversaryRepresent, BLUE);
    
    DrawRectangleRec(adversaries[0].adversaryRepresent, BLUE);
    DrawRectangleRec(adversaries[1].adversaryRepresent, LIGHTGRAY);
    DrawRectangleRec(endPoint.endPointRepresent,GREEN);
    DrawRectangleLines(0,0,screenWidth,screenHeight,WHITE);
    
    
    DrawRectangleRec(player->playerRectangle, RED);
    
   SwapPosition(adversaries[0].adversaryRepresent, adversaries[1].adversaryRepresent, player->playerRectangle);
    
   for (int ii = 0; ii < adversaries.size(); ii++)
    {
        adversaries[ii].adversaryRepresent.y += adversaries[ii].adversarySpeed*GetFrameTime();

        if ((adversaries[ii].adversaryRepresent.y  < 0) || (adversaries[ii].adversaryRepresent.y  > screenHeight-60))
        {
            adversaries[ii].adversarySpeed *= -1;
        }
        
        
    }

    
    
     //lose game
    if (CheckCollisionRecs(player->playerRectangle, adversaries[0].adversaryRepresent))
    {
        playGame = 0;
        playerWin = false;
        adversaries[0].adversaryRepresent.x = {(float)screenWidth/2};
        adversaries[0].adversaryRepresent.y = {(float)screenHeight/2};
        

        playerPos = {20,20};
        playerSize = {20,20};

        
        player = GeneratePlayer(playerPos, playerSize, 4.f);   
    }

    if (CheckCollisionRecs(player->playerRectangle, adversaries[1].adversaryRepresent))
    {
        playGame = 0;
        playerWin = false;
        adversaries[0].adversaryRepresent.x = {(float)screenWidth/2};
        adversaries[0].adversaryRepresent.y = {(float)screenHeight/2};
        

        playerPos = {0,screenHeight/2};
        playerSize = {20,20};

        
        player = GeneratePlayer(playerPos, playerSize, 4.f);   
    }

    if (CheckCollisionRecs(player->playerRectangle, endPoint.endPointRepresent))
    {
        playerWin = true;
        playGame = 0;
        levelSelection++;
        player->playerRectangle.x = 0;
        player->playerRectangle.y = screenHeight/2;
    }

    
        

        

}

