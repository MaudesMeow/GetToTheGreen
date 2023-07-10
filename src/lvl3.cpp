#include "../Header/working.hpp"
#include <vector>


 



void GenerateLvlThree()
{
    endPoint = GenerateEndPoint(Vector2{screenWidth-120,50},Vector2{40,40},0,true);
    
    int numOfEnemies = 4;
    if (generateAdver)
    {
        cout << numOfEnemies << endl;
        for (int ii =0; ii < numOfEnemies;ii++)
            {
                if (ii == 0) 
                {
                    adversaries.push_back(GenerateAdversary(Vector2{45,200}, Vector2{60,60}, 540.f));
                }
                if (ii ==1)
                {
                    adversaries.push_back(GenerateAdversary(Vector2{200,300}, Vector2{60,60}, 540.f));
                }
                if (ii ==2)
                {
                    adversaries.push_back(GenerateAdversary(Vector2{200,screenHeight-120}, Vector2{100,120}, 540.f));
                }if (ii ==3)
                {
                    adversaries.push_back(GenerateAdversary(Vector2{200,screenHeight-450}, Vector2{100,120}, 540.f));
                }
                
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
    DrawRectangleRec(adversaries[2].adversaryRepresent, BLUE);
    DrawRectangleRec(adversaries[3].adversaryRepresent, LIGHTGRAY);
    DrawRectangleRec(endPoint.endPointRepresent,GREEN);
    
    
    DrawRectangleRec(player->playerRectangle, RED);
    
   SwapPosition(adversaries[0].adversaryRepresent, adversaries[1].adversaryRepresent, player->playerRectangle);
    
   for (int ii = 0; ii < 2; ii++)
    {
        adversaries[ii].adversaryRepresent.y += adversaries[ii].adversarySpeed*GetFrameTime();

        if ((adversaries[ii].adversaryRepresent.y  < 0) || (adversaries[ii].adversaryRepresent.y  > screenHeight-60))
        {
            adversaries[ii].adversarySpeed *= -1;
        }
        
        
    }

    for (int ii = 2; ii < 4; ii++)
    {
        adversaries[ii].adversaryRepresent.x += adversaries[ii].adversarySpeed*GetFrameTime();

        if ((adversaries[ii].adversaryRepresent.x  < 0) || (adversaries[ii].adversaryRepresent.x  > screenWidth-60))
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
        

        playerPos = {20,200};
        playerSize = {20,20};

        
        player = GeneratePlayer(playerPos, playerSize, 4.f);   
    }

    if (CheckCollisionRecs(player->playerRectangle, endPoint.endPointRepresent))
    {
        playerWin = true;
        playGame = 0;
        levelSelection++;
        player->playerRectangle.x = 200;
        player->playerRectangle.y = 20;
    }

    
        

        

}

