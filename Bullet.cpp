#include "Bullet.h"
using namespace std;

Bullet::Bullet()
{
    x_speed=0;
    y_speed=0;
    is_move=false;
    angle=0;
    type=1;
    starting_point=0;
    CurrentTime = 0;
    LastTime = 0;
}

Bullet::~Bullet()
{

}
void Bullet::HandleMove(const int &x_border,const int &y_border)
{
    if(type == 1 )
    {
        x_pos+=x_speed*cos(angle*PI/180);
        y_pos+=(y_speed)*sin(angle*PI/180);
    }
    else if(type == 3)
    {
        x_pos+=x_speed*cos(angle*PI/180);
        y_pos+=(y_speed)*sin(angle*PI/180);
        angle+=30;
    }
    else if(type == 4)
    {
        x_pos+=x_speed*cos(angle*PI/180);
        y_pos+=(y_speed)*sin(angle*PI/180);
    }
    else if (type == 5)
    {
        x_pos-=1;
        y_pos = y_pos + cos(x_pos*PI/200);

    }
    else if (type == 6)
    {
        x_pos-=1;
        y_pos = y_pos + cos(x_pos*PI/200);
    }
    else if(type == 8)
    {
        x_pos += x_speed*cos(angle*PI/180);;
        y_pos += 0.5* sin (angle*PI/180);
    }
    else if( type == 9)
    {
        x_pos += x_speed*sin(angle*PI/180);;
        y_pos += 0.5*cos(angle*PI/180);
    }
    // type này của spaceship
    else if(type == 10)
    {
        x_pos+= 7;
        y_pos-=1;
    }
    else if(type == 11)
    {
        x_pos+= 7;
        y_pos+=1;
    }
    //
     if(y_pos<0 || y_pos>y_border)
    {
        is_move=false;
    }
    if(x_pos<0 || x_pos>x_border)
    {
        is_move=false;
    }
    Rect.x=x_pos;
    Rect.y=y_pos;
}

