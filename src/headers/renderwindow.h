#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "entity.h"
typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} RenderW;
void initRenderW(RenderW* renderwindow);
void RenderWindow(const char* p_title,int p_w ,int p_h,RenderW* renderwindow);
void cleanUp(RenderW* renderwindow);
SDL_Texture* loadtexture(const char* p_filename,RenderW* renderwindow);
void clear(RenderW* renderwindow);
void render(Entity* p_entity,RenderW* renderwindow,int flip);
void display(RenderW* renderwindow);