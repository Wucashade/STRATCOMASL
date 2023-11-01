#include <iostream>
#include <string>
#include "../include/Map.hpp"
#include "../include/Menu.hpp"

//Include SDL headers
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>



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
        void resize(int newWidth, int newHeight);

        static int windowHeight;
        static int windowWidth;

        static SDL_Renderer* renderer;
        
    private:

        bool isRunning;
        SDL_Window* window;
        Map* map;
        Menu* menu;
        

};