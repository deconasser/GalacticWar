#include "Texture.h"
using namespace std;
Texture::Texture()
{
    p_texture=NULL;
    Rect.x=0;
    Rect.y=0;
    Rect.w=0;
    Rect.h=0;
}
Texture::~Texture()
{
    Free();
}
bool Texture::LoadTexture(string path,SDL_Renderer* screen)
{
    Free();
    SDL_Texture* new_texture=NULL;
    SDL_Surface* load_surface=IMG_Load(path.c_str());
    if(load_surface !=NULL)
    {
        SDL_SetColorKey(load_surface,SDL_TRUE,SDL_MapRGB(load_surface->format,COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));

        if(path == "img/warPlane.png")SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, 0xFF, 0xFF, 0xFF));
        else if(path == "img//select.png") SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, 0xFF, 0xFF, 0xFF));
        else if(path == "img//selected.png" ) SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, 0xFF, 0xFF, 0xFF));
        else if(path == "img//select_Red.png") SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, 0xFF, 0xFF, 0xFF));
        new_texture=SDL_CreateTextureFromSurface(screen, load_surface);
        if(new_texture!=NULL)
        {
            Rect.w=load_surface->w;
            Rect.h=load_surface->h;
        }
        SDL_FreeSurface(load_surface);
    }
    p_texture=new_texture;
    return p_texture!=NULL;
}
void Texture::MoveBackGround(SDL_Renderer* screen,const SDL_Rect* clip)
{
    SDL_Rect renderquad1={Rect.x,Rect.y,Rect.w,Rect.h};
    SDL_RenderCopy(screen,p_texture,clip,&renderquad1);
    SDL_Rect renderquad2={Rect.x-SCREEN_WIDTH,Rect.y,Rect.w,Rect.h};
    SDL_RenderCopy(screen,p_texture,clip,&renderquad2);
    Rect.x+=1;
    if(Rect.x>=SCREEN_WIDTH){Rect.x=0;}
}
void Texture::Render(SDL_Renderer* screen,const SDL_Rect* clip)
{
    SDL_Rect renderquad1={Rect.x,Rect.y,Rect.w,Rect.h};
    SDL_RenderCopy(screen,p_texture,clip,&renderquad1);
}
void Texture::Free()
{
    if(p_texture!=NULL)
    {
        SDL_DestroyTexture(p_texture);
        p_texture=NULL;
        Rect.w=0;
        Rect.h=0;
    }
}



