#ifndef COMMONFUNC_H_INCLUDED
#define COMMONFUNC_H_INCLUDED
#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include <Windows.h>
#include <Shellapi.h>
using namespace std;

static SDL_Window* g_window=NULL;
static SDL_Renderer* g_screen=NULL;
static SDL_Event g_event;

// Screen
const int SCREEN_WIDTH=1280;
const int SCREEN_HEIGHT=720;
const int SCREEN_BPP=32;
const double PI  =3.141592653589793238463;
const int COLOR_KEY_R=167;
const int COLOR_KEY_G=175;
const int COLOR_KEY_B=180;
const int RENDER_DRAW_COLOR=255;

// check collision bên ngoài
bool CheckCollision(const SDL_Rect &object1,const SDL_Rect &object2);
// check collision bên trong
bool CheckCollision2(const SDL_Rect &object1,const SDL_Rect &object2);
string number_to_string(int number);
#endif
