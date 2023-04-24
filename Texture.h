#ifndef BASEOBJECT_H_INCLUDED
#define BASEOBJECT_H_INCLUDED
#include "Game_Utils.h"
using namespace std;
class Texture
{
public:
    Texture();
    ~Texture();
    void SetRect(const int &x, const int &y)    {Rect.x=x;Rect.y=y;}
    SDL_Rect GetRect()  {return Rect;}
    SDL_Texture* GetTexture()   {return p_texture;}
    virtual bool LoadTexture(string path, SDL_Renderer* screen);
    void MoveBackGround(SDL_Renderer* screen,const SDL_Rect* clip=NULL);
    void Render(SDL_Renderer* screen,const SDL_Rect* clip=NULL);
    void Free();
protected:
    SDL_Texture* p_texture;
    SDL_Rect Rect;
};

#endif
