#include "../Header/working.hpp"



void LevelGenerator(int lvlValue)
{

    switch(lvlValue)
    {
        case 0:
            GenerateLvlOne();
            
            break;
        case 1:
            
            GenerateLvlTwo();
            break;
        
        case 2:
            GenerateLvlThree();
            break;

    }

    
}