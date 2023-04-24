#include "Game_Utils.h"
using namespace std;

bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
    if(object1.x+object1.w>=object2.x && object2.x+object2.w>=object1.x
       && object1.y+object1.h>=object2.y && object2.y+object2.h>=object1.y){return true;}
    return false;
}
bool CheckCollision2(const SDL_Rect& object1, const SDL_Rect& object2)
{
    if((object1.x+object1.w<=object2.x && object2.x+object2.w>=object1.x
       && object1.y+object1.h>=object2.y && object2.y+object2.h>=object1.y) ||
       (object1.x+object1.w>=object2.x && object2.x+object2.w>=object1.x
       && object1.y+object1.h<=object2.y && object2.y+object2.h>=object1.y) ||
       (object1.x+object1.w>=object2.x && object2.x+object2.w<=object1.x
       && object1.y+object1.h>=object2.y && object2.y+object2.h>=object1.y) ||
       (object1.x+object1.w>=object2.x && object2.x+object2.w>=object1.x
       && object1.y+object1.h>=object2.y && object2.y+object2.h<=object1.y)) {return true;}
    return false;
}
string number_to_string(int number)
{
    stringstream ss;
    ss << setw(6) << setfill('0') << number;
    string score;
    ss >> score;
    return score;
}

