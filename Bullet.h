#ifndef BULLETOBJECT_H_INCLUDED
#define BULLETOBJECT_H_INCLUDED
#include "Texture.h"
#include "Game_Utils.h"
using namespace std;
class Bullet : public Texture
{
public:
    Bullet();
    ~Bullet();
    void set_x_speed(const double& xSpeed) {x_speed=xSpeed;}
    void set_y_speed(const double& ySpeed) {y_speed=ySpeed;}
    void set_angle(const double& angle_) {angle=angle_;}
    void set_type(const int& type_) {type=type_;}
    void set_starting_point(const double& start) {starting_point=start;}
    void set_pos(const double& xPos, const double& yPos)
    {
        x_pos=xPos;
        y_pos=yPos;
    }
    void set_is_move(const bool &isMove) {is_move=isMove;}
    bool get_is_move() const {return is_move;}
    void HandleMove(const int &x_border,const int &y_border);
    void Bullet_Circle (vector<Bullet*> &bullet,SDL_Renderer* screen);
    double get_bullet_x_pos () const {return x_pos;}
    double get_bullet_y_pos () const {return y_pos;}
private:
    double x_pos;
    double y_pos;
    double x_speed;
    double y_speed;
    double angle;
    double starting_point;
    bool is_move;
    int type;
    unsigned long long CurrentTime;
    unsigned long long LastTime;
};
#endif

