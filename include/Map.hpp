#ifndef MAP_H
#define MAP_H

#include<iostream>
#include<fstream>
#include<string>

#include <SDL.h>
#include <SDL_image.h>

#include "../include/Menu.hpp"

class Map{

    public:

        Map(){};
        ~Map(){};

        void init();
        void render();

        void renderBackground();
        void renderBorder();
        void renderUI();
        int getMapWidth(std::string fileName);
        int getMapHeight(std::string fileName);
        void moveMapUp();
        void moveMapDown();
        void moveMapLeft();
        void moveMapRight();
        void zoomIn();
        void zoomOut();

        static int mapTopLeftX;
        static int mapTopLeftY;
        static double mapScale;
        static int uIHeight;

    private:

    Menu* menu;
};

#endif