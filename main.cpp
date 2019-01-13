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
    SDL_CreateWindowAndRenderer(1024, 768, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 200, 200, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Event event;

    bool loop = true;
    do
    {
        std::cout << "event type: " << event.type << std::endl;
        switch(event.type) {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        loop = false;
                        break;
                    default:break;
                }
                break;
            case SDL_QUIT:
                loop = false;
                break;
            default:break;
        }
    }
    while(SDL_WaitEvent(&event) && loop);

    SDL_Quit();
    return 0;
}