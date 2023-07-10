#include "../Header/working.hpp"

EndPoint lvlEndPoint;


EndPoint GenerateEndPoint(Vector2 pos, Vector2 size, float speed,bool isActive)
{
    lvlEndPoint.endpointActive = isActive;
    lvlEndPoint.speed = speed;
    lvlEndPoint.endPointRepresent.x = pos.x;
    lvlEndPoint.endPointRepresent.y = pos.y;
    lvlEndPoint.endPointRepresent.width = size.x;
    lvlEndPoint.endPointRepresent.height = size.y;
    return lvlEndPoint;        
}