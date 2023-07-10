#include "../Header/working.hpp"


    Vector2 enemyPosition = {(float)screenWidth/2, (float)screenHeight/2};
    Vector2 enemySize = {(float)60, (float)60};

    Vector2 playerPos = {0,screenHeight/2};
    Vector2 playerSize = {20,20};

    Vector2 endpointPos = {screenWidth-120, screenHeight/2};
    Vector2 endPointSize = {40,40};

    
    Player* player = GeneratePlayer(playerPos, playerSize, 4.f);
    EndPoint endPoint = GenerateEndPoint(endpointPos,endPointSize,0,true);

    bool playerWin;

    vector<Adversary> adversaries;
    

   
    





void GenerateLvlOne()
{
    int numOfEnemies = 1;
    if (generateAdver)
    {
        for (int ii =0; ii < numOfEnemies;ii++)
            {
                adversaries.push_back(GenerateAdversary(Vector2{screenWidth/4,screenHeight/4}, Vector2{60,60}, 540.f));
                string val = to_string(ii);
                cout << "here is enemy " << val << endl;
                if (ii == (numOfEnemies - 1))
                {
                    generateAdver = false;
                }
                
            }
    }
    
    adversaries.push_back(GenerateAdversary(enemyPosition, enemySize, 540.f));
    PlayerMovment(*player);

    DrawRectangleRec(adversaries[0].adversaryRepresent, BLUE);
    DrawRectangleRec(player->playerRectangle, RED);
    DrawRectangleRec(endPoint.endPointRepresent, GREEN);
    DrawRectangleLines(0,0,screenWidth,screenHeight,WHITE);

    
   
        adversaries[0].adversaryRepresent.y += adversaries[0].adversarySpeed*GetFrameTime();

        if (adversaries[0].adversaryRepresent.y  < 0)
        {
            adversaries[0].adversarySpeed *= -1;
        }
        if (adversaries[0].adversaryRepresent.y  > screenHeight-60)
        {
            adversaries[0].adversarySpeed *= -1;
        }
        
    
    
   
    
    //lose game
    if (CheckCollisionPointRec(Vector2{player->playerRectangle.x, player->playerRectangle.y}, adversaries[0].adversaryRepresent))
    {
        playGame = 0;
        playerWin = false;
        enemyPosition = {(float)screenWidth/2, (float)screenHeight/2};
        enemySize = {(float)60, (float)60};

        playerPos = {0,screenHeight/2};
        playerSize = {20,20};

        
        player = GeneratePlayer(playerPos, playerSize, 4.f);   
    }

    if (CheckCollisionPointRec(Vector2{player->playerRectangle.x, player->playerRectangle.y}, endPoint.endPointRepresent))
    {
        playerWin = true;
        playGame = 0;
        levelSelection++;
        player->playerRectangle.x = 0;
        player->playerRectangle.y = screenHeight/2;
    }

    
        
    
        

}