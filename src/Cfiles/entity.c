#include "entity.h"

void entity(float x,float y,SDL_Texture* texture,Entity* entity,float h,float w)
{
 
    
    entity->pos.x=x;
    entity->pos.y=y;
   
    
    entity->currentFrame.x=0;
    entity->currentFrame.y=0;
    entity->currentFrame.h=h;
    entity->currentFrame.w=w;
    
    
    entity->texture=texture;


}

vector2d entity_getpos(Entity* entity){
    return entity->pos;
    
}
void entity_setpos(Entity* entity,float x,float y){
    entity->pos.x=x;
    entity->pos.y=y;
}
SDL_Texture* entity_getTex(Entity* entity){
    return entity->texture;
}
SDL_Rect entity_getCFrame(Entity* entity){
    return entity->currentFrame;
}

void entity_setTex(Entity* entity,SDL_Texture* tex){
    entity->texture=tex;
}
void entity_setCFrame(Entity* entity,float h,float w,float x,float y){
    entity->currentFrame.h=h;
    entity->currentFrame.w=w;
    entity->currentFrame.x=x;
    entity->currentFrame.y=y;

}


vector2d entity_collision(const SDL_Rect p_a,SDL_Rect p_b,vector2d p_aPos,vector2d p_bPos,char type){
    
    vector2d p_aVect ;
    vector2d p_bVect;
    vector(&p_aVect,p_aPos.x,p_aPos.y);
    vector(&p_bVect,p_bPos.x,p_bPos.y);
    printf("%c\n",type);
    switch (type)
    {
    case 'R':
        if (p_aVect.x < p_bVect.x +p_b.w/4)
        {
            vector(&p_aVect,p_bVect.x+p_b.w/4,p_aVect.y);

        }
        
        break;
    case 'L':
        if(p_aVect.x+p_a.w > p_bVect.x+(3*p_b.w/4)){
            
            vector(&p_aVect,p_bVect.x+(3*p_b.w/4)-p_a.w,p_aVect.y);
        }
        break;
    case 'U':
        if(p_aVect.y > p_bVect.y+p_b.h/2){
            vector(&p_aVect,p_aVect.x,p_aVect.y+p_b.h/2);
        }
        break;
    case 'B':
        if(p_aVect.y<p_bVect.y+p_b.h/2){
            vector(&p_aVect,p_aVect.x,p_aVect.y+p_b.h/2);
        }
        break;
    case 'u':
        
        break;
    case 'b':
        
        break;
    case 'c':
        
        break;
    case 'v':
        
        break;
    
    default:
        break;
    }
    return p_aVect;


}

// int entity_cllision(const Entity* p_a,const Entity* p_b,char position){
// //     printf("Player: (%d, %d, %d, %d)\n", p_a->destFrame.x, p_a->destFrame.y, p_a->destFrame.w, p_a->destFrame.h);
// // printf("Obstacle: (%d, %d, %d, %d)\n", p_b->destFrame.x, p_b->destFrame.y, p_b->destFrame.w, p_b->destFrame.h);
//     SDL_Rect Rect1={p_a->destFrame.x+8,p_a->destFrame.y+8,p_b->destFrame.w,p_b->destFrame.h};
//     SDL_Rect Rect2={p_b->destFrame.x,p_b->destFrame.y,p_b->destFrame.w,p_b->destFrame.h};
//     printf("x1=%d y1=%d x2=%d y2=%d\n",Rect1.x,Rect1.y,Rect2.x,Rect2.y);
//     switch (position)
//     {
//     case 'A':
//         return ((Rect1.y<=(Rect2.y+Rect2.h)) && ((Rect1.x+Rect1.w)>=(Rect2.x)))?1:0;

//         break;
//     case 'B':

//         return ((Rect1.y<=(Rect2.y+Rect2.h)) && ((Rect1.x)<=(Rect2.x+Rect2.w)))?1:0;
//         break;
//     case 'C':

//         return (((Rect1.y+Rect1.h)>=(Rect2.y)) && ((Rect1.x+Rect1.w)>=(Rect2.x)))?1:0;
//         break;
//     case 'D':

//         return (((Rect1.y+Rect1.h)>=(Rect2.y)) && ((Rect1.x)<=(Rect2.x+Rect2.w)))?1:0;
//         break;
//     case 'E':

//         return ((Rect1.y+Rect1.h)>=(Rect2.y)) ?1:0;
//         break;
//     case 'F':
   
//         return (Rect1.y<=(Rect2.y+Rect2.h)) ?1:0;

//         break;
//     case 'G':
//         Rect2.x=Rect2.x;
        
//         return 1;
//         break;
//     case 'H':
        
//         return ((Rect1.x)>Rect1.x-Rect2.w/2)?1:0;

//         break;




        


    
//     default:
//         break;
//     }


    
    
//     return 0;
    
   
    
// }
// void changeH(SDL_Rect* a){
//     a->h=a->h/2;
// }
// void changeW(SDL_Rect* a){
//     a->w=a->w/2;
// }
// void changeHW(SDL_Rect* a){
//     changeH(a);
//     changeW(a);
// }
