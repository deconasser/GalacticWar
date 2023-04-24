#ifndef PLAYER_POWER_H
#define PLAYER_POWER_H
#include "Game_Utils.h"
#include "Texture.h"
class PlayerPower:public Texture
{
public:
    PlayerPower();
    ~PlayerPower();
    void SetNumber(const int& num){number_=num;}
    int get_number_() {return number_;};
    void AddPos(const int& xpos);
    void initdata(SDL_Renderer* screen);
    void Decrease();
    void Increase();
    //Texture
    bool LoadTexture(string path, SDL_Renderer* screen);
    void ShowHeart(SDL_Renderer* des);
    int get_pos_list_size() {return pos_list_.size();}
    void Reset();
    void set_beta(int value_) {beta = value_;}
    //
private:
    int number_;
    double height_frame;
    double width_frame;
    SDL_Rect Frame_clip;
    vector<int> pos_list_;
    int beta;
};
#endif // PLAYER_POWER_H




