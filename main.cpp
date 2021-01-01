#include <SDL2/SDL.h>
#include <stdio.h>

SDL_Renderer *gRenderer = NULL;
SDL_Window *gWindow = NULL;
int SCREEN_SIZE = 100;

bool init_display()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "initialize_display - SDL_Init: %s\n",
                     SDL_GetError());
        return false;
    }

    if (SDL_CreateWindowAndRenderer(SCREEN_SIZE, SCREEN_SIZE, 0, &gWindow, &gRenderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "initialize_display - SDL_CreateWindowAndRenderer - %s\n",
                     SDL_GetError());
        return false;
    }

    return true;
}

void display_grid(int grid[][GRID_SIZE], int size) {}
void handle_events(int grid[][GRID_SIZE], int size) {}
void close() {}

int main(int argc, char const *argv[])
{
    if (!init_display())
    {
        return 1;
    }

    while (user_hasnt_quit)
    {
        handle_user_input();

        update_game_state();

        render_graphics();
    }
    return 0;
}
