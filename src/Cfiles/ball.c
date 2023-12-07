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

             mapE Tile=p_b->mapTiles[(int)B_pos.y/16][(int)B_pos.x/16];
    char type =getType(&p_b->walls,Tile.key>0?Tile.key:0);
    vector2d tempvect;
    if(type !='\0'){
        tempvect=entity_collision(ball->ball.currentFrame,Tile.Tile.currentFrame,ball->ball.pos,Tile.Tile.pos,type);
        vector(&tempvect,tempvect.x,tempvect.y);
        if(tempvect.x !=ball->ball.pos.x || tempvect.y != ball->ball.pos.y ){
            coll = 1;
            entity_setpos(&ball->ball,tempvect.x,tempvect.y);
        }
        

    }
        
        
    
       

        return coll;}
    
   


void moveBall(Ball* ball,Map* p_map){
        vector2d temppos=entity_getpos(&ball->ball);
        Ball tempB;
        
        int xspeed=ball->speed;
        int yspeed=ball->speed;
        entity_setpos(&tempB.ball,temppos.x+xspeed,temppos.y+yspeed);
    if (ball_collision(&tempB,p_map)){
        // ball_setSpeed(ball,-ball->speed);
       xspeed*=cos(((rand()%360)-180) * M_PI / 180.0);
       yspeed*=ball->speed*sin(20.0 * M_PI / 180.0);

    }
    entity_setpos(&ball->ball,tempB.ball.pos.x,tempB.ball.pos.y);

}

void ball_setSpeed(Ball* ball,int speed){
    ball->speed=speed;
}
int ball_getSpeed(Ball* ball){
    return ball->speed;
}