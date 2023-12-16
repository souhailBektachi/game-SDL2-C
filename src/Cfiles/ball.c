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

    int size = p_b->mapTilesSize.w;
    mapE Tile = p_b->mapTiles[(int)B_pos.y / size][(int)B_pos.x / size];
    char type = getType(&p_b->walls, Tile.key > 0 ? Tile.key : 0);
    vector2d tempvect;
    if (type != '\0')
    {
        tempvect = entity_collision(ball->ball.currentFrame, Tile.Tile.destFrame, ball->ball.pos, Tile.Tile.pos, type);
        vector(&tempvect, tempvect.x, tempvect.y);
        if (tempvect.x != ball->ball.pos.x || tempvect.y != ball->ball.pos.y)
        {
            coll = 1;
            entity_setpos(&ball->ball, tempvect.x, tempvect.y);
        }
    }

    return coll;
}

void moveBall(Ball *ball, Map *p_map, Character *character, Ball balls[], int index)
{
    vector2d temppos = entity_getpos(&ball->ball);
    Ball tempB;
    double angle = Get_BallAngle(ball);
    float Dt = getDelta_time(&ball->ball);

    double xspeed = ball->speed * cos(angle) * Dt;
    double yspeed = ball->speed * sin(angle) * Dt;

    entity_setpos(&tempB.ball, temppos.x + (int)xspeed, temppos.y + (int)yspeed);
    if (ball_collision(&tempB, p_map))
    {
        Set_BallAngle(ball, reflection_angle(xspeed, yspeed, -1));
    }
    if (tempB.ball.pos.x < SCREEN_WIDTH && tempB.ball.pos.y < SCREEN_HEIGHT && tempB.ball.pos.x > 0 && tempB.ball.pos.y > 0)
    {
        entity_setpos(&ball->ball, tempB.ball.pos.x, tempB.ball.pos.y);
    }
    ballCharacter_collision(ball, character);
    ballBalls_collision(balls, index);
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
void ballBalls_collision(Ball balls[], int index)
{
    for (int i = 0; i < 10; i++)
    {
        if (i == index)
        {
            continue;
        }

        if (SDL_HasIntersection(&balls[index].ball.destFrame, &balls[i].ball.destFrame))
        {
            Set_BallAngle(&balls[index], -Get_BallAngle(&balls[index]));
            Set_BallAngle(&balls[i], -Get_BallAngle(&balls[i]));
            break;
        }
    }
}
