#include "../Header/working.hpp"


Adversary GenerateAdversary(Vector2 pos, Vector2 size, float speed)
{
    Adversary *adversary = new Adversary();
    
    
    adversary->adversaryRepresent.x = pos.x;
    adversary->adversaryRepresent.y = pos.y;
    adversary->adversaryRepresent.width = size.x;
    adversary->adversaryRepresent.height = size.y;
    adversary->adversarySpeed = speed;
    

    return *adversary;

}