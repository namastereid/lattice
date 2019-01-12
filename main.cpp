#include <iostream>
#include <SDL.h>
#include <chrono>
#include <thread>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 3;
    }

    SDL_SetRenderDrawColor(renderer, 0, 200, 200, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Event event;

    do
    {
//        std::cout << "event type: " << event.type << std::endl;
        int type = event.type;
        if(type == SDL_KEYDOWN || type == SDL_QUIT) {
            break;
        }
    }
    while(SDL_WaitEvent(&event));

    SDL_Quit();
    return 0;
}