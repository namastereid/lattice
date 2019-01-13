#include <iostream>
#include <SDL.h>
#include <chrono>
#include <thread>

void setupScreen(int width, int height, SDL_Window *window, SDL_Renderer *renderer) {
//    void setupScreen(SDL_Window *window, SDL_Renderer *renderer) {
//    std::cout << "Setting up screen: width - " << width << "  height - " << height << std::endl;
    window = SDL_CreateWindow("lattice", 0, 0, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
    renderer = SDL_CreateRenderer(window, 0, 0);
//    SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 200, 200, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
//    SDL_DisplayMode displayMode;
//    if (SDL_GetDesktopDisplayMode(0, &displayMode)) {
//        SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
//        return 1;
//    }
//    setupScreen(displayMode.w, displayMode.h, window, renderer);
    setupScreen(1920, 1080, window, renderer);
//setupScreen(window, renderer);

    SDL_Event event;

    bool loop = true;
    do {
        switch (event.type) {
            case SDL_MOUSEMOTION:
            case SDL_KEYMAPCHANGED:
                break;
            case SDL_KEYDOWN:
                std::cout << "keydown: ";
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        std::cout << "escape key" << std::endl;
                        loop = false;
                        break;
                    default:
                        std::cout << std::endl;
                        break;
                }
                break;
            case SDL_QUIT:
                std::cout << "quit event: " << event.type << std::endl;
                loop = false;
                break;
//            case SDL_WINDOW_MAXIMIZED:
//                std::cout << "window maximized: " << event.window.windowID << " Data: " << event.window.data1 << " "
//                          << event.window.data2 << std::endl;
//                break;
//            case SDL_WINDOWEVENT_RESIZED:
//                std::cout << "window resized: " << event.window.windowID << " Data: " << event.window.data1 << " "
//                          << event.window.data2 << std::endl;
//                break;
            case SDL_WINDOWEVENT:
//                std::cout << "window event: " << event.window.windowID << " Event: " << (int)event.window.event << std::endl;
                switch (event.window.event) {
                    case SDL_WINDOWEVENT_FOCUS_GAINED:
                    case SDL_WINDOWEVENT_FOCUS_LOST:
                    case SDL_WINDOWEVENT_MOVED:
                    case SDL_WINDOWEVENT_SHOWN:
                    case SDL_WINDOWEVENT_HIDDEN:
                    case SDL_WINDOWEVENT_EXPOSED:
                    case SDL_WINDOWEVENT_ENTER:
                    case SDL_WINDOWEVENT_LEAVE:
                    case SDL_WINDOWEVENT_CLOSE:
                    case SDL_WINDOWEVENT_TAKE_FOCUS:
                    case SDL_WINDOWEVENT_MAXIMIZED:
                        break;
                    case SDL_WINDOWEVENT_RESIZED:
                        std::cout << "window resized -- width: " << event.window.data1 << ", height: "
                                << event.window.data2 << std::endl;
                        break;
                    case SDL_WINDOWEVENT_RESTORED:
                        std::cout << "window restored -- width: " << event.window.data1 << ", height: "
                                << event.window.data2 << std::endl;
                        break;
                    case SDL_WINDOWEVENT_MINIMIZED:
                        std::cout << "window maximized -- width: " << event.window.data1 << ", height: "
                                << event.window.data2 << std::endl;
                        break;
                    case SDL_WINDOWEVENT_SIZE_CHANGED:
                        std::cout << "window size changed -- width: " << event.window.data1 << ", height: "
                                  << event.window.data2 << std::endl;
//                        setupScreen(event.window.data1, event.window.data2, window, renderer);
                        SDL_SetWindowSize(window, event.window.data1, event.window.data2);
                        SDL_Renderer
                        break;
//                    case SDL_WINDOWEVENT_RESIZED:
//                        std::cout << "window resized -- width: " << event.window.data1 << ", height: "
//                                  << event.window.data2 << std::endl;
//                        break;
//                    case SDL_WINDOWEVENT_MAXIMIZED:
//                        std::cout << "window maximized -- width: " << event.window.data1 << ", height: "
//                                  << event.window.data2 << std::endl;
//                        break;
//                    case SDL_WINDOWEVENT_MINIMIZED:
//                        std::cout << "window minimized -- width: " << event.window.data1 << ", height: "
//                                  << event.window.data2 << std::endl;
//                        break;
//                    case SDL_WINDOWEVENT_RESTORED:
//                        std::cout << "window restored -- width: " << event.window.data1 << ", height: "
//                                  << event.window.data2 << std::endl;
//                        break;
                    default:
                        std::cout << "window event id: " << (int) event.window.event << std::endl;
                }
                break;
            default:
                std::cout << "event type: 0x" << std::hex << event.type << std::endl;
                std::cout << std::dec;
                break;
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    } while (SDL_WaitEvent(&event) && loop);

    SDL_Quit();
    return 0;
}