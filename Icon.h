#ifndef ICON_H_EFFECT_
#define ICON_H_EFFECT_
#include "Game_Utils.h"
#include "Texture.h"
#define Speed 1
using namespace std;
class Icon : public Texture
{
public:
    Icon();
    ~Icon();
    virtual bool LoadTexture(string path,SDL_Renderer* screen);
    int get_frame_width() const {return width_frame;}
    int get_frame_height() const {return height_frame;}
    void MoveEffect(const int &x_border,const int &y_border);
    void set_is_move(const bool &isMove) {is_move=isMove;}
    bool get_is_move() const {return is_move;}
private:
    int width_frame;
    int height_frame;
    bool is_move;
};
#endif // ICON_H_EFFECT_
