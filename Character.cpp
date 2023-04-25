#include "Character.h"
using namespace std;

Character::Character()
{
    frame=0;
    x_pos=0;
    y_pos=0;
    width_frame=0;
    height_frame=0;
    status=Normal;
    input_mouse=0;
    checkbullet=0;
    angle=0;
    CurrentTime=0;
    LastTime=0;
    increase_bullet = false;
    character1 = false;
    character2 = false;
    character3 = false;
    level_1 = false;
    level_2 = false;
    level_3 = false;
    level_4 = false;
    level_5 = false;

    spawn_bullet = false;
}
Character::~Character()
{}

bool Character::LoadTexture(string path, SDL_Renderer* screen)
{
    bool check=Texture::LoadTexture(path,screen);
    if(check==true)
    {
        width_frame=Rect.w;
        height_frame=50;
    }
    return check;
}

void Character::set_clip()
{
    if(width_frame>0 && height_frame>0)
    {
        for(int i=0;i<10;i++)
        {
            frame_clip[i].x=0;
            frame_clip[i].y=0+i*(height_frame);
            frame_clip[i].w=width_frame;
            frame_clip[i].h=50;
        }
    }
}
void Character::Show(SDL_Renderer* destination)
{
    if(status==Normal && character1 == true && character2 == false && character3 == false)
    {
        if(level_1==true) LoadTexture("img//spaceship_1_level_1_animation_1.png",destination);
        else if(level_2 == true) LoadTexture("img//spaceship_1_level_2_animation_1.png",destination);
        else if(level_3 == true) LoadTexture("img//spaceship_1_level_3_animation_1.png",destination);
        else if(level_4 == true) LoadTexture("img//spaceship_1_level_4_animation_1.png",destination);
        else if(level_5 == true) LoadTexture("img//spaceship_1_level_5_animation_1.png",destination);
    }
    else if(status==Normal && character1 == false && character2 == true && character3 == false)
    {
        if(level_1==true) LoadTexture("img//spaceship_2_level_1_animation_2.png",destination);
        else if(level_2 == true) LoadTexture("img//spaceship_2_level_2_animation_2.png",destination);
        else if(level_3 == true) LoadTexture("img//spaceship_2_level_3_animation_2.png",destination);
        else if(level_4 == true) LoadTexture("img//spaceship_2_level_4_animation_2.png",destination);
        else if(level_5 == true) LoadTexture("img//spaceship_2_level_5_animation_2.png",destination);
    }
    else if(status==Normal && character1 == false && character2 == false && character3 == true)
    {
        if(level_1==true) LoadTexture("img//spaceship_3_level_1_animation_2.png",destination);
        else if(level_2 == true) LoadTexture("img//spaceship_3_level_2_animation_2.png",destination);
        else if(level_3 == true) LoadTexture("img//spaceship_3_level_3_animation_2.png",destination);
        else if(level_4 == true) LoadTexture("img//spaceship_3_level_4_animation_2.png",destination);
        else if(level_5 == true) LoadTexture("img//spaceship_3_level_5_animation_2.png",destination);
    }

    if(input_mouse==1)  {frame++;}
    else    {frame=0;}
    if(frame>=10)    {frame=0;}
    Rect.x=x_pos;
    Rect.y=y_pos;
    SDL_Rect* current_clip=&frame_clip[frame];
    SDL_Rect RenderQuad={Rect.x,Rect.y,width_frame,height_frame};
    SDL_RenderCopy(destination,p_texture,current_clip,&RenderQuad);
}

SDL_Rect Character::GetHitBox()
{
    SDL_Rect hit_box;
    hit_box.x=Rect.x + 4*width_frame/16;
    hit_box.y=Rect.y + 4*height_frame/16;
    hit_box.w=8*width_frame/16;
    hit_box.h=8*height_frame/16;
    return hit_box;
}

