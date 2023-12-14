#include "ball.h"

void ball(float x, float y, SDL_Texture *ball_texture, Ball *ball, int speed, double angle)
{
    entity(x, y, ball_texture, &ball->ball, 16, 16);
    ball->speed = speed;
    ball->angle = angle;
}
int BgetSpeed(Ball *ball)
{
    return ball->speed;
}
int ball_collision(Ball *ball, Map *p_b)
{
    vector2d B_pos = ball->ball.pos;
    B_pos.x += 8;
    B_pos.y += 8;
    int coll = 0;

    mapE Tile = p_b->mapTiles[(int)B_pos.y / 16][(int)B_pos.x / 16];
    char type = getType(&p_b->walls, Tile.key > 0 ? Tile.key : 0);
    vector2d tempvect;
    if (type != '\0')
    {
        tempvect = entity_collision(ball->ball.currentFrame, Tile.Tile.currentFrame, ball->ball.pos, Tile.Tile.pos, type);
        vector(&tempvect, tempvect.x, tempvect.y);
        if (tempvect.x != ball->ball.pos.x || tempvect.y != ball->ball.pos.y)
        {
            coll = 1;
            entity_setpos(&ball->ball, tempvect.x, tempvect.y);
        }
    }

    return coll;
}

void moveBall(Ball *ball, Map *p_map, Character *character)
{
    vector2d temppos = entity_getpos(&ball->ball);
    Ball tempB;
    double angle = Get_BallAngle(ball);
    float Dt = getDelta_time(&ball->ball);
    double xspeed = ball->speed * cos(angle) * Dt;
    double yspeed = ball->speed * sin(angle) * Dt;

    static int PN = 1;
    entity_setpos(&tempB.ball, temppos.x + (int)xspeed, temppos.y + (int)yspeed);
    if (ball_collision(&tempB, p_map))
    {
        PN *= -1;
        Set_BallAngle(ball, reflection_angle(xspeed, yspeed, PN));
    }
    entity_setpos(&ball->ball, tempB.ball.pos.x, tempB.ball.pos.y);
    ballCharacter_collision(ball, character);
}

void ball_setSpeed(Ball *ball, int speed)
{
    ball->speed = speed;
}
int ball_getSpeed(Ball *ball)
{
    return ball->speed;
}
void Set_BallAngle(Ball *ball, double angle)
{
    ball->angle = angle;
}
double Get_BallAngle(Ball *ball)
{
    return ball->angle;
}
void ballCharacter_collision(Ball *ball, Character *character)
{
    if (entityToEntity_collision(&ball->ball, &character->character))
    {
        Kill_Character(character);
    }
}
void cleanBall(Ball *ball)
{
    cleanEntity(&ball->ball);
    SDL_DestroyTexture(ball->ball_texture);
    free(ball);
}