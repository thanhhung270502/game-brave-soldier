
#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "CommonFunc.h"
#include "BaseObject.h"

// 3000
#define MAX_TILES 20

// Luu hinh anh de lap vao o
class TileMat : public BaseObject
{
public:
    TileMat() { ; }
    ~TileMat() { ; }
};

class GameMap
{
public:
    GameMap() { ; }
    ~GameMap() { ; }

    void LoadMap(string name);
    void LoadTiles(SDL_Renderer *screen);
    void DrawMap(SDL_Renderer *screen);
    Map getGameMap() const { return game_map_; };

private:
    Map game_map_;
    TileMat tile_mat[MAX_TILES];
};

#endif