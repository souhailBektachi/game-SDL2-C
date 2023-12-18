#include "menu.h"

void Menu_init(Menu *menu, SDL_Texture *background_texture, SDL_Texture *text_textures[4], SDL_Rect Title, SDL_Rect texts)
{
    menu->background_texture = background_texture;
    menu->text_textures[0] = text_textures[0];
    menu->text_textures[1] = text_textures[1];
    menu->text_textures[2] = text_textures[2];
    menu->text_textures[3] = text_textures[3];
    entity(0, 0, background_texture, &menu->entities[0], SCREEN_HEIGHT, SCREEN_WIDTH);
    entity(Title.x, Title.y, text_textures[0], &menu->entities[1], Title.h, Title.w);
    for (int i = 2; i < 5; i++)
    {
        entity(texts.x, texts.y + texts.h * 2 * (i - 1), text_textures[i - 1], &menu->entities[i], texts.h, texts.w);
    }
}
void Menu_render(Menu *menu, RenderW *RenderWindow)
{
    for (int i = 0; i < 5; i++)
    {
        render(&menu->entities[i], RenderWindow, 0);
    }
}
void Menu_Cleanup(Menu *menu)
{
    for (int i = 0; i < 5; i++)
    {
        cleanEntity(&menu->entities[i]);
    }
}