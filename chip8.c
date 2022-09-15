#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char const *argv[])
{
    SDL_Window *window;

    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(
        "test window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        500,
        500,
        SDL_WINDOW_OPENGL
    );

    if (window == NULL) {
        printf("failed to create window.");
        return 1;
    }

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 0;
        }
    }

    SDL_Delay(10000);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
