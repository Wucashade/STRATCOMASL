#include <iostream>
#include <string>
#include "../include/Map.hpp"

//Include SDL headers
#include<SDL.h>


class Window{

    public:

        Window();
        ~Window();

        void init(const char* title, int positionX, int positionY);
        bool running();
        void close();
        void update();
        void eventManager();
        void render();
        static SDL_Renderer* renderer;
        
    private:

        bool isRunning;
        SDL_Window* window;
        Map* map;
        

};