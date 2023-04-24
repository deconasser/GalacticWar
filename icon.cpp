#include "Icon.h"
using namespace std;

Icon::Icon()
{
    width_frame=0;
    height_frame=0;
    is_move=false;
}
Icon::~Icon()
{

}
bool Icon::LoadTexture(string path, SDL_Renderer* screen)
{
    bool check_load=Texture::LoadTexture(path,screen);
    if(check_load==true)
    {
        width_frame=Rect.w;
        height_frame=Rect.h;
    }
    return check_load;
}

void Icon::MoveEffect(const int &x_limit,const int &y_limit)
{
    Rect.x-=Speed;
    if(Rect.y<0 || Rect.y>y_limit)
    {
        is_move=false;
    }
    if(Rect.x<0 || Rect.x>x_limit)
    {
        is_move=false;
    }
}


