#include "ball.h"

void ball(float x ,float y, SDL_Texture* ball_texture,Ball* ball,int speed){
entity(x,y,ball_texture,&ball->ball,16,16);
    ball->speed=speed;
    
    
}
int BgetSpeed(Ball* ball){
    return ball->speed;
}
int ball_collision(Ball* ball,Map* p_b){
    vector2d B_pos=ball->ball.pos;
    B_pos.x+=8;
    B_pos.y+=8;
    int coll=0;
    int indexy=B_pos.y/16 - 1;
    int indexX=B_pos.x/16 -1;
    for (int i = indexy; i < indexy+2; i++)
    {
        for (int j = indexX; j < indexX+2; j++)
        {
             mapE Tile=p_b->mapTiles[i][j];
    char type =getType(&p_b->walls,Tile.key>0?Tile.key:0);
    vector2d tempvect;
    if(type !='\0'){
        tempvect=entity_collision(ball->ball.currentFrame,Tile.Tile.currentFrame,ball->ball.pos,Tile.Tile.pos,type);
        vector(&tempvect,tempvect.x,tempvect.y);
        if(tempvect.x !=ball->ball.pos.x || tempvect.y != ball->ball.pos.y ){
            coll = 1;
        }else{
                        
        }
        entity_setpos(&ball->ball,tempvect.x,tempvect.y);

    }
        }
        
    }
        return coll;
    
   

}
void moveBall(Ball* ball,Map* p_map){
        vector2d temppos=entity_getpos(&ball->ball);

    entity_setpos(&ball->ball,temppos.x+ball->speed,temppos.y+ball->speed);
    
    if (ball_collision(ball,p_map)){
        ball_setSpeed(ball,-ball->speed);
        entity_setpos(&ball->ball,entity_getpos(&ball->ball).x,entity_getpos(&ball->ball).y+(rand() % 42)-20);
       

    }
}

void ball_setSpeed(Ball* ball,int speed){
    ball->speed=speed;
}