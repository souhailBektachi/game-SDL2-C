#include "Character.h"

void character(float x, float y, SDL_Texture *textures[], Character *character, int speed)
{
    entity(x, y, textures[0], &character->character, 32, 32);
    character->character.destFrame.h = 64;
    character->character.destFrame.w = 64;

    character->coll = 0;
    character->speed = speed;
    character->cycle = 0;
    character->angle = -1;
    for (int i = 0; i < 5; i++)
    {
        character->textures[i] = textures[i];
    }

    character->isDead = 0;
    character->isAccelerated = 0;
}
int CgetSpeed(Character *character)
{
    return character->speed;
}

void movecharacter(double angle, Character *character, Map *p_Map)
{
    if (angle != character->angle)
    {
        character->angle = angle;
        character->cycle = 0;
    }

    Character_animate(character);
    int speed;
    if (isAccelerated(character))
    {
        speed = 1000;
    }
    else
    {
        speed = character->speed;
    }
    double Dt = getDelta_time(&character->character);

    vector2d temppos = entity_getpos(&character->character);
    Character tempC;
    copy_character(&tempC, character);
    float p_x = speed * cos(angle) * Dt;
    float p_y = speed * sin(angle) * Dt;
    entity_setpos(&tempC.character, temppos.x + p_x, temppos.y + p_y);
    tempC.character.destFrame.x = temppos.x;
    tempC.character.destFrame.y = temppos.y;

    character_collision(&tempC, p_Map);
    entity_setpos(&character->character, tempC.character.pos.x, tempC.character.pos.y);
    character->isAccelerated = 0;
}

void addTextuers(SDL_Texture *textures[], Character *character, int size)
{
    for (int i = 0; i < size; i++)
    {
        character->textures[i] = textures[i];
    }
}

void character_collision(Character *p_a, Map *p_b)
{
    int size = p_b->mapTilesSize.w;
    int C_x = p_a->character.destFrame.x + size / 2;
    int C_y = p_a->character.destFrame.y + size / 2;
    for (int i = (C_y / size); i <= (C_y / size) + 1; i++)
    {
        for (int j = (C_x / size); j <= (C_x / size) + 1; j++)
        {
            mapE Tile = p_b->mapTiles[i][j];
            char type = getType(&p_b->walls, Tile.key > 0 ? Tile.key : 0);
            vector2d tempvect = p_a->character.pos;

            if (type != '\0')
            {
                tempvect = entity_collision(p_a->character.destFrame, Tile.Tile.destFrame, p_a->character.pos, Tile.Tile.pos, type);

                if (tempvect.x != p_a->character.pos.x || tempvect.y != p_a->character.pos.y)
                {
                    entity_setpos(&p_a->character, tempvect.x, tempvect.y);
                }
            }
        }
    }
}

void copy_character(Character *p_a, Character *p_b)
{
    character(p_b->character.pos.x, p_b->character.pos.y, p_b->textures, p_a, p_b->speed);
}

int isDead(Character *p_a)
{
    return p_a->isDead;
}
void Kill_Character(Character *p_a)
{
    if (!p_a->isDead)
    {
        p_a->isDead = 1;
    }
}
void reveive_character(Character *p_a)
{
    if (p_a->isDead)
    {
        p_a->isDead = 0;
    }
}
int isAccelerated(Character *p_a)
{

    return p_a->isAccelerated;
}
void C_accelerate(Character *p_a)
{

    p_a->isAccelerated = 1;
}

void cleanCharacter(Character *p_a)
{
    cleanEntity(&p_a->character);
    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(p_a->textures[i]);
    }
    free(p_a);
}
void Character_animate(Character *p_a)
{

    p_a->character.currentFrame.x = p_a->cycle * 32;
}