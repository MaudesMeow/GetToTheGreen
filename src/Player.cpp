#include "../Header/working.hpp"


Player* GeneratePlayer(Vector2 pos, Vector2 size, float speed)
{
    Player* newPlayer = new Player();  // Dynamically allocate memory for the player
    
    newPlayer->playerRectangle.x = pos.x;
    newPlayer->playerRectangle.y = pos.y;
    newPlayer->playerRectangle.width = size.x;
    newPlayer->playerRectangle.height = size.y;
    newPlayer->playerSpeed = speed;

    return newPlayer;
}


// void PlayerMovment(Player &playerMov)
// {
    

//     if (IsKeyUp(KEY_LEFT_SHIFT))
//     {
//         player->playerSpeed = 4.f;

//     }
//     if (IsKeyDown(KEY_LEFT_SHIFT))
//     {
//         player->playerSpeed = 8.f;
//     }
//     if (IsKeyDown(KEY_W))
//     {
//         playerMov.playerRectangle.y -= playerMov.playerSpeed;
//         playerMov.playerRectangle.y = playerMov.playerRectangle.y;
//     }
//     if (IsKeyDown(KEY_A))
//     {
//         playerMov.playerRectangle.x -= playerMov.playerSpeed;
//         playerMov.playerRectangle.x = playerMov.playerRectangle.x;
//     }
//     if (IsKeyDown(KEY_S))
//     {
//         playerMov.playerRectangle.y += playerMov.playerSpeed;
//          playerMov.playerRectangle.y = playerMov.playerRectangle.y;
//     }
//     if (IsKeyDown(KEY_D))
//     {
//         playerMov.playerRectangle.x += playerMov.playerSpeed;
//          playerMov.playerRectangle.x = playerMov.playerRectangle.x;
//     }

   
// }

void PlayerMovment(Player &playerMov)
{
    if (IsKeyUp(KEY_LEFT_SHIFT))
    {
        playerMov.playerSpeed = 4.f;
    }
    if (IsKeyDown(KEY_LEFT_SHIFT))
    {
        playerMov.playerSpeed = 8.f;
    }

    if (IsKeyDown(KEY_W) && playerMov.playerRectangle.y - playerMov.playerSpeed >= 0)
    {
        playerMov.playerRectangle.y -= playerMov.playerSpeed;
    }
    if (IsKeyDown(KEY_A) && playerMov.playerRectangle.x - playerMov.playerSpeed >= 0)
    {
        playerMov.playerRectangle.x -= playerMov.playerSpeed;
    }
    if (IsKeyDown(KEY_S) && playerMov.playerRectangle.y + playerMov.playerRectangle.height + playerMov.playerSpeed <= 600)
    {
        playerMov.playerRectangle.y += playerMov.playerSpeed;
    }
    if (IsKeyDown(KEY_D) && playerMov.playerRectangle.x + playerMov.playerRectangle.width + playerMov.playerSpeed <= 600)
    {
        playerMov.playerRectangle.x += playerMov.playerSpeed;
    }
}
