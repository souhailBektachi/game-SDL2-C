#include "game.h"

void gameInit(game *game, const char *title)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        printf("SDL INIT HAS FAILED %s", SDL_GetError());
        game->isRunning = false;
    }
    else
    {
        if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
        {
            fprintf(stderr, "Unable to initialize SDL_image: %s\n", IMG_GetError());
        }
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
        RenderWindow(title, SCREEN_WIDTH, SCREEN_HEIGHT, &game->window);
        game->isRunning = true;
    }
    SDL_Texture *playerTextures[5] = {loadtexture("assets/gfx/run.png", &game->window), loadtexture("assets/gfx/runUP.png", &game->window), loadtexture("assets/gfx/rundown.png", &game->window), loadtexture("assets/gfx/runUpToLeft.png", &game->window), loadtexture("assets/gfx/runDownLeft.png", &game->window)};

    SDL_Texture *Balltexture = loadtexture("assets/gfx/ball.png", &game->window);
    character(200, 271, playerTextures, &game->player, 10);
    const char *mapAssets[2] = {"assets/maps/firstlevel.csv", "assets/maps/secondlevel.csv"};
    SDL_Texture *maptexture[2] = {loadtexture("assets/gfx/map.png", &game->window), loadtexture("assets/gfx/dungeontileset-extended.png", &game->window)};
    const char *mapWalls[2] = {"assets/maps/secondlevelwalls.csv", "assets/maps/secondlevelwalls.csv"};
    game->themap->mapTextureHW[0] = 23;
    game->themap->mapTextureHW[1] = 64;

    for (int i = 0; i < 2; i++)
    {
        map(maptexture[i], mapAssets[i], &game->themap[i], mapWalls[i]);
        createMap(&game->themap[i]);
    }
    ball(200, 200, Balltexture, &game->theball, 3, M_PI / 4);
    game->mapindex = 1;
}

void handleEvents(game *game)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {

        const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);

        if (event.type == SDL_QUIT)
        {
            game->isRunning = false;
        }

        if (keyboardState[SDL_SCANCODE_UP] && keyboardState[SDL_SCANCODE_RIGHT])
        {
            entity_setTex(&game->player.character, game->player.textures[3]);
            game->player.character.isflipped = 1;
            movecharacter(-M_PI / 4, &game->player, &game->themap[game->mapindex]);
        }
        else if (keyboardState[SDL_SCANCODE_UP] && keyboardState[SDL_SCANCODE_LEFT])
        {
            entity_setTex(&game->player.character, game->player.textures[3]);
            game->player.character.isflipped = 0;
            movecharacter(-(3 * M_PI) / 4, &game->player, &game->themap[game->mapindex]);
        }
        else if (keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_RIGHT])
        {
            entity_setTex(&game->player.character, game->player.textures[4]);
            game->player.character.isflipped = 1;
            movecharacter(M_PI / 4, &game->player, &game->themap[game->mapindex]);
        }
        else if (keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_LEFT])
        {
            entity_setTex(&game->player.character, game->player.textures[4]);
            game->player.character.isflipped = 0;
            movecharacter((3 * M_PI) / 4, &game->player, &game->themap[game->mapindex]);
        }
        else if (keyboardState[SDL_SCANCODE_DOWN])
        {
            entity_setTex(&game->player.character, game->player.textures[2]);
            movecharacter(M_PI / 2.0, &game->player, &game->themap[game->mapindex]);
        }
        else if (keyboardState[SDL_SCANCODE_UP])
        {
            entity_setTex(&game->player.character, game->player.textures[1]);
            movecharacter(-M_PI / 2.0, &game->player, &game->themap[game->mapindex]);
        }
        else if (keyboardState[SDL_SCANCODE_LEFT])
        {
            entity_setTex(&game->player.character, game->player.textures[0]);
            movecharacter(M_PI, &game->player, &game->themap[game->mapindex]);
            game->player.character.isflipped = 1;
        }
        else if (keyboardState[SDL_SCANCODE_RIGHT])
        {
            entity_setTex(&game->player.character, game->player.textures[0]);
            movecharacter(0, &game->player, &game->themap[game->mapindex]);
            game->player.character.isflipped = 0;
        }

        if (event.type == SDL_KEYDOWN)
        {

            switch (event.key.keysym.sym)
            {
            case SDLK_v:

                set_rendered(&game->themap[game->mapindex], 0);
                game->mapindex = game->mapindex == 0 ? 1 : 0;

                break;
            case SDLK_r:
                entity_setpos(&game->player.character, 200, 200);

                reveive_character(&game->player);
                break;
            case SDLK_m:
                ball_setSpeed(&game->theball, ball_getSpeed(&game->theball) + 1);

                break;

            default:
                break;
            }
        }
    }
}
void renderGame(game *game)
{
    clear(&game->window);
    renderMap(&game->themap[game->mapindex], &game->window, game->themap->mapTextureHW[game->mapindex]);
    if (!isDead(&game->player))
    {
        render(&game->player.character, &game->window, game->player.character.isflipped);
    }
    render(&game->theball.ball, &game->window, 0);
    moveBall(&game->theball, &game->themap[game->mapindex], &game->player);
    display(&game->window);
}
void cleanGame(game *game)
{
    cleanUp(&game->window);
}
void update(game *game, double deltaTime)
{
    setDelta_time(&game->player.character, deltaTime);
    setDelta_time(&game->theball.ball, deltaTime);
}
