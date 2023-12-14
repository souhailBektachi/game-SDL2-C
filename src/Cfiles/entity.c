#include "entity.h"

void entity(float x, float y, SDL_Texture *texture, Entity *entity, float h, float w)
{

    entity->pos.x = x;
    entity->pos.y = y;

    entity->currentFrame.x = 0;
    entity->currentFrame.y = 0;
    entity->currentFrame.h = h;
    entity->currentFrame.w = w;

    entity->texture = texture;
    entity->isflipped = 0;
}

vector2d entity_getpos(Entity *entity)
{
    return entity->pos;
}
void entity_setpos(Entity *entity, float x, float y)
{
    entity->pos.x = x;
    entity->pos.y = y;
}
SDL_Texture *entity_getTex(Entity *entity)
{
    return entity->texture;
}
SDL_Rect entity_getCFrame(Entity *entity)
{
    return entity->currentFrame;
}

void entity_setTex(Entity *entity, SDL_Texture *tex)
{
    entity->texture = tex;
}
void entity_setCFrame(Entity *entity, float h, float w, float x, float y)
{
    entity->currentFrame.h = h;
    entity->currentFrame.w = w;
    entity->currentFrame.x = x;
    entity->currentFrame.y = y;
}

vector2d entity_collision(const SDL_Rect p_a, SDL_Rect p_b, vector2d p_aPos, vector2d p_bPos, char type)
{

    vector2d p_aVect;
    vector2d p_bVect;
    vector(&p_aVect, p_aPos.x, p_aPos.y);
    vector(&p_bVect, p_bPos.x, p_bPos.y);
    switch (type)
    {
    case 'L':
        if (p_aVect.x < p_bVect.x + p_b.w / 4)
        {
            vector(&p_aVect, p_bVect.x + p_b.w / 4, p_aVect.y);
        }

        break;
    case 'R':
        if (p_aVect.x + p_a.w > p_bVect.x + (3 * p_b.w / 4))
        {

            vector(&p_aVect, p_bVect.x + (3 * p_b.w / 4) - p_a.w, p_aVect.y);
        }
        break;
    case 'U':
        if (p_aVect.y < p_bVect.y + p_b.h / 4)
        {
            vector(&p_aVect, p_aVect.x, p_bVect.y + p_b.h / 4);
        }
        break;
    case 'B':
        if (p_aVect.y + p_a.h > p_bVect.y + (3 * p_b.h / 4))
        {
            vector(&p_aVect, p_aVect.x, p_bVect.y + (3 * p_b.h / 4) - p_a.h);
        }
        break;
    case 'u':
        if (p_aVect.y < p_bVect.y + p_b.h / 4 || p_aVect.x < p_bVect.x + p_b.w / 4)
        {
            vector(&p_aVect, p_bVect.x + p_b.w / 4, p_bVect.y + p_b.h / 4);
        }
        break;
    case 'b':
        if (p_aVect.y + p_a.h > p_bVect.y + (3 * p_b.h / 4) || p_aVect.x < p_bVect.x + p_b.w / 4)
        {
            vector(&p_aVect, p_bVect.x + p_b.w / 4, p_bVect.y + (3 * p_b.h / 4) - p_a.h);
        }
        break;
    case 'c':
        if (p_aVect.y < p_bVect.y + p_b.h / 4 || p_aVect.x + p_a.w > p_bVect.x + (3 * p_b.w / 4))
        {
            vector(&p_aVect, p_bVect.x + (3 * p_b.w / 4) - p_a.w, p_bVect.y + p_b.h / 4);
        }
        break;
    case 'v':
        if (p_aVect.y + p_a.h > p_bVect.y + (3 * p_b.h / 4) || p_aVect.x + p_a.w > p_bVect.x + (3 * p_b.w / 4))
        {
            vector(&p_aVect, p_bVect.x + (3 * p_b.w / 4) - p_a.w, p_bVect.y + (3 * p_b.h / 4) - p_a.h);
        }
        break;

    default:
        break;
    }
    return p_aVect;
}

int entityToEntity_collision(Entity *p_a, Entity *p_b)
{
    SDL_Rect p_aRect = p_a->currentFrame;
    SDL_Rect p_bRect = p_b->currentFrame;
    p_aRect.x = p_a->pos.x;
    p_aRect.y = p_a->pos.y;
    p_bRect.x = p_b->pos.x;
    p_bRect.y = p_b->pos.y;

    if (SDL_HasIntersection(&p_aRect, &p_bRect))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void setDelta_time(Entity *entity, float deltaTime)
{
    entity->delta_time = deltaTime;
}
float getDelta_time(Entity *entity)
{
    return entity->delta_time;
}
