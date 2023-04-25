#include "Enemy.h"
using namespace std;

Enemy::Enemy()
{
    x_pos=0;
    y_pos=0;
    x_speed=0;
    y_speed=0;
    x_limit=0;
    width_frame=0;
    height_frame=0;
    Rect.x = SCREEN_WIDTH;
    Rect.y=SCREEN_HEIGHT*0.5;
    Rect.w=Enemy_Width;
    Rect.h=Enemy_Height;
    random_y = 0;
    angle_rotate_speed=0;
    type = 1.5;
    CurrentTime = 0;
    LastTime = 0;

    changespawn=0;
    angle=0;
    angle_cp = 0;
    angle2 =90;
    angle2_cp =90;
    angle3 = 180;
    angle3_cp =180;
    angle4 = 270;
    angle4_cp = 270;
    angle_move=0;
    reverse_direction=0;
    type=0;
    delay_shoot_time = 300;
    delay_shoot_time2 = 300;
    first = 0;
    score = 0;
    die=0;
    frame = 0;
    cnt = 0;
}
Enemy::~Enemy() {}
void Enemy::MoveThreat()
{
   if(type!=9.1 && type != 9.2 && type!= 10.1 && type != 10.2 && type!= 10.3)
   {
       if(x_pos <= x_limit) x_pos = x_limit;
       else
       {
           if(type == 1.1)
           {
            x_pos-= 1;
           }
           else x_pos -= 1;

       }
   }
   else if (type ==9.1 || type ==9.2)
   {
       SDL_Rect Sub_screen;
       Sub_screen.x = 800;
       Sub_screen.y = 0;
       Sub_screen.w = 480;
       Sub_screen.h = 720;
       x_pos += x_speed;
       y_pos += y_speed;
       if(x_pos <= Sub_screen.x || x_pos + width_frame >= Sub_screen.x + Sub_screen.w)
       {
           x_speed*=-1;
       }
       if(y_pos + height_frame>=Sub_screen.h+Sub_screen.y || y_pos <= Sub_screen.y)
       {
           y_speed*=-1;
       }
   }
   else if(type ==10.1 || type == 10.2 || type == 10.3)
   {
       SDL_Rect Sub_screen;
       Sub_screen.x = 640;
       Sub_screen.y = 0;
       Sub_screen.w = 640;
       Sub_screen.h = 720;
       x_pos += x_speed;
       y_pos += y_speed;

       if(x_pos <= Sub_screen.x || x_pos + width_frame >= Sub_screen.x + Sub_screen.w)
       {
           x_speed*=-1;
       }
       if(y_pos + height_frame>=Sub_screen.h+Sub_screen.y || y_pos <= Sub_screen.y)
       {
           y_speed*=-1;
       }
   }
}
 void Enemy::HandleInputAction(SDL_Event events)
 {}
 bool Enemy::LoadTexture(string path, SDL_Renderer* screen)
{
    bool ret=Texture::LoadTexture(path,screen);
    if(ret==true)
    {
        width_frame=Rect.w;
        height_frame=Rect.h;
    }
    return ret;
}
void Enemy::Show(SDL_Renderer* screen)
{
    Rect.x=x_pos;
    Rect.y=y_pos;
    frame_clip[0].x=0;
    frame_clip[0].y=0;
    frame_clip[0].w=width_frame;
    frame_clip[0].h=height_frame;
    SDL_Rect* current_clip=&frame_clip[0];

    SDL_Rect RenderQuad={Rect.x,Rect.y,width_frame,height_frame};
    SDL_RenderCopy(screen,p_texture,current_clip,&RenderQuad);
}
bool Enemy::canspawnbullet()
{
    CurrentTime=SDL_GetTicks();
    bool check_can_spawn=0;
        if(CurrentTime>LastTime+delay_shoot_time)
        {
            LastTime=CurrentTime;
            check_can_spawn=1;
        }
    return check_can_spawn;
}
void Enemy::MakeBulletUponDeath(vector<Bullet*> &bullet,SDL_Renderer* screen)
{
    for(int i=0;i<36;i++)
    {
        Bullet*p_bullet=new Bullet();
        if(type == 9.1 || type == 3.1||type==2.1 || type == 2.2 || type == 9.2|| type == 10.1 || type == 10.2 || type == 10.3)
        {
            p_bullet->LoadTexture("img//Shot_004.png",screen);
            p_bullet->set_is_move(true);
            p_bullet->set_angle(0+10*i);
            p_bullet->set_x_speed(4);
            p_bullet->set_y_speed(4);
            p_bullet->set_pos(x_pos+width_frame/2-(p_bullet->GetRect().w)/2,y_pos+height_frame/2);
            bullet.push_back(p_bullet);
        }
        else if(type == 6.1|| type == 7.1 || type == 8.1)
        {
            p_bullet->LoadTexture("img//Fire_Shot_4_3.png",screen);
            p_bullet->set_is_move(true);
            p_bullet->set_angle(0+10*i);
            p_bullet->set_x_speed(4);
            p_bullet->set_y_speed(4);
            p_bullet->set_pos(x_pos+width_frame/2-(p_bullet->GetRect().w)/2,y_pos+height_frame/2);
            bullet.push_back(p_bullet);
        }
        else if(type == 4.1)
        {
            p_bullet->LoadTexture("img//Explosion_001.png",screen);
            p_bullet->set_is_move(true);
            p_bullet->set_angle(0+10*i);
            p_bullet->set_x_speed(4);
            p_bullet->set_y_speed(4);
            p_bullet->set_pos(x_pos+width_frame/2-(p_bullet->GetRect().w)/2,y_pos+height_frame/2);
            bullet.push_back(p_bullet);
        }
    }
    for(int i = 0 ; i < 36;i++)
    {
        Bullet*p_bullet=new Bullet();
        if(type == 5.1 || type == 1.1)
        {
            p_bullet->LoadTexture("img//Fire_Shot_4_4.png",screen);
            p_bullet->set_is_move(true);
            p_bullet->set_angle(0+10*i);
            p_bullet->set_x_speed(2);
            p_bullet->set_y_speed(2);
            p_bullet->set_pos(x_pos+width_frame/2-(p_bullet->GetRect().w)/2,y_pos+height_frame/2);
            bullet.push_back(p_bullet);
        }
    }
}
void Enemy::rotate_angle()
{
    if(reverse_direction==1)
    {
        angle_rotate_speed=-angle_rotate_speed;
        reverse_direction=0;
    }
    if(angle>=360)
    {
        angle=0;
    }
    angle+=angle_rotate_speed;
}
void Enemy::rotate_angle_cp()
{
    if(reverse_direction==1)
    {
        angle_rotate_speed=-angle_rotate_speed;
        reverse_direction=0;
    }
    if(angle_cp<=-360)
    {
        angle_cp=0;
    }
    angle_cp-=angle_rotate_speed;
}
void Enemy::rotate_angle_2()
{
    if(reverse_direction==1)
    {
        angle_rotate_speed=-angle_rotate_speed;
        reverse_direction=0;
    }
    if(angle2>=450)
    {
        angle2=90;
    }
    angle2+=angle_rotate_speed;
}
void Enemy::rotate_angle_2_cp()
{
    if(reverse_direction==1)
    {
        angle_rotate_speed=-angle_rotate_speed;
        reverse_direction=0;
    }
    if(angle2_cp<=-270)
    {
        angle2_cp=90;
    }
    angle2_cp-=angle_rotate_speed;
}
void Enemy::rotate_angle_3()
{
    if(reverse_direction==1)
    {
        angle_rotate_speed=-angle_rotate_speed;
        reverse_direction=0;
    }
    if(angle3>=540)
    {
        angle3=180;
    }
    angle3+=angle_rotate_speed;
}
void Enemy::rotate_angle_3_cp()
{
    if(reverse_direction==1)
    {
        angle_rotate_speed=-angle_rotate_speed;
        reverse_direction=0;
    }
    if(angle3_cp<=-180)
    {
        angle3_cp=180;
    }
    angle3_cp-=angle_rotate_speed;
}

