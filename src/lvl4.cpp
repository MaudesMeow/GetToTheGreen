#include "../Header/working.hpp"
#include <vector>


 
void SquareTravel(Adversary adversarySquare, int bottomX, int topX, int leftY, int rightY)
{
    adversarySquare.adversaryRepresent.x += adversarySquare.adversarySpeed*GetFrameTime();
    if ((adversarySquare.adversaryRepresent.x  < bottomX) || (adversarySquare.adversaryRepresent.x  > topX))
        {
            adversarySquare.adversarySpeed *= -1;
        }
        
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
                    adversaries.push_back(GenerateAdversary(Vector2{40,40}, Vector2{60,60}, 180.f));
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
    DrawRectangleRec(endPoint.endPointRepresent,GREEN);    
    DrawRectangleRec(player->playerRectangle, RED);

    
    SquareTravel(adversaries[0], 0, screenWidth, 0, screenHeight);
    
     //lose game
    if (CheckCollisionRecs(player->playerRectangle, adversaries[0].adversaryRepresent))
    {
        playGame = 0;
        playerWin = false;
        adversaries[0].adversaryRepresent.x = {(float)screenWidth/2};
        adversaries[0].adversaryRepresent.y = {(float)screenHeight/2};
        

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

