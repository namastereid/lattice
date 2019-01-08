#include <iostream>
#include <SDL.h>
#include <chrono>
#include <thread>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Lattice", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (window == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr){
        SDL_DestroyWindow(window);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }


    //A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
    for (int i = 0; i < 3; ++i){
        //First clear the renderer
        SDL_RenderClear(ren);
        //Update the screen
        SDL_RenderPresent(ren);
        //Take a quick break after all that hard work
        SDL_Delay(1000);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << "Finished!" << std::endl;

    SDL_Quit();

    return 0;
}