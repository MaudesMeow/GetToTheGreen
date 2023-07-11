#include "../Header/working.hpp"



void LevelGenerator(int lvlValue)
{

    switch(lvlValue)
    {
        case 1:
            GenerateLvlOne();
            
            break;
        case 2:
            
            GenerateLvlTwo();
            break;
        
        case 3:
            GenerateLvlThree();
            break;
        case 4:
            GenerateLvlFour();
            break;
        default:
            break;

    }

    
}