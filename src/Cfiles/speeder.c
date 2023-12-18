#include "speeder.h"

void speeder_init(speeder *Speeder, Map *themap, SDL_Texture *SpeederTexture, float x, float y, int h, int w, int cycle)
{
    Speeder->cycle = cycle;
    Speeder->themap = themap;
    entity(x, y, SpeederTexture, &Speeder->speeder, h, w);
}
void accelerate(speeder *Speeder, Character *character)
{
    if (Character_collision(Speeder, character))
    {

        C_accelerate(character);
    }
}

int Character_collision(speeder *Speeder, Character *character)
{
    SDL_Rect block;
    block.h = Speeder->speeder.destFrame.h - 16;
    block.w = Speeder->speeder.destFrame.w - 16;
    block.x = Speeder->speeder.destFrame.x + 16;
    block.y = Speeder->speeder.destFrame.y + 16;
    SDL_Rect block2;
    block2.h = character->character.destFrame.h - 16;
    block2.w = character->character.destFrame.w - 16;
    block2.x = character->character.destFrame.x + 16;
    block2.y = character->character.destFrame.y + 16;

    if (SDL_HasIntersection(&block, &block2))
    {

        return 1;
    }
    return 0;
}
