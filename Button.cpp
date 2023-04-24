#include "Button.h"
using namespace std;
Button::Button()
{
	width_frame=0;
    height_frame=0;
    restart_game = false;
    rating_higher = false;
    cnt = 0;
    backmenu = false;
    sound = false;
}
Button::~Button()
{

}
bool Button::LoadTexture(string path, SDL_Renderer* screen)
{
    bool check_load=Texture::LoadTexture(path,screen);
    if(check_load==true)
    {
        width_frame=Rect.w;
        height_frame=Rect.h;
    }
    return check_load;
}
bool Button::IsInside(SDL_Event event)
{
	if (event.type==SDL_MOUSEMOTION || event.type==SDL_MOUSEBUTTONDOWN || event.type==SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside=true;
		if (x<Rect.x)
		{
			inside=false;
		}
		else if (x>Rect.x+width_frame)
		{
			inside=false;
		}
		else if (y<Rect.y)
		{
			inside=false;
		}
		else if (y>Rect.y+height_frame)
		{
			inside=false;
		}
		return inside;
	}
	return 0;
}
void Button::HandlePlayButton(SDL_Event event,SDL_Renderer* screen,bool &menu,bool &play,bool &QuitMenu)
{
	if(IsInside(event))
	{
	    LoadTexture("img//start_red.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    sound = true;
		    play=true;
		    QuitMenu=true;
			menu=false;
		}
	}
	else
	{
		LoadTexture("img//Start_BTN.png",screen);
	}
}
void Button::HandleMapButton(SDL_Event event,SDL_Renderer* screen,bool &menu,bool &help)
{
	if(IsInside(event))
	{
	    LoadTexture("img//map_red.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    sound = true;
            help = true;
            menu = false;
		}
	}
	else
	{
		LoadTexture("img//Map_BTN.png",screen);
	}
}
void Button::HandleExitButton(SDL_Event event,SDL_Renderer* screen,bool &QuitMenu)
{
    if(IsInside(event))
	{
	    LoadTexture("img//exit_red.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    sound = true;
		    QuitMenu=!QuitMenu;
		}
	}
	else
	{
		LoadTexture("img//Exit_BTN.png",screen);
	}
}
void Button::HandleRestartButton(SDL_Event event,SDL_Renderer* screen,
                          vector<Enemy*>&Enemy_List,Character &spaceship,
                          vector<Bullet*> &Bullet_List,long &current_score,bool &GameOver,int& round_game,bool &paused,int& dem_level)
{
    if (IsInside(event))
	{
	    LoadTexture("img//Replay_BTN_ACTIVE.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    sound = true;
		    GameOver=false;
            current_score=0;
            Enemy_List.erase(Enemy_List.begin(),Enemy_List.begin()+Enemy_List.size());
            Bullet_List.erase(Bullet_List.begin(),Bullet_List.begin()+Bullet_List.size());
            spaceship.Reset();
            SDL_WarpMouseInWindow(g_window,SCREEN_WIDTH/2-32,SCREEN_HEIGHT-100);
            paused = false;
            restart_game = true;
            dem_level = 1;
		}
	}
	else
	{
		LoadTexture("img//Replay_BTN.png",screen);
	}
}
void Button::HandleCloseBTN(SDL_Event event,SDL_Renderer* screen,bool &QuitMenu,bool& play)
{
    if(IsInside(event))
	{
	    LoadTexture("img//Close_BTN_ACTIVE.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    sound = true;
		    QuitMenu=!QuitMenu;
		    play = false;
		}
	}
	else
	{
		LoadTexture("img//Close_BTN.png",screen);
	}
}
void Button::HandleRatingButton(SDL_Event event, SDL_Renderer* screen)
{
    if(IsInside(event))
    {
        LoadTexture("img/Rating_BTN_ACTIVE.png",screen);
        if(event.type==SDL_MOUSEBUTTONDOWN)
        {
            sound = true;
            LoadTexture("img/Rating.png",screen);
            rating_higher = true;
        } else
        {
            rating_higher = false;

        }
    }
    else
    {
        LoadTexture("img/Rating_BTN.png",screen);
        rating_higher = false;

    }

}
void Button::HandleFaceBook(SDL_Event event, SDL_Renderer* screen,bool &menu)
{
    if(IsInside(event))
    {
        LoadTexture("img/Facebook_BTN_ACTIVE.png",screen);
        if(event.type==SDL_MOUSEBUTTONDOWN)
        {
            sound = true;
            ShellExecute(NULL, "open", "https://www.facebook.com/thinh.nguyenba.37", NULL, NULL, SW_SHOWNORMAL);
        }
    }
    else
    {
        LoadTexture("img/Facebook_BTN.png",screen);
    }
}
void Button::HandleShoppingButton(SDL_Event event, SDL_Renderer* screen,bool& menu,bool& help,bool& help2,bool& shop)
{
    if(IsInside(event))
    {
        LoadTexture("img/Shop_BTN_ACTIVE.png",screen);
        if(event.type==SDL_MOUSEBUTTONDOWN)
        {
            sound = true;
            shop = true;
            menu = false;
            help = false;
            help2 = false;
        }
    }
    else
    {
        LoadTexture("img/Shop_BTN.png",screen);
    }
}
void Button::HandleContinuePlayGameButton(SDL_Event event,SDL_Renderer* screen,bool &paused)
{
    if(IsInside(event))
    {
        LoadTexture("img/Play_BTN_ACTIVE.png",screen);
        if(event.type==SDL_MOUSEBUTTONDOWN)
        {
            sound = true;
            paused = false;
        }
    }
    else
    {
        LoadTexture("img/Play_BTN.png",screen);
    }
}
void Button::HandleBackMenuButton(SDL_Event event,SDL_Renderer* screen,bool& QuitMenu,bool &play)
{
    if(IsInside(event))
    {
        LoadTexture("img/Menu_BTN_ACTIVE.png",screen);
        if(event.type==SDL_MOUSEBUTTONDOWN)
        {
            sound = true;
            backmenu = true;
        }
    }
    else
    {
        LoadTexture("img/Menu_BTN.png",screen);
    }
}
void Button::HandleQANDRButton(SDL_Event event,SDL_Renderer* screen,bool &paused)
{
    if(IsInside(event))
    {
        LoadTexture("img/FAQ_BTN_ACTIVE.png",screen);
        if(event.type==SDL_MOUSEBUTTONDOWN)
        {
            sound = true;
            ShellExecute(NULL, "open", "https://www.facebook.com/thinh.nguyenba.37", NULL, NULL, SW_SHOWNORMAL);
        }
    }
    else
    {
        LoadTexture("img/FAQ_BTN.png",screen);
    }
}
void Button::HandleBackButton(SDL_Event event,SDL_Renderer* screen,bool &menu,bool &help,bool &help2)
{
    if(IsInside(event))
	{
	    LoadTexture("img//Backward_BTN_ACTIVE.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    sound = true;
		    menu=true;
		    help=false;
		    help2 = false;
		}
	}
	else
	{
		LoadTexture("img//Backward_BTN.png",screen);
	}
}
void Button::HandleBackButtonForShop(SDL_Event event, SDL_Renderer* screen,bool &menu,bool &help,bool& help2,bool& shop)
{
    if(IsInside(event))
	{
	    LoadTexture("img//Backward_BTN_ACTIVE - Copy.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    sound = true;
		    menu=true;
		    help=false;
		    help2 = false;
		    shop = false;
		}
	}
	else
	{
		LoadTexture("img//Backward_BTN - Copy.png",screen);
	}
}
void Button::HandleForwardButton(SDL_Event event, SDL_Renderer* screen, bool &menu,bool &help,bool& help2)
{
    if(IsInside(event))
	{
	    LoadTexture("img//Forward_BTN_ACTIVE.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    sound = true;
		    menu=false;
		    help = false;
		    help2 = true;
		}
	}
	else
	{
		LoadTexture("img//Forward_BTN.png",screen);
	}
}
void Button::HandleBackButton2(SDL_Event event,SDL_Renderer* screen,bool &menu,bool &help,bool& help2)
{

    if(IsInside(event))
	{
	    LoadTexture("img//Backward_BTN_ACTIVE.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    sound = true;
            menu = false;
            help = true;
            help2 = false;
		}
	}
	else
	{
		LoadTexture("img//Backward_BTN.png",screen);
	}

}
void Button::HandleForwardButton2(SDL_Event event, SDL_Renderer* screen, bool &menu,bool &help,bool& help2)
{
    if(IsInside(event))
	{
	    LoadTexture("img//Forward_BTN_ACTIVE.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    sound = true;
		    menu=true;
		    help = false;
		    help2 = false;
		}
	}
	else
	{
		LoadTexture("img//Forward_BTN.png",screen);
	}
}
void Button::HandleSelect1(SDL_Event event, SDL_Renderer* screen,bool &menu,bool &help,bool& help2,bool& shop,bool& shop_button_1,bool& shop_button_2,bool& shop_button_3)
{
    if(IsInside(event) && shop_button_1==false)
	{
	    LoadTexture("img//select_Red.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    sound = true;
		    menu=false;
		    help = false;
		    help2 = false;
		    shop = true;
		    shop_button_1 = true;
		    shop_button_2 = false;
		    shop_button_3 = false;
		}
	}
	else if(shop_button_1==true && shop_button_2 == false&& shop_button_3 == false)
    {
        LoadTexture("img//selected.png",screen);
    }
	else if(shop_button_1 == false)
	{
		LoadTexture("img//select.png",screen);
	}
}
void Button::HandleSelect2(SDL_Event event, SDL_Renderer* screen,bool &menu,bool &help,bool& help2,bool& shop,bool& shop_button_1,bool& shop_button_2,bool& shop_button_3)
{
    if(IsInside(event) && shop_button_2==false)
	{
	    LoadTexture("img//select_Red.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    sound = true;
		    menu=false;
		    help = false;
		    help2 = false;
		    shop = true;
		    shop_button_2 = true;
		    shop_button_1 = false;
		    shop_button_3 = false;
		}
	}
	else if(shop_button_2==true && shop_button_1 == false&& shop_button_3 == false)
    {
        LoadTexture("img//selected.png",screen);
    }
	else if(shop_button_2 == false)
	{
		LoadTexture("img//select.png",screen);
	}
}
void Button::HandleSelect3(SDL_Event event, SDL_Renderer* screen,bool &menu,bool &help,bool& help2,bool& shop,bool& shop_button_1,bool& shop_button_2,bool& shop_button_3)
{
    if(IsInside(event) && shop_button_3==false)
	{
	    LoadTexture("img//select_Red.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    sound = true;
		    menu=false;
		    help = false;
		    help2 = false;
		    shop = true;
		    shop_button_3 = true;
		    shop_button_1 = false;
		    shop_button_2 = false;
		}
	}
	else if(shop_button_3==true&&shop_button_1==false && shop_button_2==false)
    {
        LoadTexture("img//selected.png",screen);
    }
	else if(shop_button_3 == false)
	{
		LoadTexture("img//select.png",screen);
	}
}

