#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include "Texture.h"
#include "Game_Utils.h"
#include "Enemy.h"
#include "Character.h"
#include "Bullet.h"
#include "PlayerPower.h"
using namespace std;

class Button : public Texture
{
public:
	Button();
	~Button();
	virtual bool LoadTexture(string path,SDL_Renderer* screen);
    int get_frame_width() const {return width_frame;}
    int get_frame_height() const {return height_frame;}
	bool IsInside(SDL_Event event);
	void HandlePlayButton(SDL_Event event,SDL_Renderer* screen,bool &menu,bool &play,bool &QuitMenu);
	void HandleMapButton(SDL_Event event,SDL_Renderer* screen,bool &menu,bool &help);
	void HandleExitButton(SDL_Event event,SDL_Renderer* screen,bool &QuitMenu);
	void HandleCloseBTN(SDL_Event event,SDL_Renderer* screen,bool &QuitMenu,bool &play);

	void HandleFaceBook(SDL_Event event,SDL_Renderer* screen,bool &menu);

	void HandleBackButton(SDL_Event event,SDL_Renderer* screen,bool &menu,bool &help,bool& help2);
	void HandleBackButton2(SDL_Event event,SDL_Renderer* screen,bool &menu,bool &help,bool& help2);
	void HandleRestartButton(SDL_Event event,SDL_Renderer* screen,
                          vector<Enemy*>&Enemy_List,Character &spaceship,
                          vector<Bullet*> &Bullet_List,
                          long &current_score,bool &GameOver,int& round_game,bool &paused,int& dem_level);
    //HANDLE RATING
    void HandleRatingButton(SDL_Event event, SDL_Renderer* screen);
    //HANDLE SHOP
    void HandleShoppingButton(SDL_Event event, SDL_Renderer* screen,bool& menu,bool& help,bool& help2,bool& shop);
    //
    bool get_restart_game() {return restart_game;}
    void set_restart_game_value(bool value_) {restart_game = value_;}

    //Handle continue game
    void HandleContinuePlayGameButton(SDL_Event event,SDL_Renderer* screen,bool &paused);
    // Handle Menu
    void HandleBackMenuButton(SDL_Event event,SDL_Renderer* screen,bool &QuitMenu,bool &play);
    //
    void HandleQANDRButton(SDL_Event event,SDL_Renderer* screen,bool &paused);
    //
    void HandleForwardButton(SDL_Event event, SDL_Renderer* screen, bool &menu,bool &help,bool& help2);
    //
    void HandleBackButtonForShop(SDL_Event event, SDL_Renderer* screen,bool &menu,bool &help,bool& help2,bool& shop);
    //
    void HandleSelect1(SDL_Event event, SDL_Renderer* screen,bool &menu,bool &help,bool& help2,bool& shop,bool& shop_button_1,bool& shop_button_2,bool& shop_button_3);
    void HandleSelect2(SDL_Event event, SDL_Renderer* screen,bool &menu,bool &help,bool& help2,bool& shop,bool& shop_button_1,bool& shop_button_2,bool& shop_button_3);
    void HandleSelect3(SDL_Event event, SDL_Renderer* screen,bool &menu,bool &help,bool& help2,bool& shop,bool& shop_button_1,bool& shop_button_2,bool& shop_button_3);
    void HandleForwardButton2(SDL_Event event, SDL_Renderer* screen, bool &menu,bool &help,bool& help2);
    bool get_rating_higher() {return rating_higher;}
    void set_reting_higher(bool value_) {rating_higher = value_;}
    bool get_backmenu() {return backmenu;}
    void set_backmenu(bool value_){backmenu = value_;}
    void set_sound(bool value_) {sound = value_;}
    bool get_sound(){return sound;}
private:
    int width_frame;
    int height_frame;
    bool restart_game;
    bool rating_higher;
    bool backmenu;
    int cnt = 0;
    bool sound;
};

#endif // BUTTON_H_INCLUDED
