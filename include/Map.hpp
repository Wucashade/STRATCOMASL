#ifndef MAP_H
#define MAP_H

#include<iostream>
#include<fstream>
#include<string>
#include <vector>

#include <SDL.h> 
#include <SDL_image.h>

#include <osmium/io/pbf_input.hpp>
#include <osmium/geom/coordinates.hpp>

#include "../include/Menu.hpp"
#include "../include/Weapon.hpp"
#include "../include/Missile.hpp"
#include "GeoLocation.hpp"
#include "CartesianLocation.hpp"

class Map{

    public:

        Map(){};
        ~Map();

        void init();
        void update();
        void render();

        void renderBackground();
        void renderBorder();
        void renderUI();
        void renderMissiles();

        CartesianLocation geoToCartesian(const GeoLocation& location);


        int getMapWidth(std::string fileName);
        int getMapHeight(std::string fileName);
        void moveMapUp();
        void moveMapDown();
        void moveMapLeft();
        void moveMapRight();
        void zoomIn();
        void zoomOut();
        void handleMouseButtonDown(SDL_MouseButtonEvent& b);
        static double calculatePixelDistance();

        static int mapTopLeftX;
        static int mapTopLeftY;
        static double mapScale;
        static int uIHeight;
        static double mapSize;

        std::vector<Missile*> missiles;

    private:

    Menu* menu;
};

#endif