#include <iostream>
#include <SDL.h>
#include "../include/Window.hpp"

int main(){
    Window* window = new Window();
    window->init("STRATCOMALS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    while(window->running() == 1){
        window->eventManager();
        window->render();
    }

    window->close();
    delete(window);

    return 0;
}