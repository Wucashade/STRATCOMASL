#ifndef MAP_H
#define MAP_H

#include<iostream>
#include<fstream>
#include<string>
#include <vector>


#include <SDL.h> 
#include <SDL_image.h>

#include "../include/Menu.hpp"
#include "../include/Weapon.hpp"
#include "../include/Missile.hpp"

class Map{

    public:

        Map(){};
        ~Map();

        void init();
        void render();

        void renderBackground();
        void renderBorder();
        void renderUI();
        void renderMissiles();
        int getMapWidth(std::string fileName);
        int getMapHeight(std::string fileName);
        void moveMapUp();
        void moveMapDown();
        void moveMapLeft();
        void moveMapRight();
        void zoomIn();
        void zoomOut();
        void handleMouseButtonDown(SDL_MouseButtonEvent& b);

        static int mapTopLeftX;
        static int mapTopLeftY;
        static double mapScale;
        static int uIHeight;

        std::vector<Missile*> missiles;

    private:

    Menu* menu;
};

#endif