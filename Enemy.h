#ifndef THREATOBJECT_H_INCLUDED
#define THREATOBJECT_H_INCLUDED
#include "Icon.h"
#include "Game_Utils.h"
#include "Texture.h"
#include "Bullet.h"
#include "Character.h"
#define Enemy_Width 51
#define Enemy_Height 85
using namespace std;
class Enemy:public Texture
{
public:
    Enemy();
    ~Enemy();
    //Move
    void MoveThreat();
    void HandleInputAction(SDL_Event events);
    //Texture
    bool LoadTexture(string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void Show_Pow(SDL_Renderer* des);
    void set_clip();
    //Position
    void set_x_pos(const double &xPos) {x_pos=xPos;}
    void set_y_pos(const double &yPos) {y_pos=yPos;}
    double get_x_pos() const {return x_pos;}
    double get_y_pos() const {return y_pos;}
    //SetLimit
    void set_x_limit(const double &xLimit) {x_limit=xLimit;}
    //
    void set_type_threat(const double type_) {type=type_;}
    double get_type_threat() const {return type;}
    void set_stats(SDL_Renderer* screen);
    //movement
    void set_x_speed(const float &xSpeed) {x_speed=xSpeed;}
    void set_y_speed(const float &ySpeed) {y_speed=ySpeed;}
    //frame
    int get_width_frame() const {return width_frame;}
    int get_height_frame() const {return height_frame;}
    void set_type(const double& _type){type=_type;}
    //bullet
    bool canspawnbullet();
    void MakeBullet(vector<Bullet*> &bullet,SDL_Renderer* screen,Character &spaceship);
    void MakeBulletUponDeath(vector<Bullet*> &bullet,SDL_Renderer* screen);
    void RemoveBullet(const int &index);
   //angle
    void rotate_angle();void rotate_angle_cp();
    void rotate_angle_2();void rotate_angle_2_cp();
    void rotate_angle_3();void rotate_angle_3_cp();
    void rotate_angle_4();void rotate_angle_4_cp();
    void set_angle_rotate_speed(const double& angleSpeed) {angle_rotate_speed=angleSpeed;}
    void set_angle(const double& angle_) {angle=angle_;}
    //
    int get_score() const {return score;}
    void Enemy_die_icr() {die++;}
    bool Enemy_die();
    //
    int get_frame() {return frame;}
    void set_frame(int frame_) {frame = frame_;}
    //Bonus
    void Health_Icon(vector<Icon*> &health,SDL_Renderer* screen);
    void Rocket_Bonus_Icon(vector<Icon*> &Rocket_Bonus, SDL_Renderer* screen);
    void Upgrade_Bonus_Icon(vector<Icon*> &Upgrade_Bonus, SDL_Renderer* screen);
private:
    double x_pos;
    double y_pos;
    double x_speed;
    double y_speed;
    double x_limit;
    double width_frame;
    double height_frame;
    int random_y;
    SDL_Rect frame_clip[0];
    vector<Bullet*> p_bullet_list;
   // int checkbullet;
    double type;
    bool changespawn;
    double angle,angle_cp;
    double angle2,angle2_cp;
    double angle3,angle3_cp;
    double angle4,angle4_cp;
    double angle_rotate_speed;
    double angle_move;
    int delay_shoot_time;
    int delay_shoot_time2;
    unsigned long long CurrentTime;
    unsigned long long LastTime;
    int first;
    int score;
    int die;
    int frame;
    int cnt;
};
#endif

