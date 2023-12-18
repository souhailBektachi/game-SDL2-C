#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "entity.h"
#include "renderwindow.h"
typedef struct
{
    SDL_Texture *background_texture;
    SDL_Texture *text_textures[4];
    Entity entities[5];

    SDL_Rect rect;
} Menu;
void Menu_init(Menu *menu, SDL_Texture *background_texture, SDL_Texture *text_textures[4], SDL_Rect Title, SDL_Rect texts);
void Menu_render(Menu *menu, RenderW *RenderWindow);
void Menu_Cleanup(Menu *menu);