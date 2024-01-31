
#include "../Header/stdafx.h"
#include "../Header/CommonFunc.h"
#include "../Header/BaseObject.h"
#include "../Header/game_map.h"
#include "../Header/MainObject.h"

BaseObject gBackground;

bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);

    if (ret < 0)
        return false;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    // Create window
    gWindow = SDL_CreateWindow("Game SDL2.0", SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (gWindow == NULL)
        success = false;
    else
    {
        gScreen = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
        if (gScreen == NULL)
            success = false;
        else
        {
            SDL_SetRenderDrawColor(gScreen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags))
                success = false;
        }
    }

    return success;
}

bool LoadBackground()
{
    bool ret = gBackground.LoadImg("../images/bg2.png", gScreen);
    return ret;
}

void close()
{
    gBackground.Free();
    SDL_DestroyRenderer(gScreen);
    gScreen = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char *argv[])
{
    if (InitData() == false)
        return -1;

    if (LoadBackground() == false)
        return -1;

    GameMap game_map;
    game_map.LoadMap("../images/map/map.txt");
    game_map.LoadTiles(gScreen);

    MainObject p_player;
    p_player.LoadImg("../images/player_right.png", gScreen);
    p_player.setClips();

    bool isQuit = false;
    while (!isQuit)
    {
        while (SDL_PollEvent(&gEvent) != 0)
        {
            if (gEvent.type == SDL_QUIT)
            {
                isQuit = true;
            }
            p_player.HandleInputAction(gEvent, gScreen);
        }

        SDL_SetRenderDrawColor(gScreen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(gScreen);

        gBackground.Render(gScreen, NULL);
        game_map.DrawMap(gScreen);

        Map map_data = game_map.getGameMap();
        p_player.doPlayer(map_data);

        p_player.Show(gScreen);

        SDL_RenderPresent(gScreen);
    }

    close();
    cout << "Hello, world!" << endl;
    return 0;
}