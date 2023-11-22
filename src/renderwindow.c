
#include "renderwindow.h"

void initRenderW(RenderW* renderwindow){
    renderwindow->window=NULL;
    renderwindow->renderer=NULL;
}

void RenderWindow(const char* p_title,int p_w ,int p_h,RenderW* renderwindow ){
    
    initRenderW(renderwindow);
    renderwindow->window=SDL_CreateWindow(p_title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,p_w,p_h,SDL_WINDOW_SHOWN);
    if (renderwindow->window==NULL)
    {
        printf("Window failed to init %s\n",SDL_GetError());
    }
    renderwindow->renderer=SDL_CreateRenderer(renderwindow->window,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    


    


}
SDL_Texture* loadtexture(const char* p_filename,RenderW* renderwindow){
    SDL_Texture* texture =NULL;
    
    texture =IMG_LoadTexture(renderwindow->renderer,p_filename);
    if(texture ==NULL){
            printf("Texture failed to load: %s\n", IMG_GetError());

    }
    return texture;
}
void clear(RenderW* renderwindow){
    
   SDL_RenderClear(renderwindow->renderer);
    
}

void render(Entity* p_entity,RenderW* renderwindow){
    SDL_Rect src;
    src.x=0;
    src.y=0;
    src.h=32;
    src.w=32;
    
    SDL_Rect dst;
    dst.x=entity_getx(p_entity);
    dst.y=entity_gety(p_entity);
    dst.h=32;
    dst.w=32;
    SDL_RenderCopy(renderwindow->renderer,entity_getTex(p_entity),&src,&dst);
    
    
    


}
void display(RenderW *renderwindow){
    

    SDL_RenderPresent(renderwindow->renderer);
}
void cleanUp(RenderW* renderwindow){
    SDL_DestroyWindow(renderwindow->window);
}