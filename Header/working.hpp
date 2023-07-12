#ifndef HEADER_WORKING
#define HEADER_WORKING

#include <iostream>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include <vector>

using namespace std;


//----------structs--------//

typedef struct player 
{
    bool active; 
    
    Rectangle playerRectangle;
    float playerSpeed;

    Rectangle PlayerFrameRec;
    Rectangle PlayerCollision;
    int PlayerFramesCounter;
    int PlayerFramesSpeed;
    int PlayerCurrentFrame;
    
} Player;

typedef struct EndPoint 
{
    bool endpointActive;
    Rectangle endPointRepresent;

    float speed;

} EndPoint;

typedef struct Adversary
{
    Rectangle adversaryRepresent;
    float adversarySpeed;

} Adversary;




//----global variables-------//



const int screenWidth = 600;
const int screenHeight = 600;
extern int playGame;
extern bool playerWin;
extern bool generateAdver;
extern int numOfEnemies;
extern Vector2 playerPos;
extern Vector2 playerSize;

extern vector<Adversary> adversaries;

extern Adversary adversaryThree;
extern Player *player;
extern Adversary adversary;
extern EndPoint endPoint;

extern int levelSelection;








//Player.cpp
Player* GeneratePlayer(Vector2 pos, Vector2 size, float speed);
void PlayerMovment(Player &playerMov);

//Adversary.cpp
Adversary GenerateAdversary(Vector2 pos, Vector2 size, float speed);

//EndPoint.cpp
EndPoint GenerateEndPoint(Vector2 pos, Vector2 size, float speed,bool isActive);


//LvelGenerator.cpp

void LevelGenerator(int lvlValue);

//lvl1.cpp

void GenerateLvlOne();

//lvl2.cpp
void GenerateLvlTwo();
void SwapPosition(Rectangle rect1, Rectangle rect2, Rectangle rect3);

//lvl3.cpp

void GenerateLvlThree();

//lvl4.cpp

void GenerateLvlFour();
void SquarePatternRight(Rectangle& adRec,int speed, int leftX, int rightX, int topY, int bottomY, int direction);
void SquarePatternLeft(Rectangle& adRec,int speed, int leftX, int rightX, int topY, int bottomY, int direction);


#endif