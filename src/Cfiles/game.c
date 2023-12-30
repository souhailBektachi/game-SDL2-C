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

    SDL_Texture *playerTextures[5] = {loadtexture("assets/gfy/run.png", &game->window), loadtexture("assets/gfy/runUP.png", &game->window), loadtexture("assets/gfy/rundown.png", &game->window), loadtexture("assets/gfy/runUpToLeft.png", &game->window), loadtexture("assets/gfy/runDownLeft.png", &game->window)};

    SDL_Texture *Balltexture = loadtexture("assets/gfx/ball.png", &game->window);
    character(200, 271, playerTextures, &game->player, 600);
    const char *mapAssets[2] = {"assets/maps/firstlevel.csv", "assets/maps/secondlevel2.csv"};
    SDL_Texture *maptexture[2] = {loadtexture("assets/gfx/map.png", &game->window), loadtexture("assets/gfx/dungeontileset-extended.png", &game->window)};
    const char *mapWalls[2] = {"assets/maps/secondlevelwalls.csv", "assets/maps/secondlevelwalls.csv"};
    game->themap->mapTextureHW[0] = 23;
    game->themap->mapTextureHW[1] = 64;

    for (int i = 0; i < 2; i++)
    {
        map(maptexture[i], mapAssets[i], &game->themap[i], mapWalls[i], 16, 16);
        createMap(&game->themap[i]);
    }
    int pos = 200;
    for (int i = 0; i < 1; i++)
    {
        ball(pos, pos, Balltexture, &game->theballs[i], 300, M_PI / 4);
        pos += 10;
    }

    game->mapindex = 1;
    game->ispaused = true;
    Set_mapTilesSize(&game->themap[game->mapindex], 32);
    SDL_Texture *menuTexts[4] = {loadtexture("assets/gfx/Menu/Title.png", &game->window), loadtexture("assets/gfx/Menu/Play.png", &game->window), loadtexture("assets/gfx/Menu/Level maker.png", &game->window), loadtexture("assets/gfx/Menu/EXIT.png", &game->window)};
    Menu_init(&game->themenu, loadtexture("assets/gfx/Menu/Background.png", &game->window), menuTexts, (SDL_Rect){28, 95, 423, 48}, (SDL_Rect){207, 225, 66, 29});
    game->themenu.entities[3].currentFrame.w = 171;
    game->themenu.entities[3].destFrame.w = 171;
    entity_setpos(&game->themenu.entities[3], 155, entity_getpos(&game->themenu.entities[3]).y);
    SDL_Texture *speedertex = loadtexture("assets/gfx/speeder.png", &game->window);
    speeder_init(&game->Speeder, &game->themap[game->mapindex], speedertex, 255, 255, 32, 32, 4);
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
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            vector2d ButtonPos = game->themenu.entities[2].pos;
            vector2d mousePos;
            mousePos.x = event.button.x;
            mousePos.y = event.button.y;
            if (mousePos.x > ButtonPos.x && mousePos.x < ButtonPos.x + 66 && mousePos.y > ButtonPos.y && mousePos.y < ButtonPos.y + 29)
            {
                game->ispaused = false;
            }
        }
        if (!keyboardState[SDL_SCANCODE_UP] && !keyboardState[SDL_SCANCODE_DOWN] && !keyboardState[SDL_SCANCODE_LEFT] && !keyboardState[SDL_SCANCODE_RIGHT])
        {
            game->player.cycle = 0;
            Character_animate(&game->player);
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
                entity_setpos(&game->player.character, 32, 32);

                reveive_character(&game->player);
                break;
            case SDLK_m:
                ball_setSpeed(&game->theballs[0], ball_getSpeed(&game->theballs[0]) + 100);

                break;
            case SDLK_p:
                game->ispaused = !game->ispaused;
                break;

            default:
                break;
            }
        }
    }
}
void renderGame(game *game)
{
    if (game->ispaused)
    {
        clear(&game->window);
        Menu_render(&game->themenu, &game->window);
        display(&game->window);
    }
    else
    {

        clear(&game->window);
        renderMap(&game->themap[game->mapindex], &game->window, game->themap->mapTextureHW[game->mapindex]);
        render(&game->Speeder.speeder, &game->window, 0);
        if (!isDead(&game->player))
        {
            render(&game->player.character, &game->window, game->player.character.isflipped);
        }

        for (int i = 0; i < 1; i++)
        {
            render(&game->theballs[i].ball, &game->window, 0);
        }

        for (int i = 0; i < 1; i++)
        {
            moveBall(&game->theballs[i], &game->themap[game->mapindex], &game->player, game->theballs, i);
        }

        display(&game->window);
    }
}
void cleanGame(game *game)
{
    cleanUp(&game->window);
    cleanBall(&game->theballs[0]);
    cleanEntity(&game->player.character);
    cleanCharacter(&game->player);
    cleanMap(&game->themap[0]);
}
void update(game *game, double deltaTime)
{
    static int i = 0;
    if (i > 60)
    {
        i = 0;
    }
    if (i % 5 == 0)
    {
        game->player.cycle++;
        if (game->player.cycle > 3)
        {
            game->player.cycle = 0;
        }
    }
    setDelta_time(&game->player.character, deltaTime);
    for (int i = 0; i < 10; i++)
    {
        setDelta_time(&game->theballs[i].ball, deltaTime);
    }
    accelerate(&game->Speeder, &game->player);
    if (game->player.isAccelerated)
    {
        movecharacter(0, &game->player, &game->themap[game->mapindex]);
    }
    i++;
}
