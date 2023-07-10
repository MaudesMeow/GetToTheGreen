#include "../Header/working.hpp"
#include <vector>


 
bool timeToGrow = true;


void GenerateLvlThree()
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
                    adversaries.push_back(GenerateAdversary(Vector2{45,200}, Vector2{60,60}, 540.f));
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
                
                string val = to_string(ii);
                cout << "here is enemy " << val << endl;
                if (ii == 1)
                {
                    generateAdver = false;
                }
                
            }
    }
            
    
    PlayerMovment(*player);
    //draw my adversaries
    
    DrawRectangleRec(adversaries[0].adversaryRepresent, BLUE);
    DrawRectangleRec(adversaries[1].adversaryRepresent, LIGHTGRAY);
    DrawRectangleRec(adversaries[2].adversaryRepresent, BLUE);
    DrawRectangleRec(adversaries[3].adversaryRepresent, LIGHTGRAY);
    DrawRectangleRec(endPoint.endPointRepresent,GREEN);
    
    
    DrawRectangleRec(player->playerRectangle, RED);

    if ((player->playerRectangle.x == screenWidth/3) && timeToGrow )
    {
        cout << "is it growing" << endl;
        adversaries[3].adversaryRepresent.y -= 75;
        adversaries[3].adversaryRepresent.height += 75;
        adversaries[2].adversaryRepresent.height += 75;
        adversaries[3].adversaryRepresent.width += 150;
        adversaries[2].adversaryRepresent.width += 150;
        timeToGrow = false;
    }

    if ((player->playerRectangle.x == screenWidth/6) && timeToGrow )
    {
        cout << "is it growing" << endl;
        adversaries[3].adversaryRepresent.y -= 75;
        adversaries[3].adversaryRepresent.height += 75;
        adversaries[2].adversaryRepresent.height += 75;
        adversaries[3].adversaryRepresent.width += 150;
        adversaries[2].adversaryRepresent.width += 150;
        timeToGrow = false;
    }
    
    timeToGrow = true;
   SwapPosition(adversaries[0].adversaryRepresent, adversaries[1].adversaryRepresent, player->playerRectangle);
    

    //moving pieces vertically
   for (int ii = 0; ii < 2; ii++)
    {
        adversaries[ii].adversaryRepresent.y += adversaries[ii].adversarySpeed*GetFrameTime();

        if ((adversaries[ii].adversaryRepresent.y  < 0) || (adversaries[ii].adversaryRepresent.y  > screenHeight-60))
        {
            adversaries[ii].adversarySpeed *= -1;
        }
        
        
    }
    //moving pieces horizontally
    for (int ii = 2; ii < 4; ii++)
    {
        adversaries[ii].adversaryRepresent.x += adversaries[ii].adversarySpeed*GetFrameTime();
        
        if ((adversaries[ii].adversaryRepresent.x  < 0) || (adversaries[ii].adversaryRepresent.x  > (screenWidth-400)))
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
        

        playerPos = {0,screenHeight/2};
        playerSize = {20,20};
        timeToGrow = true;

        
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
        timeToGrow = true;
    }

    //lose game
    if (CheckCollisionRecs(player->playerRectangle, adversaries[2].adversaryRepresent))


    {
        playGame = 0;
        playerWin = false;
        adversaries[0].adversaryRepresent.x = {(float)screenWidth/2};
        adversaries[0].adversaryRepresent.y = {(float)screenHeight/2};
        

        playerPos = {0,screenHeight/2};
        playerSize = {20,20};

        
        player = GeneratePlayer(playerPos, playerSize, 4.f);   
        timeToGrow = true;
    }
    
    if (CheckCollisionRecs(player->playerRectangle, adversaries[3].adversaryRepresent))
    {
        playGame = 0;
        playerWin = false;
        adversaries[0].adversaryRepresent.x = {(float)screenWidth/2};
        adversaries[0].adversaryRepresent.y = {(float)screenHeight/2};
        

        playerPos = {0,screenHeight/2};
        playerSize = {20,20};

        
        player = GeneratePlayer(playerPos, playerSize, 4.f);   
        timeToGrow = true;
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

