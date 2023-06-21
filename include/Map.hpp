#ifndef MAP_H
#define MAP_H

#include<iostream>
#include<fstream>
#include<string>

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
        int getMapWidth(std::string fileName);
        int getMapHeight(std::string fileName);
        void moveMapUp();
        void moveMapDown();
        void moveMapLeft();
        void moveMapRight();

        static int mapTopLeftX;
        static int mapTopLeftY;

    private:


};

#endif