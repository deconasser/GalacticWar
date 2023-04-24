#ifndef MAINOBJECT_H_INCLUDED
#define MAINOBJECT_H_INCLUDED
#include "Game_Utils.h"
#include "Texture.h"
#include "Bullet.h"

using namespace std;
class Character:public Texture
{
public:
    Character();
    ~Character();

    enum StateType
    {
        Normal=1,
        Pause=2
    };
    //texture
    bool LoadTexture(string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void set_clip();
    SDL_Rect GetHitBox();
    //positions
    void set_positions(const int x,const int y)
    {
        x_pos=x;
        y_pos=y;
    }
    //bullet
    vector<Bullet*> get_bullet_list() const {return p_bullet_list;}
    void HandleBullet1(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);

    void SpawnBullet(SDL_Renderer* screen);
    void RemoveBullet(const int &index);
    void Reset();
    //frame
    int get_width_frame() const {return width_frame;}
    int get_height_frame() const {return height_frame;}
    int set_check_bullet(int value_) { increase_bullet= value_;}
    //
    void set_character1(bool value_) {character1=value_;}
    void set_character2(bool value_) {character2=value_;}
    void set_character3(bool value_) {character3=value_;}
    bool get_character1() {return character1;}
    bool get_character2() {return character2;}
    bool get_character3() {return character3;}
    //
    void set_level_1(bool value_) {level_1 = value_;}
    bool get_level_1() {return level_1;}
    void set_level_2(bool value_) {level_2 = value_;}
    bool get_level_2() {return level_2;}
    void set_level_3(bool value_) {level_3 = value_;}
    bool get_level_3() {return level_3;}
    void set_level_4(bool value_) {level_4 = value_;}
    bool get_level_4() {return level_4;}
    void set_level_5(bool value_) {level_5 = value_;}
    bool get_level_5() {return level_5;}

    int get_check_bullet() {return checkbullet;}
    bool get_spawn_bullet() {return spawn_bullet;}
    void set_spawn_bullet(bool value_) {spawn_bullet=value_;}


private:
    int x_pos;
    int y_pos;
    int width_frame;
    int height_frame;
    int frame;
    SDL_Rect frame_clip[10];
    int status;
    bool input_mouse;
    double angle;
    vector<Bullet*> p_bullet_list;
    int checkbullet;
    unsigned long long CurrentTime;
    unsigned long long LastTime;
    int increase_bullet;
    bool character1;
    bool character2;
    bool character3;

    bool level_1;
    bool level_2;
    bool level_3;
    bool level_4;
    bool level_5;

    bool spawn_bullet;
};

#endif