void Enemy::rotate_angle_4()
{
    if(reverse_direction==1)
    {
        angle_rotate_speed=-angle_rotate_speed;
        reverse_direction=0;
    }
    if(angle4>=630)
    {
        angle4 = 270;
    }
    angle4+=angle_rotate_speed;
}
void Enemy::rotate_angle_4_cp()
{
    if(reverse_direction==1)
    {
        angle_rotate_speed=-angle_rotate_speed;
        reverse_direction=0;
    }
    if(angle4_cp<=-90)
    {
        angle4_cp=270;
    }
    angle4_cp-=angle_rotate_speed;
}
void Enemy::MakeBullet(vector<Bullet*> &bullet,SDL_Renderer* screen,Character &spaceship)
{
    if(type == 1.1)
    {
        delay_shoot_time=10;
        Bullet*p_bullet1=new Bullet();
        p_bullet1->LoadTexture("img//Laser_02.png",screen);
        p_bullet1->set_is_move(true);
        p_bullet1->set_type(4);
        p_bullet1->set_angle(-180);
        p_bullet1->set_x_speed(8);
        p_bullet1->set_y_speed(8);
        p_bullet1->set_pos(x_pos-width_frame/2,y_pos+height_frame/2.45);
        bullet.push_back(p_bullet1);
    }
    else if(type == 2.1)
    {
        for(int i = 0 ; i < 1; i++)
        {
            delay_shoot_time=50;
            Bullet*p_bullet=new Bullet();
            p_bullet->LoadTexture("img//Laser_3_4.png",screen);
            p_bullet->set_type(5);
            p_bullet->set_is_move(true);
            p_bullet -> set_angle(0);
            p_bullet->set_y_speed(3);
            p_bullet->set_x_speed(3);
            p_bullet->set_pos(x_pos,y_pos+24);
            bullet.push_back(p_bullet);
        }
    }
    else if(type == 2.2)
    {
        for(int i = 0 ; i < 1; i++)
        {
            delay_shoot_time=50;
            Bullet*p_bullet=new Bullet();
            p_bullet->LoadTexture("img//Laser_3_4.png",screen);
            p_bullet->set_type(5);
            p_bullet->set_is_move(true);
            p_bullet -> set_angle(0);
            p_bullet->set_y_speed(3);
            p_bullet->set_x_speed(3);
            p_bullet->set_pos(x_pos,y_pos+24);
            bullet.push_back(p_bullet);
        }
    }
    else if(type==3.1)
    {
        delay_shoot_time = 700;
        Bullet*p_bullet = new Bullet();
        p_bullet->LoadTexture("img/Fire_Shot_4_4 - Copy.png",screen);
        p_bullet->set_is_move(true);
        if( spaceship.GetRect().x-x_pos >=0 )
        {
            p_bullet->set_angle(atan((spaceship.GetRect().y-y_pos)/(spaceship.GetRect().x-x_pos))*180/PI);
        }
        else if(spaceship.GetRect().x-x_pos<0)
        {
            p_bullet->set_angle(180+atan((spaceship.GetRect().y-y_pos)/(spaceship.GetRect().x-x_pos))*180/PI);
        }
        p_bullet->set_x_speed(4);
        p_bullet->set_y_speed(4);
        p_bullet->set_pos(x_pos+width_frame/2-(p_bullet->GetRect().w)/2,y_pos+24);
        bullet.push_back(p_bullet);
    }
    else if(type == 4.1)
    {
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet1=new Bullet();
            p_bullet1->LoadTexture("img//Shot_04.png",screen);
            p_bullet1->set_is_move(true);
            p_bullet1->set_type(1);
            p_bullet1->set_angle(10+angle);
            rotate_angle();
            p_bullet1->set_x_speed(2);
            p_bullet1->set_y_speed(2);
            p_bullet1->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet1);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet2=new Bullet();
            p_bullet2->LoadTexture("img//Shot_04.png",screen);
            p_bullet2->set_is_move(true);
            p_bullet2->set_type(1);
            p_bullet2->set_angle(10+angle2);
            rotate_angle_2();
            p_bullet2->set_x_speed(2);
            p_bullet2->set_y_speed(2);
            p_bullet2->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet2);
        }
         for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet3=new Bullet();
            p_bullet3->LoadTexture("img//Shot_04.png",screen);
            p_bullet3->set_is_move(true);
            p_bullet3->set_type(1);
            p_bullet3->set_angle(10+angle3);
            rotate_angle_3();
            p_bullet3->set_x_speed(2);
            p_bullet3->set_y_speed(2);
            p_bullet3->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet3);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet2=new Bullet();
            p_bullet2->LoadTexture("img//Shot_04.png",screen);
            p_bullet2->set_is_move(true);
            p_bullet2->set_type(1);
            p_bullet2->set_angle(10+angle4);
            rotate_angle_4();
            p_bullet2->set_x_speed(2);
            p_bullet2->set_y_speed(2);
            p_bullet2->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet2);
        }

    }
    else if(type==5.1)
    {

            for(int i=0;i<36;i++)
            {
                delay_shoot_time=500;
                Bullet*p_bullet_circle = new Bullet();
                p_bullet_circle->LoadTexture("img//Fire_Shot_4_4 - Copy.png",screen);
                p_bullet_circle->set_is_move(true);
                p_bullet_circle->set_angle(0+10*i);
                p_bullet_circle->set_x_speed(2);
                p_bullet_circle->set_y_speed(2);
                p_bullet_circle->set_pos(x_pos+width_frame/2-(p_bullet_circle->GetRect().w)/2,y_pos+24);
                bullet.push_back(p_bullet_circle);
            }


    }
    else if(type==6.1)
    {
        delay_shoot_time=12;
        Bullet*p_bullet1=new Bullet();
        p_bullet1->LoadTexture("img//BulletThreat6.png",screen);
        p_bullet1->set_is_move(true);
        p_bullet1->set_angle(20+angle);
        rotate_angle();
        p_bullet1->set_x_speed(2.5);
        p_bullet1->set_y_speed(2.5);
        p_bullet1->set_pos(x_pos+width_frame/2-(p_bullet1->GetRect().w)/2,y_pos+24);
        bullet.push_back(p_bullet1);

        Bullet*p_bullet2=new Bullet();
        p_bullet2->LoadTexture("img//BulletThreat5.png",screen);
        p_bullet2->set_is_move(true);
        p_bullet2->set_angle(5+angle);
        rotate_angle();
        p_bullet2->set_x_speed(2.5);
        p_bullet2->set_y_speed(2.5);
        p_bullet2->set_pos(x_pos+width_frame/2-(p_bullet2->GetRect().w)/2,y_pos+24);
        bullet.push_back(p_bullet2);
    }
    else if(type == 7.1)
    {
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet1=new Bullet();
            p_bullet1->LoadTexture("img//Shot_04.png",screen);
            p_bullet1->set_is_move(true);
            p_bullet1->set_type(1);
            p_bullet1->set_angle(10+angle);
            rotate_angle();
            p_bullet1->set_x_speed(2);
            p_bullet1->set_y_speed(2);
            p_bullet1->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet1);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet1_cp=new Bullet();
            p_bullet1_cp->LoadTexture("img//Shot_04.png",screen);
            p_bullet1_cp->set_is_move(true);
            p_bullet1_cp->set_type(1);
            p_bullet1_cp->set_angle(10+angle_cp);
            rotate_angle_cp();
            p_bullet1_cp->set_x_speed(2);
            p_bullet1_cp->set_y_speed(2);
            p_bullet1_cp->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet1_cp);
        }
         for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet3=new Bullet();
            p_bullet3->LoadTexture("img//Shot_04.png",screen);
            p_bullet3->set_is_move(true);
            p_bullet3->set_type(1);
            p_bullet3->set_angle(10+angle3);

            rotate_angle_3();
            p_bullet3->set_x_speed(2);
            p_bullet3->set_y_speed(2);
            p_bullet3->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet3);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet3_cp=new Bullet();
            p_bullet3_cp->LoadTexture("img//Shot_04.png",screen);
            p_bullet3_cp->set_is_move(true);
            p_bullet3_cp->set_type(1);
            p_bullet3_cp->set_angle(10+angle3_cp);
            rotate_angle_3_cp();
            p_bullet3_cp->set_x_speed(2);
            p_bullet3_cp->set_y_speed(2);
            p_bullet3_cp->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet3_cp);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet2=new Bullet();
            p_bullet2->LoadTexture("img//Shot_04.png",screen);
            p_bullet2->set_is_move(true);
            p_bullet2->set_type(1);
            p_bullet2->set_angle(10+angle2);
            rotate_angle_2();
            p_bullet2->set_x_speed(2);
            p_bullet2->set_y_speed(2);
            p_bullet2->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet2);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet2_cp=new Bullet();
            p_bullet2_cp->LoadTexture("img//Shot_04.png",screen);
            p_bullet2_cp->set_is_move(true);
            p_bullet2_cp->set_type(1);
            p_bullet2_cp->set_angle(10+angle2_cp);
            rotate_angle_2_cp();
            p_bullet2_cp->set_x_speed(2);
            p_bullet2_cp->set_y_speed(2);
            p_bullet2_cp->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet2_cp);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet4=new Bullet();
            p_bullet4->LoadTexture("img//Shot_04.png",screen);
            p_bullet4->set_is_move(true);
            p_bullet4->set_type(1);
            p_bullet4->set_angle(10+angle4);
            rotate_angle_4();
            p_bullet4->set_x_speed(2);
            p_bullet4->set_y_speed(2);
            p_bullet4->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet4);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet4_cp=new Bullet();
            p_bullet4_cp->LoadTexture("img//Shot_04.png",screen);
            p_bullet4_cp->set_is_move(true);
            p_bullet4_cp->set_type(1);
            p_bullet4_cp->set_angle(10+angle4_cp);
            rotate_angle_4_cp();
            p_bullet4_cp->set_x_speed(2);
            p_bullet4_cp->set_y_speed(2);
            p_bullet4_cp->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet4_cp);
        }

    }
    else if(type == 8.1)
    {
        for(int i=0;i<6;i++)
        {
            delay_shoot_time=500;
            Bullet*p_bullet=new Bullet();
            p_bullet->LoadTexture("img//Exhaust_2_008.png",screen);
            p_bullet->set_is_move(true);
            //type bullet;
            p_bullet-> set_type(8);
            p_bullet->set_angle(angle + 20*i);
            p_bullet->set_x_speed(2);
            p_bullet->set_y_speed(2);
            p_bullet->set_pos(x_pos+width_frame/2-(p_bullet->GetRect().w)/2,y_pos+24);
            bullet.push_back(p_bullet);
        }
        for(int i=0;i<6;i++)
        {
            delay_shoot_time=500;
            Bullet*p_bullet=new Bullet();
            p_bullet->LoadTexture("img//Exhaust_2_008.png",screen);
            p_bullet->set_is_move(true);
            p_bullet-> set_type(9);
            p_bullet->set_angle(-140 + 20*i);
            p_bullet->set_x_speed(2);
            p_bullet->set_y_speed(2);
            p_bullet->set_pos(x_pos+width_frame/2-(p_bullet->GetRect().w)/2,y_pos+24);
            bullet.push_back(p_bullet);
        }
    }
    else if(type == 9.1)
    {
        /*
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet1=new Bullet();
            p_bullet1->LoadTexture("img//Shot_04.png",screen);
            p_bullet1->set_is_move(true);
            p_bullet1->set_type(1);
            p_bullet1->set_angle(10+angle);
            rotate_angle();
            p_bullet1->set_x_speed(2);
            p_bullet1->set_y_speed(2);
            p_bullet1->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet1);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet1_cp=new Bullet();
            p_bullet1_cp->LoadTexture("img//Shot_04.png",screen);
            p_bullet1_cp->set_is_move(true);
            p_bullet1_cp->set_type(1);
            p_bullet1_cp->set_angle(10+angle_cp);
            rotate_angle_cp();
            p_bullet1_cp->set_x_speed(2);
            p_bullet1_cp->set_y_speed(2);
            p_bullet1_cp->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet1_cp);
        }
         for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet3=new Bullet();
            p_bullet3->LoadTexture("img//Shot_04.png",screen);
            p_bullet3->set_is_move(true);
            p_bullet3->set_type(1);
            p_bullet3->set_angle(10+angle3);

            rotate_angle_3();
            p_bullet3->set_x_speed(2);
            p_bullet3->set_y_speed(2);
            p_bullet3->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet3);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet3_cp=new Bullet();
            p_bullet3_cp->LoadTexture("img//Shot_04.png",screen);
            p_bullet3_cp->set_is_move(true);
            p_bullet3_cp->set_type(1);
            p_bullet3_cp->set_angle(10+angle3_cp);
            rotate_angle_3_cp();
            p_bullet3_cp->set_x_speed(2);
            p_bullet3_cp->set_y_speed(2);
            p_bullet3_cp->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet3_cp);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet2=new Bullet();
            p_bullet2->LoadTexture("img//Shot_04.png",screen);
            p_bullet2->set_is_move(true);
            p_bullet2->set_type(1);
            p_bullet2->set_angle(10+angle2);
            rotate_angle_2();
            p_bullet2->set_x_speed(2);
            p_bullet2->set_y_speed(2);
            p_bullet2->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet2);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet2_cp=new Bullet();
            p_bullet2_cp->LoadTexture("img//Shot_04.png",screen);
            p_bullet2_cp->set_is_move(true);
            p_bullet2_cp->set_type(1);
            p_bullet2_cp->set_angle(10+angle2_cp);
            rotate_angle_2_cp();
            p_bullet2_cp->set_x_speed(2);
            p_bullet2_cp->set_y_speed(2);
            p_bullet2_cp->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet2_cp);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet4=new Bullet();
            p_bullet4->LoadTexture("img//Shot_04.png",screen);
            p_bullet4->set_is_move(true);
            p_bullet4->set_type(1);
            p_bullet4->set_angle(10+angle4);
            rotate_angle_4();
            p_bullet4->set_x_speed(2);
            p_bullet4->set_y_speed(2);
            p_bullet4->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet4);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet4_cp=new Bullet();
            p_bullet4_cp->LoadTexture("img//Shot_04.png",screen);
            p_bullet4_cp->set_is_move(true);
            p_bullet4_cp->set_type(1);
            p_bullet4_cp->set_angle(10+angle4_cp);
            rotate_angle_4_cp();
            p_bullet4_cp->set_x_speed(2);
            p_bullet4_cp->set_y_speed(2);
            p_bullet4_cp->set_pos(x_pos,y_pos+height_frame/2);
            bullet.push_back(p_bullet4_cp);
        }*/
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_1=new Bullet();
            p_bullet_pos_2_1->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_1->set_is_move(true);
            p_bullet_pos_2_1->set_type(1);
            p_bullet_pos_2_1->set_angle(10+angle);
            rotate_angle();
            p_bullet_pos_2_1->set_x_speed(2);
            p_bullet_pos_2_1->set_y_speed(2);
            p_bullet_pos_2_1->set_pos(640,100);
            bullet.push_back(p_bullet_pos_2_1);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_1_cp=new Bullet();
            p_bullet_pos_2_1_cp->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_1_cp->set_is_move(true);
            p_bullet_pos_2_1_cp->set_type(1);
            p_bullet_pos_2_1_cp->set_angle(10+angle_cp);
            rotate_angle_cp();
            p_bullet_pos_2_1_cp->set_x_speed(2);
            p_bullet_pos_2_1_cp->set_y_speed(2);
            p_bullet_pos_2_1_cp->set_pos(640,100);
            bullet.push_back(p_bullet_pos_2_1_cp);
        }
         for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_3=new Bullet();
            p_bullet_pos_2_3->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_3->set_is_move(true);
            p_bullet_pos_2_3->set_type(1);
            p_bullet_pos_2_3->set_angle(10+angle3);

            rotate_angle_3();
            p_bullet_pos_2_3->set_x_speed(2);
            p_bullet_pos_2_3->set_y_speed(2);
            p_bullet_pos_2_3->set_pos(640,100);
            bullet.push_back(p_bullet_pos_2_3);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_3_cp=new Bullet();
            p_bullet_pos_2_3_cp->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_3_cp->set_is_move(true);
            p_bullet_pos_2_3_cp->set_type(1);
            p_bullet_pos_2_3_cp->set_angle(10+angle3_cp);
            rotate_angle_3_cp();
            p_bullet_pos_2_3_cp->set_x_speed(2);
            p_bullet_pos_2_3_cp->set_y_speed(2);
            p_bullet_pos_2_3_cp->set_pos(640,100);
            bullet.push_back(p_bullet_pos_2_3_cp);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_2=new Bullet();
            p_bullet_pos_2_2->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_2->set_is_move(true);
            p_bullet_pos_2_2->set_type(1);
            p_bullet_pos_2_2->set_angle(10+angle2);
            rotate_angle_2();
            p_bullet_pos_2_2->set_x_speed(2);
            p_bullet_pos_2_2->set_y_speed(2);
            p_bullet_pos_2_2->set_pos(640,100);
            bullet.push_back(p_bullet_pos_2_2);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_2_cp=new Bullet();
            p_bullet_pos_2_2_cp->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_2_cp->set_is_move(true);
            p_bullet_pos_2_2_cp->set_type(1);
            p_bullet_pos_2_2_cp->set_angle(10+angle2_cp);
            rotate_angle_2_cp();
            p_bullet_pos_2_2_cp->set_x_speed(2);
            p_bullet_pos_2_2_cp->set_y_speed(2);
            p_bullet_pos_2_2_cp->set_pos(640,100);
            bullet.push_back(p_bullet_pos_2_2_cp);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_4=new Bullet();
            p_bullet_pos_2_4->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_4->set_is_move(true);
            p_bullet_pos_2_4->set_type(1);
            p_bullet_pos_2_4->set_angle(10+angle4);
            rotate_angle_4();
            p_bullet_pos_2_4->set_x_speed(2);
            p_bullet_pos_2_4->set_y_speed(2);
            p_bullet_pos_2_4->set_pos(640,100);
            bullet.push_back(p_bullet_pos_2_4);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_4_cp=new Bullet();
            p_bullet_pos_2_4_cp->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_4_cp->set_is_move(true);
            p_bullet_pos_2_4_cp->set_type(1);
            p_bullet_pos_2_4_cp->set_angle(10+angle4_cp);
            rotate_angle_4_cp();
            p_bullet_pos_2_4_cp->set_x_speed(2);
            p_bullet_pos_2_4_cp->set_y_speed(2);
            p_bullet_pos_2_4_cp->set_pos(640,100);
            bullet.push_back(p_bullet_pos_2_4_cp);
        }

        //
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_1=new Bullet();
            p_bullet_pos_2_1->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_1->set_is_move(true);
            p_bullet_pos_2_1->set_type(1);
            p_bullet_pos_2_1->set_angle(10+angle);
            rotate_angle();
            p_bullet_pos_2_1->set_x_speed(2);
            p_bullet_pos_2_1->set_y_speed(2);
            p_bullet_pos_2_1->set_pos(640,620);
            bullet.push_back(p_bullet_pos_2_1);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_1_cp=new Bullet();
            p_bullet_pos_2_1_cp->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_1_cp->set_is_move(true);
            p_bullet_pos_2_1_cp->set_type(1);
            p_bullet_pos_2_1_cp->set_angle(10+angle_cp);
            rotate_angle_cp();
            p_bullet_pos_2_1_cp->set_x_speed(2);
            p_bullet_pos_2_1_cp->set_y_speed(2);
            p_bullet_pos_2_1_cp->set_pos(640,620);
            bullet.push_back(p_bullet_pos_2_1_cp);
        }
         for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_3=new Bullet();
            p_bullet_pos_2_3->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_3->set_is_move(true);
            p_bullet_pos_2_3->set_type(1);
            p_bullet_pos_2_3->set_angle(10+angle3);

            rotate_angle_3();
            p_bullet_pos_2_3->set_x_speed(2);
            p_bullet_pos_2_3->set_y_speed(2);
            p_bullet_pos_2_3->set_pos(640,620);
            bullet.push_back(p_bullet_pos_2_3);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_3_cp=new Bullet();
            p_bullet_pos_2_3_cp->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_3_cp->set_is_move(true);
            p_bullet_pos_2_3_cp->set_type(1);
            p_bullet_pos_2_3_cp->set_angle(10+angle3_cp);
            rotate_angle_3_cp();
            p_bullet_pos_2_3_cp->set_x_speed(2);
            p_bullet_pos_2_3_cp->set_y_speed(2);
            p_bullet_pos_2_3_cp->set_pos(640,620);
            bullet.push_back(p_bullet_pos_2_3_cp);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_2=new Bullet();
            p_bullet_pos_2_2->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_2->set_is_move(true);
            p_bullet_pos_2_2->set_type(1);
            p_bullet_pos_2_2->set_angle(10+angle2);
            rotate_angle_2();
            p_bullet_pos_2_2->set_x_speed(2);
            p_bullet_pos_2_2->set_y_speed(2);
            p_bullet_pos_2_2->set_pos(640,620);
            bullet.push_back(p_bullet_pos_2_2);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_2_cp=new Bullet();
            p_bullet_pos_2_2_cp->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_2_cp->set_is_move(true);
            p_bullet_pos_2_2_cp->set_type(1);
            p_bullet_pos_2_2_cp->set_angle(10+angle2_cp);
            rotate_angle_2_cp();
            p_bullet_pos_2_2_cp->set_x_speed(2);
            p_bullet_pos_2_2_cp->set_y_speed(2);
            p_bullet_pos_2_2_cp->set_pos(640,620);
            bullet.push_back(p_bullet_pos_2_2_cp);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_4=new Bullet();
            p_bullet_pos_2_4->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_4->set_is_move(true);
            p_bullet_pos_2_4->set_type(1);
            p_bullet_pos_2_4->set_angle(10+angle4);
            rotate_angle_4();
            p_bullet_pos_2_4->set_x_speed(2);
            p_bullet_pos_2_4->set_y_speed(2);
            p_bullet_pos_2_4->set_pos(640,620);
            bullet.push_back(p_bullet_pos_2_4);
        }
        for(int i = 0 ; i < 1;i++)
        {
            delay_shoot_time=50;
            double t = 0;
            Bullet*p_bullet_pos_2_4_cp=new Bullet();
            p_bullet_pos_2_4_cp->LoadTexture("img//BulletThreat5.png",screen);
            p_bullet_pos_2_4_cp->set_is_move(true);
            p_bullet_pos_2_4_cp->set_type(1);
            p_bullet_pos_2_4_cp->set_angle(10+angle4_cp);
            rotate_angle_4_cp();
            p_bullet_pos_2_4_cp->set_x_speed(2);
            p_bullet_pos_2_4_cp->set_y_speed(2);
            p_bullet_pos_2_4_cp->set_pos(640,620);
            bullet.push_back(p_bullet_pos_2_4_cp);
        }
