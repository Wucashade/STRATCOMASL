#ifndef MAP_H
#define MAP_H

#include<iostream>
#include<fstream>

#include <SDL.h>
#include <SDL_image.h>

class Map{

    public:

        Map(){};
        ~Map(){};

        void init();
        void render();

        void renderBackground();
        void renderBorder();

    private:


};

#endif