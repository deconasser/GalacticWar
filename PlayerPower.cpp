#include "PlayerPower.h"
using namespace std;
PlayerPower::PlayerPower()
{
    width_frame = 0;
    height_frame = 0;
    number_ = 0;
    beta = 180;
}
PlayerPower::~PlayerPower()
{

}
void PlayerPower::AddPos(const int& xpos)
{
    pos_list_.push_back(xpos);
}
 bool PlayerPower::LoadTexture(string path, SDL_Renderer* screen)
{
    bool ret=Texture::LoadTexture(path,screen);
    if(ret==true)
    {
        width_frame=Rect.w;
        height_frame=Rect.h;
    }
    return ret;
}
void PlayerPower::initdata(SDL_Renderer* screen)
{
    LoadTexture("img//HP_Bonus.png", screen);
    number_ = 5;
    pos_list_.clear();
    pos_list_.push_back(20);
    pos_list_.push_back(60);
    pos_list_.push_back(100);
    pos_list_.push_back(140);
    pos_list_.push_back(180);
}
void PlayerPower::ShowHeart(SDL_Renderer* screen)
{

    if(number_ == pos_list_.size())
    {
        for(int i = 0 ; i < pos_list_.size(); i++)
        {
            Rect.x=pos_list_.at(i);
            Rect.y=0;
            Frame_clip.x=0;
            Frame_clip.y=0;
            Frame_clip.w=32;
            Frame_clip.h=32;
            SDL_Rect* current_clip3=&Frame_clip;
            SDL_Rect RenderQuad3={Rect.x,Rect.y,width_frame,height_frame};
            SDL_RenderCopy(screen,GetTexture(),current_clip3,&RenderQuad3);
        }
    }
}
void PlayerPower::Decrease()
{
    number_--;
    pos_list_.pop_back();
    beta-= 40;
}
void PlayerPower::Increase()
{
    number_++;
    beta += 40;
    pos_list_.push_back(beta);
}
void PlayerPower::Reset()
{
    pos_list_.clear();
}

