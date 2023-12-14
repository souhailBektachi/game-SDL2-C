#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "csts.h"
#include "renderwindow.h"
#include "stdbool.h"
#include "Character.h"
#include "map.h"
#include "ball.h"
#include "entity.h"
typedef struct
{
    const char *title;
    RenderW window;
    bool isRunning;
    Character player;
    Map themap[2];
    Ball theball;
    int mapindex;

} game;

void gameInit(game *game, const char *title);
void handleEvents(game *game);
void update(game *game);
void renderGame(game *game);
void cleanGame(game *game);
bool running();