void Character::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
{
    if(events.type==SDL_MOUSEBUTTONDOWN || events.type==SDL_MOUSEBUTTONUP || events.type==SDL_MOUSEMOTION)
    {
        input_mouse=1;
        int x,y;
        SDL_GetMouseState(&x,&y);
        x_pos=x-width_frame/2;
        y_pos=y-height_frame/2;
    }
    if(events.type==SDL_MOUSEBUTTONDOWN)
    {
        if(events.button.button==SDL_BUTTON_LEFT)
        {
            checkbullet=1;
        }
    }
    else if(events.type == SDL_KEYDOWN)
    {

        switch( events.key.keysym.sym )
                        {
                            case SDLK_SPACE:
                            checkbullet=2;
                            break;


                            case SDLK_ESCAPE:
                            SDL_Quit();
                            break;
                        }
    }
    else if(events.type==SDL_MOUSEBUTTONUP)
    {
        checkbullet=0;
    }
    else if(events.type == SDL_KEYUP)
    {
        checkbullet=0;
    }

}
void Character::SpawnBullet(SDL_Renderer* screen)
{
    CurrentTime=SDL_GetTicks();
    if(character1 == true && character2 == false && character3 == false)
    {
        if(checkbullet!=0 && CurrentTime>LastTime+200)
        {

        if(checkbullet==1 && increase_bullet == 1)
        {
            Bullet* p_bullet_1= new Bullet();
            p_bullet_1->LoadTexture("img/Exhaust_3_2.png",screen);
            p_bullet_1->set_pos(Rect.x+width_frame-15,Rect.y+10-6);
            p_bullet_1->set_x_speed(7);
            p_bullet_1->set_y_speed(7);
            p_bullet_1->set_angle(angle);
            p_bullet_1->set_is_move(true);
            p_bullet_list.push_back(p_bullet_1);
            LastTime=CurrentTime;

            Bullet* p_bullet_2= new Bullet();
            p_bullet_2->LoadTexture("img/Exhaust_3_2.png",screen);
            p_bullet_2->set_pos(Rect.x+width_frame-15,Rect.y+4*10-6);
            p_bullet_2->set_x_speed(7);
            p_bullet_2->set_y_speed(7);
            p_bullet_2->set_angle(angle);
            p_bullet_2->set_is_move(true);
            p_bullet_list.push_back(p_bullet_2);
            LastTime=CurrentTime;
            spawn_bullet = true;
        }
        if(checkbullet == 1 && increase_bullet == 0)
        {
            Bullet* p_bullet_1= new Bullet();
            p_bullet_1->LoadTexture("img/Exhaust_3_2.png",screen);
            p_bullet_1->set_pos(Rect.x+width_frame-15,Rect.y+25-6);
            p_bullet_1->set_x_speed(7);
            p_bullet_1->set_y_speed(7);
            p_bullet_1->set_angle(angle);
            p_bullet_1->set_is_move(true);
            p_bullet_list.push_back(p_bullet_1);
            LastTime=CurrentTime;
            spawn_bullet = true;
        }
        if(checkbullet==1 && increase_bullet == 2)
        {
            Bullet* p_bullet_1= new Bullet();
            p_bullet_1->LoadTexture("img/Exhaust_3_2.png",screen);
            p_bullet_1->set_pos(Rect.x+width_frame-15,Rect.y+25-6);
            p_bullet_1->set_x_speed(7);
            p_bullet_1->set_y_speed(7);
            p_bullet_1->set_angle(angle);
            p_bullet_1->set_is_move(true);
            p_bullet_list.push_back(p_bullet_1);
            LastTime=CurrentTime;

            Bullet* p_bullet_2= new Bullet();
            p_bullet_2->LoadTexture("img/Exhaust_3_2.png",screen);
            p_bullet_2->set_pos(Rect.x+width_frame-15,Rect.y+10-6);
            p_bullet_2->set_x_speed(7);
            p_bullet_2->set_y_speed(7);
            p_bullet_2->set_angle(angle);
            p_bullet_2->set_is_move(true);
            p_bullet_2->set_type(10);
            p_bullet_list.push_back(p_bullet_2);
            LastTime=CurrentTime;

            Bullet* p_bullet_3= new Bullet();
            p_bullet_3->LoadTexture("img/Exhaust_3_2.png",screen);
            p_bullet_3->set_pos(Rect.x+width_frame-15,Rect.y+4*10-6);
            p_bullet_3->set_x_speed(7);
            p_bullet_3->set_y_speed(7);
            p_bullet_3->set_angle(angle);
            p_bullet_3->set_is_move(true);
            p_bullet_3->set_type(11);
            p_bullet_list.push_back(p_bullet_3);
            LastTime=CurrentTime;
            spawn_bullet = true;

        }
    }
            if(checkbullet!=0 && CurrentTime>LastTime+700)
            {
                Bullet* p_bullet= new Bullet();
                if(checkbullet==2)
                {
                    p_bullet->LoadTexture("img/Laser_004.png",screen);
                    p_bullet->set_pos(Rect.x+width_frame,Rect.y);
                    p_bullet->set_x_speed(3);
                    p_bullet->set_y_speed(3);
                    p_bullet->set_angle(angle);
                    p_bullet->set_is_move(true);
                    p_bullet_list.push_back(p_bullet);
                    LastTime=CurrentTime;
                    spawn_bullet = true;
                }

            }
    }
    else if (character1 == false && character2 == true && character3 == false)
    {
        if(checkbullet!=0 && CurrentTime>LastTime+200)
        {

        if(checkbullet==1 && increase_bullet == 1)
        {
            Bullet* p_bullet_1= new Bullet();
            p_bullet_1->LoadTexture("img/Fire_Shot_3_2.png",screen);
            p_bullet_1->set_pos(Rect.x+width_frame-15,Rect.y+10-6);
            p_bullet_1->set_x_speed(7);
            p_bullet_1->set_y_speed(7);
            p_bullet_1->set_angle(angle);
            p_bullet_1->set_is_move(true);
            p_bullet_list.push_back(p_bullet_1);
            LastTime=CurrentTime;

            Bullet* p_bullet_2= new Bullet();
            p_bullet_2->LoadTexture("img/Fire_Shot_3_2.png",screen);
            p_bullet_2->set_pos(Rect.x+width_frame-15,Rect.y+4*10-6);
            p_bullet_2->set_x_speed(7);
            p_bullet_2->set_y_speed(7);
            p_bullet_2->set_angle(angle);
            p_bullet_2->set_is_move(true);
            p_bullet_list.push_back(p_bullet_2);
            LastTime=CurrentTime;
            spawn_bullet = true;
        }
        if(checkbullet == 1 && increase_bullet == 0)
        {
            Bullet* p_bullet_1= new Bullet();
            p_bullet_1->LoadTexture("img/Fire_Shot_3_2.png",screen);
            p_bullet_1->set_pos(Rect.x+width_frame-15,Rect.y+25-6);
            p_bullet_1->set_x_speed(7);
            p_bullet_1->set_y_speed(7);
            p_bullet_1->set_angle(angle);
            p_bullet_1->set_is_move(true);
            p_bullet_list.push_back(p_bullet_1);
            LastTime=CurrentTime;
            spawn_bullet = true;
        }
        if(checkbullet==1 && increase_bullet == 2)
        {
            Bullet* p_bullet_1= new Bullet();
            p_bullet_1->LoadTexture("img/Fire_Shot_3_2.png",screen);
            p_bullet_1->set_pos(Rect.x+width_frame-15,Rect.y+25-6);
            p_bullet_1->set_x_speed(7);
            p_bullet_1->set_y_speed(7);
            p_bullet_1->set_angle(angle);
            p_bullet_1->set_is_move(true);
            p_bullet_list.push_back(p_bullet_1);
            LastTime=CurrentTime;

            Bullet* p_bullet_2= new Bullet();
            p_bullet_2->LoadTexture("img/Fire_Shot_3_2.png",screen);
            p_bullet_2->set_pos(Rect.x+width_frame-15,Rect.y+10-6);
            p_bullet_2->set_x_speed(7);
            p_bullet_2->set_y_speed(7);
            p_bullet_2->set_angle(angle);
            p_bullet_2->set_is_move(true);
            p_bullet_2->set_type(10);
            p_bullet_list.push_back(p_bullet_2);
            LastTime=CurrentTime;

            Bullet* p_bullet_3= new Bullet();
            p_bullet_3->LoadTexture("img/Fire_Shot_3_2.png",screen);
            p_bullet_3->set_pos(Rect.x+width_frame-15,Rect.y+4*10-6);
            p_bullet_3->set_x_speed(7);
            p_bullet_3->set_y_speed(7);
            p_bullet_3->set_angle(angle);
            p_bullet_3->set_is_move(true);
            p_bullet_3->set_type(11);
            p_bullet_list.push_back(p_bullet_3);
            LastTime=CurrentTime;
            spawn_bullet = true;

        }
    }
            if(checkbullet!=0 && CurrentTime>LastTime+700)
            {
                Bullet* p_bullet= new Bullet();
                if(checkbullet==2)
                {
                    p_bullet->LoadTexture("img/Laser_004.png",screen);
                    p_bullet->set_pos(Rect.x+width_frame,Rect.y);
                    p_bullet->set_x_speed(3);
                    p_bullet->set_y_speed(3);
                    p_bullet->set_angle(angle);
                    p_bullet->set_is_move(true);
                    p_bullet_list.push_back(p_bullet);
                    LastTime=CurrentTime;
                    spawn_bullet = true;
                }

            }
    }
    else if(character1 == false && character2 == false && character3 == true)
    {
        if(checkbullet!=0 && CurrentTime>LastTime+200)
        {

        if(checkbullet==1 && increase_bullet == 1)
        {
            Bullet* p_bullet_1= new Bullet();
            p_bullet_1->LoadTexture("img/Explosion_01.png",screen);
            p_bullet_1->set_pos(Rect.x+width_frame-15,Rect.y+10-6);
            p_bullet_1->set_x_speed(7);
            p_bullet_1->set_y_speed(7);
            p_bullet_1->set_angle(angle);
            p_bullet_1->set_is_move(true);
            p_bullet_list.push_back(p_bullet_1);
            LastTime=CurrentTime;

            Bullet* p_bullet_2= new Bullet();
            p_bullet_2->LoadTexture("img/Explosion_01.png",screen);
            p_bullet_2->set_pos(Rect.x+width_frame-15,Rect.y+4*10-6);
            p_bullet_2->set_x_speed(7);
            p_bullet_2->set_y_speed(7);
            p_bullet_2->set_angle(angle);
            p_bullet_2->set_is_move(true);
            p_bullet_list.push_back(p_bullet_2);
            LastTime=CurrentTime;
            spawn_bullet = true;
        }
        if(checkbullet == 1 && increase_bullet == 0)
        {
            Bullet* p_bullet_1= new Bullet();
            p_bullet_1->LoadTexture("img/Explosion_01.png",screen);
            p_bullet_1->set_pos(Rect.x+width_frame-15,Rect.y+25-6);
            p_bullet_1->set_x_speed(7);
            p_bullet_1->set_y_speed(7);
            p_bullet_1->set_angle(angle);
            p_bullet_1->set_is_move(true);
            p_bullet_list.push_back(p_bullet_1);
            LastTime=CurrentTime;
            spawn_bullet = true;
        }
        if(checkbullet==1 && increase_bullet == 2)
        {
            Bullet* p_bullet_1= new Bullet();
            p_bullet_1->LoadTexture("img/Explosion_01.png",screen);
            p_bullet_1->set_pos(Rect.x+width_frame-15,Rect.y+25-6);
            p_bullet_1->set_x_speed(7);
            p_bullet_1->set_y_speed(7);
            p_bullet_1->set_angle(angle);
            p_bullet_1->set_is_move(true);
            p_bullet_list.push_back(p_bullet_1);
            LastTime=CurrentTime;

            Bullet* p_bullet_2= new Bullet();
            p_bullet_2->LoadTexture("img/Explosion_01.png",screen);
            p_bullet_2->set_pos(Rect.x+width_frame-15,Rect.y+10-6);
            p_bullet_2->set_x_speed(7);
            p_bullet_2->set_y_speed(7);
            p_bullet_2->set_angle(angle);
            p_bullet_2->set_is_move(true);
            p_bullet_2->set_type(10);
            p_bullet_list.push_back(p_bullet_2);
            LastTime=CurrentTime;

            Bullet* p_bullet_3= new Bullet();
            p_bullet_3->LoadTexture("img/Explosion_01.png",screen);
            p_bullet_3->set_pos(Rect.x+width_frame-15,Rect.y+4*10-6);
            p_bullet_3->set_x_speed(7);
            p_bullet_3->set_y_speed(7);
            p_bullet_3->set_angle(angle);
            p_bullet_3->set_is_move(true);
            p_bullet_3->set_type(11);
            p_bullet_list.push_back(p_bullet_3);
            LastTime=CurrentTime;
            spawn_bullet = true;

        }
    }
            if(checkbullet!=0 && CurrentTime>LastTime+700)
            {
                Bullet* p_bullet= new Bullet();
                if(checkbullet==2)
                {
                    p_bullet->LoadTexture("img/Laser_004.png",screen);
                    p_bullet->set_pos(Rect.x+width_frame,Rect.y);
                    p_bullet->set_x_speed(3);
                    p_bullet->set_y_speed(3);
                    p_bullet->set_angle(angle);
                    p_bullet->set_is_move(true);
                    p_bullet_list.push_back(p_bullet);
                    LastTime=CurrentTime;
                    spawn_bullet = true;
                }

            }
    }
}
void Character::HandleBullet1(SDL_Renderer* des)
{
    for(int i=0;i<p_bullet_list.size();i++)
    {
        Bullet* p_bullet=p_bullet_list.at(i);
        if(p_bullet!=NULL)
        {
            if(p_bullet->get_is_move()==true)
            {
                p_bullet->HandleMove(SCREEN_WIDTH,SCREEN_HEIGHT);
                p_bullet->Render(des);
            }
            else
            {
                p_bullet_list.erase(p_bullet_list.begin()+i);
                if(p_bullet!=NULL)
                {
                    delete p_bullet;
                    p_bullet=NULL;
                }
            }
        }
    }
}
void Character::RemoveBullet(const int &index)
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
void Character::Reset()
{

    x_pos=0;
    y_pos=SCREEN_HEIGHT/2;
    p_bullet_list.erase(p_bullet_list.begin(),p_bullet_list.begin()+p_bullet_list.size());
}


