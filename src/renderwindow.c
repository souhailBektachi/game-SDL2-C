
#include "renderwindow.h"

void initRenderW(RenderW renderwindow){
    renderwindow.window=NULL;
    renderwindow.renderer=NULL;
}

void RenderWindow(const char* p_title,int p_w ,int p_h,RenderW renderwindow ){
    initRenderW(renderwindow);
    renderwindow.window=SDL_CreateWindow(p_title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,p_w,p_h,SDL_WINDOW_SHOWN);
    if (renderwindow.window==NULL)
    {
        printf("Window failed to init %S\n",SDL_GetError());
    }
    renderwindow.renderer=SDL_CreateRenderer(renderwindow.window,-1,SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(renderwindow.renderer);
    
    


}
SDL_Texture* loadtexture(const char* p_filename,RenderW renderwindow){
    SDL_Texture* texture=NULL;
    texture = IMG_LoadTexture(renderwindow.renderer,p_filename);
    if(texture==NULL){
        printf("texture load failed %s",SDL_GetError);
    }
    return texture;
}
void clear(RenderW renderwindow){
   SDL_RenderClear(renderwindow.renderer);
}

void render(SDL_Texture* p_texture,RenderW renderwindow){
    SDL_RenderCopy(renderwindow.renderer,p_texture,NULL,NULL);


}
void display(RenderW renderwindow){
    SDL_RenderPresent(renderwindow.renderer);
}
void cleanUp(RenderW renderwindow){
    SDL_DestroyWindow(renderwindow.window);
}