// con ran
       /*
        for(int i = 0 ; i < 1; i++)
        {
            delay_shoot_time=50;
            Bullet*p_bullet_sin_3=new Bullet();
            p_bullet_sin_3->LoadTexture("img//Laser_3_4.png",screen);
            p_bullet_sin_3->set_type(5);
            p_bullet_sin_3->set_is_move(true);
            p_bullet_sin_3-> set_angle(0);
            p_bullet_sin_3->set_y_speed(3);
            p_bullet_sin_3->set_x_speed(3);

            p_bullet_sin_3->set_pos(x_pos,600);
            bullet.push_back(p_bullet_sin_3);
        }
        */
        delay_shoot_time = 200;
    }
    else if(type == 9.2)
    {
        cnt++;
        if(cnt == 10000) cnt = 0;
        if(cnt%10 == 0)
        {
            for(int i=0;i<36;i++)
            {
                delay_shoot_time=100;
                Bullet*p_bullet_circle = new Bullet();
                p_bullet_circle->LoadTexture("img//BulletThreat6.png",screen);
                p_bullet_circle->set_is_move(true);
                p_bullet_circle->set_angle(0+10*i);
                p_bullet_circle->set_x_speed(2);
                p_bullet_circle->set_y_speed(2);
                if(cnt% 20 == 0) p_bullet_circle->set_pos(x_pos+width_frame/2-(p_bullet_circle->GetRect().w)/2,y_pos+24);
                else if(cnt% 30 == 0) p_bullet_circle->set_pos(x_pos+width_frame/2-(p_bullet_circle->GetRect().w)/2,100);
                else p_bullet_circle->set_pos(x_pos+width_frame/2-(p_bullet_circle->GetRect().w)/2,600);
                bullet.push_back(p_bullet_circle);
            }

        }
    }
    else if(type == 10.1)
    {
        cnt++;
        if(cnt == 10000) cnt = 0;
        if(cnt%10 == 0)
        {
            for(int i = 0 ; i < 60; i++)
            {
                Bullet*p_bullet_sin_2=new Bullet();
                p_bullet_sin_2->LoadTexture("img//BulletThreat4.png",screen);
                p_bullet_sin_2->set_type(5);
                p_bullet_sin_2->set_is_move(true);
                p_bullet_sin_2-> set_angle(0);
                p_bullet_sin_2->set_y_speed(3);
                p_bullet_sin_2->set_x_speed(3);

                p_bullet_sin_2->set_pos(x_pos,12*i);
                bullet.push_back(p_bullet_sin_2);
            }
            for(int j = 0; j < 1; j++)
            {
                Bullet*p_bullet=new Bullet();
                p_bullet->LoadTexture("img//Ship_Exhaust.png",screen);
                p_bullet->set_is_move(true);
                p_bullet-> set_angle(180);
                p_bullet->set_y_speed(3);
                p_bullet->set_x_speed(3);

                p_bullet->set_pos(x_pos,y_pos);
                bullet.push_back(p_bullet);
            }
        }

    }
    else if(type == 10.2)
    {
        for(int j = 0; j < 1; j++)
        {
            Bullet*p_bullet=new Bullet();
            p_bullet->LoadTexture("img//Ship_Exhaust.png",screen);
            p_bullet->set_is_move(true);
            p_bullet-> set_angle(180);
            p_bullet->set_y_speed(3);
            p_bullet->set_x_speed(3);

            p_bullet->set_pos(x_pos,y_pos);
            bullet.push_back(p_bullet);
        }

    }
    else if(type == 10.3)
    {
        for(int j = 0; j < 1; j++)
        {
            Bullet*p_bullet=new Bullet();
            p_bullet->LoadTexture("img//Ship_Exhaust.png",screen);
            p_bullet->set_is_move(true);
            p_bullet-> set_angle(180);
            p_bullet->set_y_speed(3);
            p_bullet->set_x_speed(3);
            p_bullet->set_pos(x_pos,y_pos);
            bullet.push_back(p_bullet);
        }
    }
}
void Enemy::set_stats(SDL_Renderer* screen)
{
    if(type == 1.1)
    {
        LoadTexture("img//Boss_Full_01.png",screen);
        x_speed= 2;
        y_speed = 2;
        score=300;
    }
    else if(type == 2.1 || type == 2.2)
    {
        LoadTexture("img//Ship_03.png",screen);
        x_speed = 2;
        score = 1000;
    }
    else if(type == 3.1)
    {
        LoadTexture("img//Damaged_Ship_03.png",screen);
        x_speed= 2;
        y_speed = 2;
        score=600;
    }
    else if(type==4.1)
    {
        LoadTexture("img//Damaged_Ship_04_2.png",screen);
        x_speed=2;
        score=2000;
    }
    else if(type==5.1)
    {
        LoadTexture("img//Ship_04_4.png",screen);
        x_speed = 2;
        y_speed=2;
        score=5000;
    }
    else if(type == 6.1)
    {
        LoadTexture("img//Damaged_Ship_05_2.png",screen);
        x_speed=2;
        score=500;
    }
    else if(type == 7.1)
    {
        LoadTexture("img//Ship_05_threat_7.1.png",screen);
        x_speed = 2;
        score = 1000;
    }
    else if(type == 8.1)
    {
        LoadTexture("img//Ship_06_threat_8.1.png",screen);
        x_speed = 2;
        score = 2000;
    }
    else if(type == 9.1)
    {
        x_speed = 2;
        y_speed = 2;
        LoadTexture("img//threat_map_9.png",screen);
        score = 3000;
    }
    else if(type == 9.2)
    {
        x_speed = 2;
        y_speed = 2;
        LoadTexture("img//Damaged_Ship_03_@.png",screen);
        score = 3000;
    }
    else if(type == 10.1)
    {
        x_speed = 2;
        y_speed = 2;
        LoadTexture("img//Damaged_Ship_01_2.png",screen);
        score = 3000;
    }
    else if(type == 10.2)
    {
        x_speed = 2;
        y_speed = 2;
        LoadTexture("img//Damaged_Ship_02_2.png",screen);
        score = 3000;
    }
    else if(type == 10.3)
    {
        x_speed = 2;
        y_speed = 2;
        LoadTexture("img//Damaged_Ship_06_2.png",screen);
        score = 3000;
    }
}
void Enemy::RemoveBullet(const int &index)
{
    int n=p_bullet_list.size();
    if(n>0 && index<n)
    {
        Bullet*p_bullet=p_bullet_list.at(index);
        p_bullet_list.erase(p_bullet_list.begin()+index);
        if(p_bullet)
        {
            delete p_bullet;
            p_bullet=NULL;
        }
    }
}
bool Enemy::Enemy_die()
{
    if(type==1.1)
    {
        if(die==10) return 1;
    }
    else if(type==2.1 || type == 2.2)
    {
        if(die==20) return 1;
    }
    else if(type==3.1)
    {
        if(die==50) return 1;
    }
    else if(type==4.1)
    {
        if(die==80) return 1;
    }
    else if(type==5.1)
    {
        if(die==100) return 1;
    }
    else if(type == 6.1 || type == 7.1)
    {
        if(die == 100) return 1;
    }
    else if(type == 8.1)
    {
        if(die == 100) return 1;
    }
    else if(type == 9.1 || type == 10.1 || type == 10.2 || type == 10.3 || type == 9.2)
    {
        if(die == 200) return 1;
    }
    // defense warning
    return 0;
}
void Enemy::Health_Icon(vector<Icon*> &health,SDL_Renderer* screen)
{
    Icon *p_health=new Icon();
    p_health->LoadTexture("img//HP_Bonus.png",screen);
    p_health->SetRect(x_pos+p_health->get_frame_width()/2,y_pos+p_health->get_frame_height()/2);
    p_health->set_is_move(true);
    health.push_back(p_health);
}
void Enemy::Rocket_Bonus_Icon(vector<Icon*> &Rocket_Bonus, SDL_Renderer* screen)
{
    Icon *p_rocket=new Icon();
    p_rocket->LoadTexture("img//Rockets_Bonus.png",screen);
    p_rocket->SetRect(x_pos+p_rocket->get_frame_width()/2,y_pos+p_rocket->get_frame_height()/2);
    p_rocket->set_is_move(true);
    Rocket_Bonus.push_back(p_rocket);
}
void Enemy::set_clip()
{
    if(width_frame>0 && height_frame>0)
    {
        for(int i=0;i<8;i++)
        {
            frame_clip[i].x=0;
            frame_clip[i].y=0;
            frame_clip[i].w=87;
            frame_clip[i].h=84;
        }
    }
}
void Enemy::Upgrade_Bonus_Icon(vector<Icon*> &Upgrade_Bonus, SDL_Renderer* screen)
{
    Icon *p_upgrade=new Icon();
    p_upgrade->LoadTexture("img//Upgrade_Bonus.png",screen);
    p_upgrade->SetRect(x_pos+p_upgrade->get_frame_width()/2,y_pos+p_upgrade->get_frame_height()/2);
    p_upgrade->set_is_move(true);
    Upgrade_Bonus.push_back(p_upgrade);
}
