
#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"

#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 8

class MainObject : public BaseObject
{
public:
    MainObject();
    ~MainObject();

    enum WalkType
    {
        WALK_RIGHT = 0,
        WALK_LEFT = 1
    };

    virtual bool LoadImg(string path, SDL_Renderer *screen);
    void Show(SDL_Renderer *des);
    void HandleInputAction(SDL_Event events, SDL_Renderer *screen);
    void setClips();
    void doPlayer(Map &map_data);
    void checkToMap(Map &map_data);

private:
    float x_val_;
    float y_val_;

    float x_pos_;
    float y_pos_;

    // width and height of 1 frame
    int width_frame_;
    int height_frame_;

    // Cac frame
    SDL_Rect frame_clip_[8];

    // Dang trong action nao?
    Input input_type_;

    // Dang o frame nao?
    int frame_;

    // Dang di chuyen qua phai~ hay trai' ??
    int status_;

    // Check dung tren mat dat hay chua
    bool on_ground_;
};

#endif