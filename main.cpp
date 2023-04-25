#include "Game_Utils.h"
#include "Texture.h"
#include "Character.h"
#include "Enemy.h"
#include "PlayerPower.h"
#include "TextObjects.h"
#include "Button.h"
#include "Icon.h"

bool game_restarted = false;
bool ranking = false;
bool true_animation_enemy = false;
int generate_health = 0;
int generate_rocket = 0;
// để xem ra đạn 2 hay đạn 3
int spaceship_count_bullet = 0;
int dem_load_anh_exflosion = 0;
string file = "Score.txt";
int dem_level = 1;
using namespace std;
//
Texture Background1;
Texture Background2;
Texture Background3;
Texture Background4;
Texture Background5;
Texture Background6;
Texture Background7;
Texture Background8;
Texture Background9;
Texture Background10;
Texture GameOverUI;
Texture YouWin;
Texture Menu;
Texture Menu_Help_Play;
Texture Ship_Shop;
Texture Menu_help;
Texture Round1;
Texture Round2;
Texture Round3;
Texture Round4;
Texture Round5;
Texture Round6;
Texture Round7;
Texture Round8;
Texture Round9;
Texture Round10;
Texture Pause;
Texture Rating;
Texture Select;
Texture Select_Red;
Texture Selected;
//
Character warPlane;
PlayerPower player_power;
//text
Text CurrentScore;
Text numberofcurrentscore;
Text Score_Rating_1;
Text Score_Rating_2;
Text Score_Rating_3;
Text Score_Rating_4;
//
Button PlayButton;
Button FaceBook;
Button MapButton;
Button ExitButton;
Button CloseButton;
Button BackButton1;
Button ForwardButton1;
Button BackButton2;
Button ForwardButton2;
Button RestartButton;
Button Rating_Higher;
Button ShoppingMall;
Button Menu_Button;
Button ContinuePlay;
Button QR;
Button Back_Button_For_Shop;
Button Select1;
Button Select2;
Button Select3;



