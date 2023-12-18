#include "entity.h"
#include "Character.h"
#include "map.h"
typedef struct
{
    Entity speeder;
    int cycle;
    Map *themap;

} speeder;
void speeder_init(speeder *Speeder, Map *themap, SDL_Texture *SpeederTexture, float x, float y, int h, int w, int cycle);
void accelerate(speeder *Speeder, Character *character);
int Character_collision(speeder *Speeder, Character *character);
