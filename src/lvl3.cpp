#include "../Header/working.hpp"
#include <vector>


 
bool timeToGrow = true;


void GenerateLvlThree()
{
    endPoint = GenerateEndPoint(Vector2{screenWidth-20,screenHeight/2},Vector2{20,20},0,true);
    
    //create the enemies
    int numOfEnemies = 5;
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
                    adversaries.push_back(GenerateAdversary(Vector2{1,screenHeight-600}, Vector2{screenWidth,260}, 540.f));
                }if (ii ==3)
                {
                    adversaries.push_back(GenerateAdversary(Vector2{1,screenHeight-260}, Vector2{screenWidth,260}, 540.f));
                }
                if (ii ==4)
                {
                    adversaries.push_back(GenerateAdversary(Vector2{screenWidth-100,0}, Vector2{60,60}, 720.f));
                }
                
                string val = to_string(ii);
                cout << "here is enemy " << val << endl;
                if (ii == 4)
                {
                    generateAdver = false;
                }
                
            }
    }
            
    
    PlayerMovment(*player);
    //draw my adversaries
    
    DrawRectangleRec(adversaries[0].adversaryRepresent, BLUE);
    DrawRectangleRec(adversaries[1].adversaryRepresent, BLUE);
    DrawRectangleRec(adversaries[4].adversaryRepresent, BLUE);
    DrawRectangleRec(adversaries[2].adversaryRepresent, GRAY);
    DrawRectangleRec(adversaries[3].adversaryRepresent, GRAY);
    
    DrawRectangleRec(endPoint.endPointRepresent,GREEN);
    DrawRectangleLines(0,0,screenWidth,screenHeight,WHITE);
    
    
    DrawRectangleRec(player->playerRectangle, RED);

    

    
    
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

    adversaries[4].adversaryRepresent.y += adversaries[4].adversarySpeed*GetFrameTime();

        if ((adversaries[4].adversaryRepresent.y  < 0) || (adversaries[4].adversaryRepresent.y  > screenHeight-60))
        {
            adversaries[4].adversarySpeed *= -1;
        }
    //moving pieces horizontally
    // for (int ii = 2; ii < 4; ii++)
    // {
    //     adversaries[ii].adversaryRepresent.x += adversaries[ii].adversarySpeed*GetFrameTime();
        
    //     if ((adversaries[ii].adversaryRepresent.x  < 0) || (adversaries[ii].adversaryRepresent.x  > (screenWidth-500)))
    //     {
    //         adversaries[ii].adversarySpeed *= -1;
    //     }
        
        
    // }

    
    
     

    for (int ii = 0; ii <6; ii++)
    {
        if (CheckCollisionRecs(player->playerRectangle, adversaries[ii].adversaryRepresent))
        {
            cout << "collided with " << ii << endl;
            playGame = 0;
            playerWin = false;
            
            

            playerPos = {0,screenHeight/2};
            playerSize = {20,20};

            
            player = GeneratePlayer(playerPos, playerSize, 4.f);   
            timeToGrow = true;
        }
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

    
        

        

};