//
TTF_Font* general_font=NULL;
TTF_Font* paused_font=NULL;
// Mixer
Mix_Chunk* Underground=NULL;
Mix_Chunk* hit=NULL;
Mix_Chunk* dead = NULL;
Mix_Chunk* Menu_game=NULL;
Mix_Chunk* enemy_die = NULL;
Mix_Chunk* health_collect = NULL;
Mix_Chunk* upgrade_spaceship = NULL;
Mix_Chunk* select_button = NULL;
Mix_Chunk* shot = NULL;
//
int GameOver = 0;
int round_game  = 1;
int Time_LoadRound = 0;
bool ready_enemy = true;
bool no_enemy = true;
bool rating = false;
int cnt = 0;
vector<string> score;
void GenerateEnemy(vector<Enemy*> &Enemy_List,SDL_Renderer* screen,int& round_game)
{

    if(Enemy_List.size()<=0)
    {
        if(round_game == 1)
        {

            int random5 = rand() % ( (SCREEN_HEIGHT -150*3)- 100 + 1) + 100;//random trong khoang min->max
            int k=random5;
            for(int i = 0 ; i < 3; i++)
            {
                Enemy* p_enemy= new Enemy();
                p_enemy->set_type_threat(1.1);
                p_enemy->set_stats(screen);
                p_enemy->set_x_pos(1500);
                if(i==1) p_enemy->set_x_limit(1100);
                else p_enemy->set_x_limit(1000);
                p_enemy->set_y_pos(k);
                k+=150;
                if(i==2) k = 0;
                Enemy_List.push_back(p_enemy);
            }
        }
        if(round_game == 2)
        {
            for(int i=0;i<2;i++)
            {
                Enemy* p_enemy=new Enemy();
                p_enemy->set_type_threat(2.1);
                p_enemy->set_stats(screen);
                if(i == 1) {p_enemy->set_x_pos(1100);p_enemy->set_y_pos(360-85);p_enemy->set_x_limit(1100);}
                if(i == 0) {p_enemy->set_x_pos(1000);p_enemy->set_y_pos(90);p_enemy->set_x_limit(1000);}
                Enemy_List.push_back(p_enemy);
            }
            for(int j=2;j<4;j++)
            {
                Enemy* p_enemy=new Enemy();
                p_enemy->set_type_threat(2.2);
                p_enemy->set_stats(screen);
                p_enemy->set_x_pos(SCREEN_WIDTH);
                if(j == 2) {p_enemy->set_x_pos(1100);p_enemy->set_y_pos(360+80);p_enemy->set_x_limit(1100);}
                if(j == 3) {p_enemy->set_x_pos(1000);p_enemy->set_y_pos(720-150);p_enemy->set_x_limit(1000);}
                Enemy_List.push_back(p_enemy);
            }
        }
        if (round_game == 3)
        {
            for(int i=0;i<5;i++)
            {
                Enemy* p_enemy1=new Enemy();
                p_enemy1->set_type_threat(3.1);
                p_enemy1->set_stats(screen);
                p_enemy1->set_x_pos(SCREEN_WIDTH);
                if(i==0 || i==2 || i==4 ) p_enemy1->set_x_limit(1180);
                else p_enemy1->set_x_limit(1080);
                p_enemy1->set_y_pos(100+(i)*120);
                Enemy_List.push_back(p_enemy1);
            }

        }
        if(round_game == 4)
        {
            for(int i = 0 ; i < 1; i++)
            {
                Enemy* p_enemy= new Enemy();
                p_enemy->set_type_threat(4.1);
                p_enemy->set_stats(screen);
                p_enemy->set_x_pos(800);
                p_enemy->set_x_limit(800);
                //p_enemy->set_angle(0);
                p_enemy->set_angle_rotate_speed(5);
                p_enemy->set_y_pos(360);
                Enemy_List.push_back(p_enemy);
            }
        }
        if(round_game == 5)
        {
           for(int i=0;i<1;i++)
            {
                Enemy* p_enemy= new Enemy();
                p_enemy->set_type_threat(5.1);
                p_enemy->set_stats(screen);
                p_enemy->set_x_pos(800);
                p_enemy->set_x_limit(800);
                p_enemy->set_angle_rotate_speed(5);
                p_enemy->set_y_pos(360);
                Enemy_List.push_back(p_enemy);
            }
        }
        //Enemy2
        if(round_game==6)
        {
            for(int i=0;i<3;i++)
            {
                Enemy* p_enemy= new Enemy();
                p_enemy->set_type_threat(6.1);
                if(i==0)
                {
                    p_enemy->set_angle(0);
                    p_enemy->set_angle_rotate_speed(10);
                }
                else
                {
                    p_enemy->set_angle(180);
                    p_enemy->set_angle_rotate_speed(10);
                }
                p_enemy->set_stats(screen);
                p_enemy->set_x_pos(1500);
                if(i==1) p_enemy->set_x_limit(1100);
                else p_enemy->set_x_limit(1000);
                p_enemy->set_y_pos(100+i*200);
                Enemy_List.push_back(p_enemy);
            }
        }
        if(round_game == 7)
        {
            for(int i = 0 ; i < 1; i++)
            {
                Enemy* p_enemy= new Enemy();
                p_enemy->set_type_threat(7.1);
                p_enemy->set_stats(screen);
                p_enemy->set_x_pos(800);
                p_enemy->set_x_limit(800);
                p_enemy->set_angle_rotate_speed(5);
                p_enemy->set_y_pos(360);
                Enemy_List.push_back(p_enemy);
            }

        }
        if(round_game == 8)
        {
            for(int i = 0 ; i < 2; i++)
            {
                Enemy* p_enemy= new Enemy();
                p_enemy->set_type_threat(8.1);
                p_enemy->set_stats(screen);
                p_enemy->set_x_pos(1180);p_enemy->set_x_limit(1180);
                p_enemy->set_angle(-220);
                p_enemy->set_angle_rotate_speed(5);
                p_enemy->set_y_pos(480*i+120);
                Enemy_List.push_back(p_enemy);
            }

        }
        if(round_game == 10)
        {
            for(int i=0;i<1;i++)
            {
                Enemy* p_enemy= new Enemy();
                p_enemy->set_type_threat(9.1);
                p_enemy->set_stats(screen);
                p_enemy->set_x_pos(1100);
                p_enemy->set_y_pos(360);
                p_enemy->set_angle_rotate_speed(5);
                Enemy_List.push_back(p_enemy);
            }
            for(int j=0;j<1;j++)
            {
                Enemy* p_enemy1= new Enemy();
                p_enemy1->set_type_threat(9.2);
                p_enemy1->set_stats(screen);
                p_enemy1->set_x_pos(1100);
                p_enemy1->set_y_pos(0);
                p_enemy1->set_angle_rotate_speed(5);
                Enemy_List.push_back(p_enemy1);
            }
        }
        if(round_game == 9)
        {
            Enemy* p_enemy1= new Enemy();
            p_enemy1->set_type_threat(10.1);
            p_enemy1->set_stats(screen);
            p_enemy1->set_x_pos(1100);
            p_enemy1->set_y_pos(360);
            p_enemy1->set_angle_rotate_speed(5);
            Enemy_List.push_back(p_enemy1);

            Enemy* p_enemy2= new Enemy();
            p_enemy2->set_type_threat(10.2);
            p_enemy2->set_stats(screen);
            p_enemy2->set_x_pos(780);
            p_enemy2->set_y_pos(240);
            p_enemy2->set_angle_rotate_speed(5);
            Enemy_List.push_back(p_enemy2);

            Enemy* p_enemy3= new Enemy();
            p_enemy3->set_type_threat(10.3);
            p_enemy3->set_stats(screen);
            p_enemy3->set_x_pos(700);
            p_enemy3->set_y_pos(600);
            p_enemy3->set_angle_rotate_speed(5);
            Enemy_List.push_back(p_enemy3);
        }
    }

}
void Collision(vector<Enemy*>&Enemy_List,Character &spaceship,vector<Bullet*> &Bullet_List,Mix_Chunk* hit,SDL_Renderer* screen,long &current_score,bool &GameOver,Mix_Chunk* enemy_die,bool &game_restarted,vector<Icon*> &Health_List,vector<Icon*>&Rocket_List,vector<Icon*> &Upgrade_List)
{
    // Xu li warPlane bi dinhs vao nguoi dich
    for(int i=0;i<Enemy_List.size();i++)
    {
        Enemy *p_enemy=Enemy_List.at(i);
        if(p_enemy!=NULL)
        {
            p_enemy->MoveThreat();
            p_enemy->Show(screen);
            if(p_enemy->canspawnbullet()==1)
            {
                p_enemy->MakeBullet(Bullet_List,screen,spaceship);
            }
            SDL_Rect spaceshipRect=spaceship.GetHitBox();
            if(p_enemy!=NULL)
            {
                SDL_Rect ThreatRect=p_enemy->GetRect();
                bool Threat_to_Spaceship=CheckCollision(spaceshipRect,ThreatRect);
                if(Threat_to_Spaceship==1)
                {
                    GameOver=true;
                }
            }
        }
    }
    // XU LI VA CHAM BULLET ENEMY VA WARPALNE
    for(int i=0;i<Bullet_List.size();i++)
    {
        Bullet*p_bullet=Bullet_List.at(i);
        if(p_bullet!=NULL)
        {
            SDL_Rect BulletRect=p_bullet->GetRect();
            SDL_Rect Main_Rect=spaceship.GetHitBox();

            bool ThreatBullet_to_spaceship=CheckCollision(BulletRect,Main_Rect);
            if(ThreatBullet_to_spaceship)
            {
                Bullet_List.erase(Bullet_List.begin()+i);
                player_power.Decrease();
                Mix_PlayChannel(4,dead,0);

                int m,n;
                SDL_GetMouseState(&m,&n);
                warPlane.set_positions(m-43,n-42);

                //HEALTH
                if(player_power.get_number_()==0)
                {
                        SDL_Delay(2);
                        score[0] = number_to_string(current_score);
                        sort(score.begin(),score.begin()+5);
                        ofstream out(file,ios::trunc);
                        if(out)
                        {
                            for(int i = 1 ; i < score.size();i++)
                            {
                            out << score[i] << endl;
                            }
                        }
                        out.close();
                        GameOver = true;
                }
            }
            if(p_bullet->get_is_move()==true)
            {
                p_bullet->HandleMove(SCREEN_WIDTH,SCREEN_HEIGHT);
                p_bullet->Render(screen);
            }
            else
            {
                Bullet_List.erase(Bullet_List.begin()+i);
                delete p_bullet;
                p_bullet=NULL;
            }
        }
    }
    //
    vector<Bullet*> spaceship_bullet_array=spaceship.get_bullet_list();
    for(int i=0;i<spaceship_bullet_array.size();i++)
    {
        Bullet*p_bullet=spaceship_bullet_array.at(i);
        if(p_bullet!=NULL)
        {
            for(int j=0;j<Enemy_List.size();j++)
            {

                Enemy* p_enemy=Enemy_List.at(j);
                if(p_enemy!=NULL)
                {
                    SDL_Rect ThreatRect;
                    ThreatRect=p_enemy->GetRect();
                    SDL_Rect BulletRect=p_bullet->GetRect();
                    bool SpaceshipBullet_to_Threat=CheckCollision(ThreatRect,BulletRect);
                    if(SpaceshipBullet_to_Threat)
                    {
                        p_enemy->Enemy_die_icr();
                        spaceship.RemoveBullet(i);
                        if(p_enemy->Enemy_die())
                        {
                            if(p_enemy->get_type_threat() == 3.1)
                            {
                                for(int i=0;i<12;i++)
                                {
                                    Bullet*p_bullet=new Bullet();
                                    p_bullet->LoadTexture("img/Laser_01.png",screen);
                                    p_bullet->set_is_move(true);
                                    p_bullet->set_angle(0+30*i);
                                    p_bullet->set_x_speed(2);
                                    p_bullet->set_y_speed(2);
                                    int Size=Bullet_List.size();
                                    p_bullet->set_pos(Bullet_List[0]->get_bullet_x_pos(),Bullet_List[0]->get_bullet_y_pos());
                                    Bullet_List.push_back(p_bullet);
                                }
                            }

                            p_enemy->MakeBulletUponDeath(Bullet_List,screen);
                            generate_health++;
                            if(Enemy_List.size() == 3) {p_enemy->Health_Icon(Health_List,screen);generate_health=-2;}
                            generate_rocket++;
                            if(generate_rocket == 7) {p_enemy->Rocket_Bonus_Icon(Rocket_List,screen);}
                            if(generate_rocket == 14) {p_enemy->Rocket_Bonus_Icon(Rocket_List,screen);}
                            if(Enemy_List.size()==1 && round_game <= 5) {p_enemy->Upgrade_Bonus_Icon(Upgrade_List,screen);}
                            current_score+=(p_enemy->get_score());
                            Enemy_List.erase(Enemy_List.begin()+j);
                            if(Enemy_List.empty() == true)
                            {
                                ready_enemy = false;
                                game_restarted = false;
                            }
                        }
                        if(p_enemy->Enemy_die()==false )Mix_PlayChannel(4,hit,0);
                        else Mix_PlayChannel(4,enemy_die,0);
                    }
                }
            }
        }
    }
    //
    for(int i = 0; i < Health_List.size();i++)
    {
        Icon* p_health = Health_List.at(i);
        if(p_health!=nullptr)
        {
            SDL_Rect Health_Rect = p_health->GetRect();
            SDL_Rect Spaceship_Rect = spaceship.GetHitBox();
            bool Health_to_spaceship = CheckCollision(Health_Rect,Spaceship_Rect);
            if(Health_to_spaceship==true)
            {
                player_power.Increase();
                Mix_PlayChannel(6,health_collect,0);
                Health_List.erase(Health_List.begin()+i);
            }
            if(p_health->get_is_move()==true)
            {
                p_health->MoveEffect(SCREEN_WIDTH,SCREEN_HEIGHT);
                p_health->Render(screen);
            }
            else
            {
                Health_List.erase(Health_List.begin()+i);
                delete p_health;
                p_health=NULL;
            }
        }
    }
    for(int i = 0; i <Rocket_List.size();i++)
    {
        Icon* p_rocket = Rocket_List.at(i);
        if(p_rocket!=nullptr)
        {
            SDL_Rect Rocket_Rect = p_rocket->GetRect();
            SDL_Rect Spaceship_Rect_Rocket = spaceship.GetHitBox();
            bool Rocket_Bonus_to_spaceship = CheckCollision(Spaceship_Rect_Rocket,Rocket_Rect);
            if(Rocket_Bonus_to_spaceship==true)
            {
                if(spaceship_count_bullet == 0) {spaceship.set_check_bullet(1);spaceship_count_bullet++;}
                else if(spaceship_count_bullet == 1) {spaceship.set_check_bullet(2);}
                Mix_PlayChannel(7,health_collect,0);
                Rocket_List.erase(Rocket_List.begin()+i);
            }
            if(p_rocket->get_is_move()==true)
            {
                p_rocket->MoveEffect(SCREEN_WIDTH,SCREEN_HEIGHT);
                p_rocket->Render(screen);
            }
            else
            {
                Rocket_List.erase(Rocket_List.begin()+i);
                delete p_rocket;
                p_rocket = nullptr;
            }

        }
    }
        if(round_game<=5)
        {
            for(int i = 0; i <Upgrade_List.size();i++)
        {
            Icon* p_upgrade = Upgrade_List.at(i);
            if(p_upgrade!=nullptr)
            {
                SDL_Rect upgrade_Rect = p_upgrade->GetRect();
                SDL_Rect Spaceship_Rect_upgrade = spaceship.GetHitBox();
                bool upgrade_Bonus_to_spaceship = CheckCollision(Spaceship_Rect_upgrade,upgrade_Rect);
                if(upgrade_Bonus_to_spaceship==true)
                {
                    if(dem_level<5) dem_level++;
                    if(dem_level == 1) {
                            warPlane.set_level_1(true);
                            warPlane.set_level_2(false);
                            warPlane.set_level_3(false);
                            warPlane.set_level_4(false);
                            warPlane.set_level_5(false);
                    }

                    else if(dem_level == 2) {
                            warPlane.set_level_1(false);
                            warPlane.set_level_2(true);
                            warPlane.set_level_3(false);
                            warPlane.set_level_4(false);
                            warPlane.set_level_5(false);
                    }
                    else if(dem_level == 3) {
                            warPlane.set_level_1(false);
                            warPlane.set_level_2(false);
                            warPlane.set_level_3(true);
                            warPlane.set_level_4(false);
                            warPlane.set_level_5(false);
                    }
                    else if(dem_level == 4) {
                            warPlane.set_level_1(false);
                            warPlane.set_level_2(false);
                            warPlane.set_level_3(false);
                            warPlane.set_level_4(true);
                            warPlane.set_level_5(false);
                    }
                    else if(dem_level == 5) {
                            warPlane.set_level_1(false);
                            warPlane.set_level_2(false);
                            warPlane.set_level_3(false);
                            warPlane.set_level_4(false);
                            warPlane.set_level_5(true);
                    }

                    Mix_PlayChannel(5,upgrade_spaceship,0);
                    Upgrade_List.erase(Upgrade_List.begin()+i);
                }
                if(p_upgrade->get_is_move()==true)
                {
                    p_upgrade->MoveEffect(SCREEN_WIDTH,SCREEN_HEIGHT);
                    p_upgrade->Render(screen);
                }
                else
                {
                    Upgrade_List.erase(Upgrade_List.begin()+i);
                    delete p_upgrade;
                    p_upgrade = nullptr;
                }

            }
        }

    }

    if(Bullet_List.size() == 0 && round_game <= 10 && ready_enemy == false && game_restarted == false)
        {round_game++;Time_LoadRound = 0;ready_enemy = true;
        }
}
bool Init()
{
    bool success=true;
    if(SDL_Init( SDL_INIT_VIDEO ) < 0) success = false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
    g_window=SDL_CreateWindow("War",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(g_window==NULL)
    {
        success=false;
    }
    else
    {
        g_screen=SDL_CreateRenderer(g_window,-1,SDL_RENDERER_ACCELERATED);
        if(g_screen==NULL)
        {
            success=false;
        }
        else
        {
            int imgFlags=IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) && imgFlags))
                success=false;
        }
        if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0)
        {
            success=false;
        }
        if(TTF_Init()==-1)
        {
            success=false;
        }
        general_font=TTF_OpenFont("fonts/vermin_vibes_roundhouse.ttf",40);
        paused_font=TTF_OpenFont("fonts/vermin_vibes_roundhouse.ttf",40);
        if(general_font==NULL || paused_font==NULL)
        {
           success=false;
        }

        Underground=Mix_LoadWAV("musics//hero-80s-127027.mp3");
        hit=Mix_LoadWAV("musics//SE_enemy_vanish.wav");
        dead=Mix_LoadWAV("musics//SE_dead.wav");
        Menu_game=Mix_LoadWAV("musics//Menu_game.mp3");
        enemy_die = Mix_LoadWAV("musics//enemy_die.mp3");
        health_collect = Mix_LoadWAV("musics//health.wav");
        upgrade_spaceship = Mix_LoadWAV("musics//UPGRADE.wav");
        select_button = Mix_LoadWAV("musics//select.wav");
        shot = Mix_LoadWAV("musics//shot2.wav");
        if(hit==NULL || Underground==NULL || dead==NULL || Menu_game==NULL  || enemy_die == NULL || health_collect==NULL || upgrade_spaceship==NULL || select_button == NULL || shot==NULL)
        {
            success=false;
        }
    }
    return success;
}
void close()
{
    Background1.Free();
    Background2.Free();
    Background3.Free();
    Background4.Free();
    Background5.Free();Background6.Free();
    Background7.Free();
    Background8.Free();
    Background9.Free();
    Background10.Free();
    YouWin.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen=NULL;
    SDL_DestroyWindow(g_window);
    g_window=NULL;
    Mix_FreeChunk(hit);
    hit=NULL;
    Mix_FreeChunk(Underground);
    Underground = nullptr;
    Mix_FreeChunk(enemy_die);
    enemy_die = NULL;
    Mix_FreeChunk(dead);
    dead = NULL;
    Mix_FreeChunk(Menu_game);
    Menu_game = NULL;
    Mix_FreeChunk(health_collect);
    health_collect = nullptr;
    Mix_FreeChunk(upgrade_spaceship);
    upgrade_spaceship=NULL;
    Mix_FreeChunk(select_button);
    select_button=NULL;
    Mix_FreeChunk(shot);
    shot=NULL;
    Menu.Free();
    Round1.Free();
    Round2.Free();
    Round3.Free();
    Round4.Free();
    Round5.Free();
    Round6.Free();
    Round7.Free();
    Round8.Free();
    Round9.Free();
    Round10.Free();
    Menu_help.Free();
    Menu_Help_Play.Free();
    GameOverUI.Free();
    Pause.Free();
    Rating.Free();
    Ship_Shop.Free();
    Select.Free();
    Selected.Free();
    Select_Red.Free();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

int main(int argc,char* argv[])
{
    loop:
    if(Init()==false)
    {
        cout << "Khong khoi tao duoc INIT" << endl;
        return 0;
    }
    long current_score=0;

    //
    Menu.LoadTexture("img//menu.png",g_screen);
    Pause.LoadTexture("img//pause_game.png",g_screen);
    Rating.LoadTexture("",g_screen);
    Menu_help.LoadTexture("img//Menu_help.png",g_screen);
    Menu_Help_Play.LoadTexture("img//Menu_Help_Play.png",g_screen);
    GameOverUI.LoadTexture("img//game_over.png",g_screen);
    YouWin.LoadTexture("img//YouWin.png",g_screen);
    Ship_Shop.LoadTexture("img//Ship_Shop.png",g_screen);
    Select.LoadTexture("img//select.png",g_screen);
    Selected.LoadTexture("img//selected.png",g_screen);
    Select_Red.LoadTexture("img//select_Red.png",g_screen);
    //
    Round1.LoadTexture("img/1.png",g_screen);
    Round2.LoadTexture("img/2.png",g_screen);
    Round3.LoadTexture("img/3.png",g_screen);
    Round4.LoadTexture("img/4.png",g_screen);
    Round5.LoadTexture("img/5.png",g_screen);
    Round6.LoadTexture("img/6.png",g_screen);
    Round7.LoadTexture("img/7.png",g_screen);
    Round8.LoadTexture("img/8.png",g_screen);
    Round9.LoadTexture("img/9.png",g_screen);
    Round10.LoadTexture("img/10.png",g_screen);
    Background1.LoadTexture("img/map_round_1.png",g_screen);
    Background2.LoadTexture("img/map_round_2.png",g_screen);
    Background3.LoadTexture("img/map_round_3.png",g_screen);
    Background4.LoadTexture("img/map_round_4.png",g_screen);
    Background5.LoadTexture("img/map_round_5.png",g_screen);
    Background6.LoadTexture("img/map_round_6.png",g_screen);
    Background7.LoadTexture("img/map_round_7.png",g_screen);
    Background8.LoadTexture("img/map_round_8.png",g_screen);
    Background9.LoadTexture("img/map_round_1.png",g_screen);
    Background10.LoadTexture("img/map_round_10.png",g_screen);
    vector<Bullet*> Bullet_List;
    vector<Enemy*> Enemy_List;
    vector<Icon*> Health_List;
    vector<Icon*> Rocket_List;
    vector<Icon*> Upgrade_List;
    CurrentScore.SetColor(Text::RED_TEXT);
    string str_currentscore="SCORE:";
    CurrentScore.Set_Text(str_currentscore);
    CurrentScore.LoadFromRenderText(general_font,g_screen);
    numberofcurrentscore.SetColor(Text::WHITE_TEXT);
    Score_Rating_1.SetColor(Text::WHITE_TEXT);
    Score_Rating_2.SetColor(Text::WHITE_TEXT);
    Score_Rating_3.SetColor(Text::WHITE_TEXT);
    Score_Rating_4.SetColor(Text::WHITE_TEXT);
    // delay
    //int delay_enemy = 0;
    //
    Mix_VolumeChunk(hit,MIX_MAX_VOLUME/5);
    Mix_VolumeChunk(Underground,MIX_MAX_VOLUME/10);
    Mix_VolumeChunk(Menu_game,MIX_MAX_VOLUME/10);
    Mix_VolumeChunk(dead,MIX_MAX_VOLUME/5);
    Mix_VolumeChunk(enemy_die,MIX_MAX_VOLUME);
    Mix_VolumeChunk(health_collect,MIX_MAX_VOLUME/5);
    Mix_VolumeChunk(upgrade_spaceship,MIX_MAX_VOLUME/5);
    Mix_VolumeChunk(select_button,MIX_MAX_VOLUME/8);
    Mix_VolumeChunk(shot,MIX_MAX_VOLUME/5);
    //
    bool play=false;
    bool menu=true;
    bool help=false;
    bool help2 = false;
    bool QuitMenu=false;
    bool shop = false;
    bool shop_button_1 = true;
    bool shop_button_2 = false;
    bool shop_button_3 = false;
    //TXT
    score.push_back("000000");
    ifstream in(file);
    if(in)
    {
        while(!in.eof()){
            string s;
            getline(in>>ws,s);
            score.push_back(s);
        }
    }
    sort(score.begin(),score.begin()+4);

    SDL_WarpMouseInWindow(g_window,SCREEN_WIDTH/2-32,SCREEN_HEIGHT-100);
    bool paused=false;
    bool GameOver=false;
    player_power.initdata(g_screen);

    while(!QuitMenu)
    {

        if(!Mix_Playing(1))
        {
            Mix_PlayChannel(1,Menu_game,-1);
        }
        if(menu)
        {
            while(SDL_PollEvent(&g_event)!=0)
            {
                if(g_event.type==SDL_QUIT)
                {
                    QuitMenu=true;

                }
                PlayButton.HandlePlayButton(g_event,g_screen,menu,play,QuitMenu);
                if(PlayButton.get_sound()==true) {Mix_PlayChannel(4,select_button,0);PlayButton.set_sound(false);}

                MapButton.HandleMapButton(g_event,g_screen,menu,help);
                if(MapButton.get_sound()==true) {Mix_PlayChannel(4,select_button,0);MapButton.set_sound(false);}
                ExitButton.HandleExitButton(g_event,g_screen,QuitMenu);
                if(ExitButton.get_sound()==true) {Mix_PlayChannel(4,select_button,0);ExitButton.set_sound(false);}
                FaceBook.HandleFaceBook(g_event,g_screen,menu);
                if(FaceBook.get_sound()==true) {Mix_PlayChannel(4,select_button,0);FaceBook.set_sound(false);}
                Rating_Higher.HandleRatingButton(g_event,g_screen);
                if(Rating_Higher.get_sound()==true) {Mix_PlayChannel(4,select_button,0);Rating_Higher.set_sound(false);}
                ShoppingMall.HandleShoppingButton(g_event,g_screen,menu,help,help2,shop);
                if(ShoppingMall.get_sound()==true) {Mix_PlayChannel(4,select_button,0);ShoppingMall.set_sound(false);}

            }
            PlayButton.SetRect(SCREEN_WIDTH/2-PlayButton.get_frame_width()/2-200,SCREEN_HEIGHT/2+30);
            MapButton.SetRect(SCREEN_WIDTH/2-PlayButton.get_frame_width()/2 + 200 ,SCREEN_HEIGHT/2+30);
            ExitButton.SetRect(SCREEN_WIDTH/2-PlayButton.get_frame_width()/2,SCREEN_HEIGHT/2+150);
            FaceBook.SetRect(SCREEN_WIDTH/2-PlayButton.get_frame_width()/2 + 70,SCREEN_HEIGHT/2+280);
            ShoppingMall.SetRect(SCREEN_WIDTH/2-PlayButton.get_frame_width()/2 + 210,SCREEN_HEIGHT/2+280);
            if(Rating_Higher.get_rating_higher()==true) {
                Rating_Higher.SetRect(SCREEN_WIDTH/3,100);
                Score_Rating_1.Set_Text(score[4]);
                Score_Rating_1.LoadFromRenderText(paused_font,g_screen);
                Score_Rating_1.RenderText(g_screen,SCREEN_WIDTH/2-100,SCREEN_HEIGHT/2+50);
                Score_Rating_2.Set_Text(score[3]);
                Score_Rating_2.LoadFromRenderText(paused_font,g_screen);
                Score_Rating_2.RenderText(g_screen,SCREEN_WIDTH/2-100,SCREEN_HEIGHT/2+100);
                Score_Rating_3.Set_Text(score[2]);
                Score_Rating_3.LoadFromRenderText(paused_font,g_screen);
                Score_Rating_3.RenderText(g_screen,SCREEN_WIDTH/2-100,SCREEN_HEIGHT/2+150);
                Score_Rating_4.Set_Text(score[1]);
                Score_Rating_4.LoadFromRenderText(paused_font,g_screen);
                Score_Rating_4.RenderText(g_screen,SCREEN_WIDTH/2-100,SCREEN_HEIGHT/2+200);
                ranking = true;
            }
            else
            {Rating_Higher.SetRect(SCREEN_WIDTH/2-PlayButton.get_frame_width()/2 + 140,SCREEN_HEIGHT/2+280);ranking = false;}
            Menu.Render(g_screen);
            MapButton.Render(g_screen);
            PlayButton.Render(g_screen);
            ExitButton.Render(g_screen);
            FaceBook.Render(g_screen);
            Rating_Higher.Render(g_screen);
            ShoppingMall.Render(g_screen);

            if(ranking==true)
            {
                Score_Rating_1.RenderText(g_screen,SCREEN_WIDTH/2-100,SCREEN_HEIGHT/2-175);
                Score_Rating_2.RenderText(g_screen,SCREEN_WIDTH/2-100,SCREEN_HEIGHT/2-95);
                Score_Rating_3.RenderText(g_screen,SCREEN_WIDTH/2-100,SCREEN_HEIGHT/2-5);
                Score_Rating_4.RenderText(g_screen,SCREEN_WIDTH/2-100,SCREEN_HEIGHT/2+75);
            }
            SDL_RenderPresent(g_screen);
        }
        if(help==true)
        {
            shop = false;
            while(SDL_PollEvent(&g_event)!=0)
            {
                if(g_event.type==SDL_QUIT)
                {
                    QuitMenu=true;
                }
                BackButton1.HandleBackButton(g_event,g_screen,menu,help,help2);
                if(BackButton1.get_sound()==true) {Mix_PlayChannel(4,select_button,0);BackButton1.set_sound(false);}
                ForwardButton1.HandleForwardButton(g_event,g_screen,menu,help,help2);
                if(ForwardButton1.get_sound()==true) {Mix_PlayChannel(4,select_button,0);ForwardButton1.set_sound(false);}

            }
            Menu_help.Render(g_screen);
            BackButton1.SetRect(30,SCREEN_HEIGHT-BackButton1.get_frame_height()-30);
            BackButton1.Render(g_screen);
            ForwardButton1.SetRect(1180,SCREEN_HEIGHT-BackButton1.get_frame_height()-30);
            ForwardButton1.Render(g_screen);
            SDL_RenderPresent(g_screen);
        }
        if(help2 == true)
        {
            shop = false;
            while(SDL_PollEvent(&g_event)!=0)
            {
                if(g_event.type==SDL_QUIT)
                {
                    QuitMenu=true;
                }
                BackButton2.HandleBackButton2(g_event,g_screen,menu,help,help2);
                if(BackButton2.get_sound()==true) {Mix_PlayChannel(4,select_button,0);BackButton2.set_sound(false);}
                ForwardButton2.HandleForwardButton2(g_event,g_screen,menu,help,help2);
                if(ForwardButton2.get_sound()==true) {Mix_PlayChannel(4,select_button,0);ForwardButton2.set_sound(false);}
            }
            Menu_Help_Play.Render(g_screen);
            BackButton2.SetRect(30,SCREEN_HEIGHT-BackButton2.get_frame_height()-30);
            BackButton2.Render(g_screen);
            ForwardButton2.SetRect(1180,SCREEN_HEIGHT-BackButton2.get_frame_height()-30);
            ForwardButton2.Render(g_screen);
            SDL_RenderPresent(g_screen);
        }
        if(shop)
        {
            while(SDL_PollEvent(&g_event)!=0)
            {
                if(g_event.type==SDL_QUIT)
                {
                    QuitMenu=true;
                }


                Back_Button_For_Shop.HandleBackButtonForShop(g_event,g_screen,menu,help,help2,shop);
                if(Back_Button_For_Shop.get_sound()==true) {Mix_PlayChannel(4,select_button,0);Back_Button_For_Shop.set_sound(false);}
                //ForwardButton2.HandleForwardButton2(g_event,g_screen,menu,help,help2);
                Select1.HandleSelect1(g_event,g_screen,menu,help,help2,shop,shop_button_1,shop_button_2,shop_button_3);
                if(Select1.get_sound()==true) {Mix_PlayChannel(4,select_button,0);Select1.set_sound(false);}
                Select2.HandleSelect2(g_event,g_screen,menu,help,help2,shop,shop_button_1,shop_button_2,shop_button_3);
                if(Select2.get_sound()==true) {Mix_PlayChannel(4,select_button,0);Select2.set_sound(false);}
                Select3.HandleSelect3(g_event,g_screen,menu,help,help2,shop,shop_button_1,shop_button_2,shop_button_3);
                if(Select3.get_sound()==true) {Mix_PlayChannel(4,select_button,0);Select3.set_sound(false);}
            }
            Ship_Shop.SetRect(SCREEN_WIDTH/3,100);
            Ship_Shop.Render(g_screen);
            Back_Button_For_Shop.SetRect(SCREEN_WIDTH/3 + 30,100+500-80);
            Back_Button_For_Shop.Render(g_screen);
            //ForwardButton2.SetRect(1180,SCREEN_HEIGHT-BackButton2.get_frame_height()-30);
           // ForwardButton2.Render(g_screen);
            Select1.SetRect(602,192);
            Select1.Render(g_screen);
            Select2.SetRect(602,292);
            Select2.Render(g_screen);
            Select3.SetRect(602,392);
            Select3.Render(g_screen);
            SDL_RenderPresent(g_screen);
        }
    }

    while(play)
        {

                Mix_HaltChannel(1);
                if(!Mix_Playing(2))
                {
                    Mix_PlayChannel(2,Underground,-1);
                }
                if(!GameOver)
                {
                    if(shop_button_1==true && shop_button_2==false &&shop_button_3==false)
                {
                    if(dem_level==1) warPlane.LoadTexture("img//spaceship_1_level_1_animation_1.png",g_screen);
                    else if(dem_level==2) warPlane.LoadTexture("img//spaceship_1_level_2_animation_1.png",g_screen);
                    else if(dem_level==3) warPlane.LoadTexture("img//spaceship_1_level_3_animation_1.png",g_screen);
                    else if(dem_level==4) warPlane.LoadTexture("img//spaceship_1_level_4_animation_1.png",g_screen);
                    else if(dem_level==5) warPlane.LoadTexture("img//spaceship_1_level_5_animation_1.png",g_screen);
                    warPlane.set_character1(true);
                    warPlane.set_character2(false);
                    warPlane.set_character3(false);
                }
                else if(shop_button_1==false && shop_button_2==true && shop_button_3==false)
                {
                    if(dem_level==1) warPlane.LoadTexture("img//spaceship_2_level_1_animation_2.png",g_screen);
                    else if(dem_level==2) warPlane.LoadTexture("img//spaceship_2_level_2_animation_2.png",g_screen);
                    else if(dem_level==3) warPlane.LoadTexture("img//spaceship_2_level_3_animation_2.png",g_screen);
                    else if(dem_level==4) warPlane.LoadTexture("img//spaceship_2_level_4_animation_2.png",g_screen);
                    else if(dem_level==5) warPlane.LoadTexture("img//spaceship_2_level_5_animation_2.png",g_screen);
                    warPlane.set_character1(false);
                    warPlane.set_character2(true);
                    warPlane.set_character3(false);
                }
                else if(shop_button_1==false && shop_button_2==false && shop_button_3==true)
                {
                    if(dem_level==1) warPlane.LoadTexture("img//spaceship_3_level_1_animation_2.png",g_screen);
                    else if(dem_level==2) warPlane.LoadTexture("img//spaceship_3_level_2_animation_2.png",g_screen);
                    else if(dem_level==3) warPlane.LoadTexture("img//spaceship_3_level_3_animation_2.png",g_screen);
                    else if(dem_level==4) warPlane.LoadTexture("img//spaceship_3_level_4_animation_2.png",g_screen);
                    else if(dem_level==5) warPlane.LoadTexture("img//spaceship_3_level_5_animation_2.png",g_screen);
                    warPlane.set_character1(false);
                    warPlane.set_character2(false);
                    warPlane.set_character3(true);

                }

                warPlane.set_clip();
                    if(game_restarted==true && cnt ==0)
                    {player_power.initdata(g_screen);player_power.ShowHeart(g_screen);cnt++;}
                    if(paused)
                    {
                        round_game = 1;
                        dem_level = 1;
                        warPlane.set_level_1(true);
                        warPlane.set_level_2(false);
                        warPlane.set_level_3(false);
                        warPlane.set_level_4(false);
                        warPlane.set_level_5(false);
                        SDL_ShowCursor(SDL_ENABLE);
                        SDL_ShowCursor(SDL_ENABLE);
                        while(SDL_PollEvent(&g_event)!=0)
                        {
                            if(g_event.type==SDL_QUIT)
                            {
                                play=false;
                            }
                            if(g_event.type==SDL_KEYDOWN)
                            {
                                if(g_event.key.keysym.sym==SDLK_p)
                                {
                                    paused=false;
                                }
                                if(g_event.key.keysym.sym==SDLK_ESCAPE)
                                {
                                    play=false;
                                }
                            }
                        RestartButton.HandleRestartButton(g_event,g_screen,Enemy_List,warPlane,Bullet_List,current_score,GameOver,round_game,paused,dem_level);
                        if(RestartButton.get_sound()==true) {Mix_PlayChannel(4,select_button,0);RestartButton.set_sound(false);}
                        if(RestartButton.get_restart_game() == true) {
                        game_restarted = true;RestartButton.set_restart_game_value(false);Time_LoadRound = 0;ready_enemy = true;cnt = 0;
                        player_power.Reset();
                        Health_List.clear();
                        Upgrade_List.clear();
                        Rocket_List.clear();
                        generate_health = 0;
                        generate_rocket = 0;
                        warPlane.set_check_bullet(0);
                        spaceship_count_bullet = 0;
                        player_power.set_beta(180);
                        }
                            CloseButton.HandleCloseBTN(g_event,g_screen,QuitMenu,play);
                            if(CloseButton.get_sound()==true) {Mix_PlayChannel(4,select_button,0);CloseButton.set_sound(false);}
                            Menu_Button.HandleBackMenuButton(g_event,g_screen,QuitMenu,play);
                            if(Menu_Button.get_sound()==true) {Mix_PlayChannel(4,select_button,0);Menu_Button.set_sound(false);}
                            if(Menu_Button.get_backmenu() == true)
                            {
                            Background1.Free();
                            Background2.Free();
                            Background3.Free();
                            Background4.Free();
                            Background5.Free();Background6.Free();
                            Background7.Free();
                            Background8.Free();
                            Background9.Free();
                            Background10.Free();

                            SDL_DestroyRenderer(g_screen);
                            g_screen=NULL;
                            SDL_DestroyWindow(g_window);
                            g_window=NULL;
                            Mix_FreeChunk(upgrade_spaceship);
                            upgrade_spaceship=NULL;
                            Mix_FreeChunk(hit);
                            hit=NULL;
                            Mix_FreeChunk(Underground);
                            Underground = nullptr;
                            Mix_FreeChunk(enemy_die);
                            enemy_die = NULL;
                            Mix_FreeChunk(dead);
                            dead = NULL;
                            Mix_FreeChunk(Menu_game);
                            Menu_game = NULL;
                            Mix_FreeChunk(health_collect);
                            health_collect = NULL;
                            Mix_FreeChunk(select_button);
                            select_button=NULL;
                            Mix_FreeChunk(shot);
                            shot=NULL;
                            Menu_help.Free();
                            Menu.Free();
                            Round1.Free();
                            Round2.Free();
                            Round3.Free();
                            Round4.Free();
                            Round5.Free();
                            Round6.Free();
                            Round7.Free();
                            Round8.Free();
                            Round9.Free();
                            Round10.Free();
                            Ship_Shop.Free();
                            Select1.Free();
                            Select2.Free();
                            Select3.Free();
                            Selected.Free();
                            GameOverUI.Free();
                            Pause.Free();
                            Rating.Free();
                            Menu_Button.set_backmenu(false);
                            goto loop;

                        }
                            ContinuePlay.HandleContinuePlayGameButton(g_event,g_screen,paused);
                            if(ContinuePlay.get_sound()==true) {Mix_PlayChannel(4,select_button,0);ContinuePlay.set_sound(false);}
                        }

                         Pause.SetRect(SCREEN_WIDTH/3,100);
                         Pause.Render(g_screen);
                         RestartButton.SetRect(SCREEN_WIDTH/3+80,250);
                         RestartButton.Render(g_screen);
                         CloseButton.SetRect(SCREEN_WIDTH/3+80,350);
                         CloseButton.Render(g_screen);
                         Menu_Button.SetRect(SCREEN_WIDTH/3+260,250);
                         Menu_Button.Render(g_screen);
                         ContinuePlay.SetRect(SCREEN_WIDTH/3+260,350);
                         ContinuePlay.Render(g_screen);
                         numberofcurrentscore.Set_Text(number_to_string(current_score));
                         numberofcurrentscore.LoadFromRenderText(paused_font,g_screen);
                         numberofcurrentscore.RenderText(g_screen,SCREEN_WIDTH/2-100,SCREEN_HEIGHT/2+150);
                         SDL_RenderPresent(g_screen);
                    }
                    if(!Mix_Playing(2))
                    {
                        Mix_PlayChannel(2,Underground,-1);
                    }

                    if(!paused)
                    {

                        while (SDL_PollEvent(&g_event)!=0)
                        {
                            if(g_event.type==SDL_QUIT)
                            {
                                play=false;
                            }
                            if(g_event.type==SDL_KEYDOWN)
                            {
                                if(g_event.key.keysym.sym==SDLK_p)
                                {
                                    paused=true;

                                }
                                if(g_event.key.keysym.sym==SDLK_ESCAPE)
                                {
                                    play=false;
                                }
                            }
                            warPlane.HandleInputAction(g_event,g_screen);
                        }
                        if(Time_LoadRound <=1) {SDL_RenderClear(g_screen);
                        if(round_game==1) Round1.Render(g_screen);
                        else if(round_game==2) Round2.Render(g_screen);
                        else if(round_game==3) Round3.Render(g_screen);
                        else if(round_game==4) Round4.Render(g_screen);
                        else if(round_game==5) Round5.Render(g_screen);
                        else if(round_game==6) Round6.Render(g_screen);
                        else if(round_game==7) Round7.Render(g_screen);
                        else if(round_game==8) Round8.Render(g_screen);
                        else if(round_game==9) Round9.Render(g_screen);
                        else if(round_game==10) Round10.Render(g_screen);
                        Time_LoadRound++;SDL_ShowCursor(SDL_DISABLE);
                        SDL_RenderPresent(g_screen);SDL_Delay(1500);}
                        else
                        {
                            SDL_RenderClear(g_screen);

                            if(round_game == 1)
                            {
                                Background1.Render(g_screen);
                                SDL_ShowCursor(SDL_DISABLE);
                                Background1.MoveBackGround(g_screen,NULL);
                            }
                            else if(round_game == 2)
                            {
                                Background2.Render(g_screen);
                                SDL_ShowCursor(SDL_DISABLE);
                                Background2.MoveBackGround(g_screen,NULL);
                            }
                            else if(round_game == 3)
                            {
                                Background3.Render(g_screen);
                                SDL_ShowCursor(SDL_DISABLE);
                                Background3.MoveBackGround(g_screen,NULL);
                            }
                            else if(round_game == 4)
                            {
                                Background4.Render(g_screen);
                                SDL_ShowCursor(SDL_DISABLE);
                                Background4.MoveBackGround(g_screen,NULL);
                            }
                            else if(round_game == 5)
                            {
                                Background5.Render(g_screen);
                                SDL_ShowCursor(SDL_DISABLE);
                                Background5.MoveBackGround(g_screen,NULL);
                            }
                            else if(round_game == 6)
                            {
                                Background6.Render(g_screen);
                                SDL_ShowCursor(SDL_DISABLE);
                                Background6.MoveBackGround(g_screen,NULL);
                            }
                            else if(round_game == 7)
                            {
                                Background7.Render(g_screen);
                                SDL_ShowCursor(SDL_DISABLE);
                                Background7.MoveBackGround(g_screen,NULL);
                            }
                             else if(round_game == 8)
                            {
                                Background8.Render(g_screen);
                                SDL_ShowCursor(SDL_DISABLE);
                                Background8.MoveBackGround(g_screen,NULL);
                            }
                             else if(round_game == 9)
                            {
                                Background9.Render(g_screen);
                                SDL_ShowCursor(SDL_DISABLE);
                                Background9.MoveBackGround(g_screen,NULL);
                            }
                             else if(round_game == 10)
                            {
                                Background10.Render(g_screen);
                                SDL_ShowCursor(SDL_DISABLE);
                                Background10.MoveBackGround(g_screen,NULL);
                            }
                            if(ready_enemy == true)
                            {GenerateEnemy(Enemy_List,g_screen,round_game);}
                            warPlane.Show(g_screen);
                            warPlane.SpawnBullet(g_screen);
                            if(warPlane.get_spawn_bullet()==true) {Mix_PlayChannel(3,shot,0);
                            warPlane.set_spawn_bullet(false);
                            }
                            warPlane.HandleBullet1(g_screen);
                            player_power.ShowHeart(g_screen);
                            Collision(Enemy_List,warPlane,Bullet_List,hit,g_screen,current_score,GameOver,enemy_die,game_restarted,Health_List,Rocket_List,Upgrade_List);
                            CurrentScore.RenderText(g_screen,950,20);
                            numberofcurrentscore.Set_Text(number_to_string(current_score));
                            numberofcurrentscore.LoadFromRenderText(general_font,g_screen);
                            numberofcurrentscore.RenderText(g_screen,SCREEN_WIDTH-195,20);
                            SDL_RenderPresent(g_screen);
                            SDL_Delay(2);

                        }
                    }
                    if(round_game == 11)
                    {
                         round_game = 1;
                         dem_level = 1;
                         warPlane.set_level_1(true);
                         warPlane.set_level_2(false);
                         warPlane.set_level_3(false);
                         warPlane.set_level_4(false);
                         warPlane.set_level_5(false);

                         SDL_ShowCursor(SDL_ENABLE);
                         while(SDL_PollEvent(&g_event)!=0)
                         {
                            if(g_event.type==SDL_QUIT)
                            {
                                play=false;
                            }
                            RestartButton.HandleRestartButton(g_event,g_screen,Enemy_List,warPlane,Bullet_List,current_score,GameOver,round_game,paused,dem_level);
                            if(RestartButton.get_sound()==true) {Mix_PlayChannel(4,select_button,0);RestartButton.set_sound(false);}
                            if(RestartButton.get_restart_game() == true) {
                            game_restarted = true;RestartButton.set_restart_game_value(false);Time_LoadRound = 0;ready_enemy = true;cnt = 0;
                            Health_List.clear();
                            Upgrade_List.clear();
                            Rocket_List.clear();
                            player_power.Reset();
                            generate_health = 0;
                            generate_rocket = 0;
                            warPlane.set_check_bullet(0);
                            spaceship_count_bullet = 0;
                            player_power.set_beta(180);
                            }
                            CloseButton.HandleCloseBTN(g_event,g_screen,QuitMenu,play);
                            if(CloseButton.get_sound()==true) {Mix_PlayChannel(4,select_button,0);CloseButton.set_sound(false);}
                            Menu_Button.HandleBackMenuButton(g_event,g_screen,QuitMenu,play);
                            if(Menu_Button.get_sound()==true) {Mix_PlayChannel(4,select_button,0);Menu_Button.set_sound(false);}
                            if(Menu_Button.get_backmenu() == true)
                            {
                                Background1.Free();
                                Background2.Free();
                                Background3.Free();
                                Background4.Free();
                                Background5.Free();Background6.Free();
                                Background7.Free();
                                Background8.Free();
                                Background9.Free();
                                Background10.Free();
                                SDL_DestroyRenderer(g_screen);
                                g_screen=NULL;
                                SDL_DestroyWindow(g_window);
                                g_window=NULL;
                                Mix_FreeChunk(hit);
                                hit=NULL;
                                Mix_FreeChunk(Underground);
                                Underground = nullptr;
                                Mix_FreeChunk(enemy_die);
                                enemy_die = NULL;
                                Mix_FreeChunk(dead);
                                dead = NULL;
                                Mix_FreeChunk(Menu_game);
                                Menu_game = NULL;
                                Mix_FreeChunk(upgrade_spaceship);
                                upgrade_spaceship=NULL;
                                Mix_FreeChunk(shot);
                                shot=NULL;
                                Menu.Free();
                                YouWin.Free();
                                Round1.Free();
                                Round2.Free();
                                Round3.Free();
                                Round4.Free();
                                Round5.Free();
                                Round6.Free();
                                Round7.Free();
                                Round8.Free();
                                Round9.Free();
                                Round10.Free();
                                Ship_Shop.Free();
                                Select1.Free();
                                Select2.Free();
                                Select3.Free();
                                Selected.Free();
                                GameOverUI.Free();
                                Pause.Free();
                                Rating.Free();
                                Menu_help.Free();
                                paused_font=NULL;
                                general_font = NULL;
                                Mix_FreeChunk(select_button);
                                select_button=NULL;
                                Menu_Button.set_backmenu(false);
                                goto loop;
                            }
                            QR.HandleQANDRButton(g_event,g_screen,paused);
                            if(QR.get_sound()==true) {Mix_PlayChannel(4,select_button,0);QR.set_sound(false);}
                         }
                         YouWin.SetRect(SCREEN_WIDTH/3,100);
                         YouWin.Render(g_screen);
                         CloseButton.SetRect(SCREEN_WIDTH/3+80,350);
                         CloseButton.Render(g_screen);
                         Menu_Button.SetRect(SCREEN_WIDTH/3+260,250);
                         Menu_Button.Render(g_screen);
                         QR.SetRect(SCREEN_WIDTH/3+260,350);
                         QR.Render(g_screen);
                         RestartButton.SetRect(SCREEN_WIDTH/3+80,250);
                         RestartButton.Render(g_screen);
                         numberofcurrentscore.Set_Text(number_to_string(current_score));
                         numberofcurrentscore.LoadFromRenderText(paused_font,g_screen);
                         numberofcurrentscore.RenderText(g_screen,SCREEN_WIDTH/2+5,SCREEN_HEIGHT/2+125);
                         CurrentScore.RenderText(g_screen,SCREEN_WIDTH/2-125,SCREEN_HEIGHT/2+125);
                         SDL_RenderPresent(g_screen);
                        }
                    }
                else
                    {
                     round_game = 1;
                     dem_level = 1;
                     warPlane.set_level_1(true);
                     warPlane.set_level_2(false);
                     warPlane.set_level_3(false);
                     warPlane.set_level_4(false);
                     warPlane.set_level_5(false);
                     SDL_ShowCursor(SDL_ENABLE);
                     while(SDL_PollEvent(&g_event)!=0)
                     {
                        if(g_event.type==SDL_QUIT)
                        {
                            play=false;
                        }
                        RestartButton.HandleRestartButton(g_event,g_screen,Enemy_List,warPlane,Bullet_List,current_score,GameOver,round_game,paused,dem_level);
                        if(RestartButton.get_sound()==true) {Mix_PlayChannel(4,select_button,0);RestartButton.set_sound(false);}
                        if(RestartButton.get_restart_game() == true) {
                        game_restarted = true;RestartButton.set_restart_game_value(false);Time_LoadRound = 0;ready_enemy = true;cnt = 0;
                        Health_List.clear();
                        Upgrade_List.clear();
                        Rocket_List.clear();
                        player_power.Reset();
                        generate_health = 0;
                        generate_rocket = 0;
                        warPlane.set_check_bullet(0);
                        spaceship_count_bullet = 0;
                        player_power.set_beta(180);
                        }
                        CloseButton.HandleCloseBTN(g_event,g_screen,QuitMenu,play);
                        if(CloseButton.get_sound()==true) {Mix_PlayChannel(4,select_button,0);CloseButton.set_sound(false);}
                        Menu_Button.HandleBackMenuButton(g_event,g_screen,QuitMenu,play);
                        if(Menu_Button.get_sound()==true) {Mix_PlayChannel(4,select_button,0);Menu_Button.set_sound(false);}
                        if(Menu_Button.get_backmenu() == true)
                        {
                            Background1.Free();
                            Background2.Free();
                            Background3.Free();
                            Background4.Free();
                            Background5.Free();Background6.Free();
                            Background7.Free();
                            Background8.Free();
                            Background9.Free();
                            Background10.Free();
                            SDL_DestroyRenderer(g_screen);
                            g_screen=NULL;
                            SDL_DestroyWindow(g_window);
                            g_window=NULL;
                            Mix_FreeChunk(hit);
                            hit=NULL;
                            Mix_FreeChunk(Underground);
                            Underground = nullptr;
                            Mix_FreeChunk(enemy_die);
                            enemy_die = NULL;
                            Mix_FreeChunk(dead);
                            dead = NULL;
                            Mix_FreeChunk(Menu_game);
                            Menu_game = NULL;
                            Mix_FreeChunk(upgrade_spaceship);
                            upgrade_spaceship=NULL;
                            Mix_FreeChunk(shot);
                            shot=NULL;
                            Menu.Free();
                            YouWin.Free();
                            Round1.Free();
                            Round2.Free();
                            Round3.Free();
                            Round4.Free();
                            Round5.Free();
                            Round6.Free();
                            Round7.Free();
                            Round8.Free();
                            Round9.Free();
                            Round10.Free();
                            Ship_Shop.Free();
                            Select1.Free();
                            Select2.Free();
                            Select3.Free();
                            Selected.Free();
                            GameOverUI.Free();
                            Pause.Free();
                            Rating.Free();
                            Menu_help.Free();
                            paused_font=NULL;
                            general_font = NULL;
                            Mix_FreeChunk(select_button);
                            select_button=NULL;
                            Menu_Button.set_backmenu(false);
                            goto loop;
                        }
                        QR.HandleQANDRButton(g_event,g_screen,paused);
                        if(QR.get_sound()==true) {Mix_PlayChannel(4,select_button,0);QR.set_sound(false);}
                     }
                     GameOverUI.SetRect(SCREEN_WIDTH/3,100);
                     GameOverUI.Render(g_screen);
                     CloseButton.SetRect(SCREEN_WIDTH/3+80,350);
                     CloseButton.Render(g_screen);
                     Menu_Button.SetRect(SCREEN_WIDTH/3+260,250);
                     Menu_Button.Render(g_screen);
                     QR.SetRect(SCREEN_WIDTH/3+260,350);
                     QR.Render(g_screen);
                     RestartButton.SetRect(SCREEN_WIDTH/3+80,250);
                     RestartButton.Render(g_screen);
                     numberofcurrentscore.Set_Text(number_to_string(current_score));
                     numberofcurrentscore.LoadFromRenderText(paused_font,g_screen);
                     numberofcurrentscore.RenderText(g_screen,SCREEN_WIDTH/2+5,SCREEN_HEIGHT/2+125);
                     CurrentScore.RenderText(g_screen,SCREEN_WIDTH/2-125,SCREEN_HEIGHT/2+125);
                     SDL_RenderPresent(g_screen);
                    }
        }
        close();
        in.close();
    return 0;
}
