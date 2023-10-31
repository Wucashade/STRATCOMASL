#include <iostream>
#include <SDL.h>
#include "../include/Window.hpp"

const int FPS = 60;
const int FRAME_TIME_MS = 1000 / FPS;

int main(){
    Window* window = new Window();
    window->init("STRATCOMALS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    while(window->running() == 1){
        Uint32 frameStart = SDL_GetTicks();


        window->eventManager();
        window->render();

        Uint32 frameTime = SDL_GetTicks() - frameStart;
        if(frameTime < FRAME_TIME_MS){
            SDL_Delay(FRAME_TIME_MS-frameTime);
        }
    }

    window->close();
    delete(window);

    return 0;
}