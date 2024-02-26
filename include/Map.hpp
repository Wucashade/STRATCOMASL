#ifndef MAP_H
#define MAP_H

#define _USE_MATH_DEFINES

#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <cmath>

#include <SDL.h> 
#include <SDL_image.h>

#include <osmium/io/pbf_input.hpp>
#include <osmium/geom/coordinates.hpp>
#include <osmium/io/any_input.hpp>
#include <osmium/handler.hpp>
#include <osmium/visitor.hpp>
#include <osmium/osm/node.hpp>
#include <osmium/geom/coordinates.hpp>
#include <osmium/geom/mercator_projection.hpp>
#include <osmium/index/map/sparse_mem_array.hpp>
#include <osmium/handler/node_locations_for_ways.hpp>

using index_t = osmium::index::map::SparseMemArray<osmium::unsigned_object_id_type, osmium::Location>;
using cache_t = osmium::handler::NodeLocationsForWays<index_t>;

#include "../include/Menu.hpp"
#include "../include/Weapon.hpp"
#include "../include/Missile.hpp"
#include "../include/OsmDataHandler.hpp"

#define TILE_SIZE 256
#define CIRCUMFERENCE 40007863
#define PIXELS_PER_DEGREE TILE_SIZE/360
#define PIXELS_PER_RADIAN TILE_SIZE/(2 * M_PI)
#define ORIGIN TILE_SIZE/2


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
        int getMapWidth(std::string fileName);
        int getMapHeight(std::string fileName);
        void moveMapUp();
        void moveMapDown();
        void moveMapLeft();
        void moveMapRight();
        void zoomIn();
        void zoomOut();
        void handleMouseButtonDown(SDL_MouseButtonEvent& b);
        int convertLongitudeToX(double longitude);
        int convertLatitudeToY(double latitude);

        void setMouseClickPos(int x, int y);
        int getMouseClickPosX();
        int getMouseClickPosY();

        static int mapTopLeftX;
        static int mapTopLeftY;
        static double zoomLevel;
        static int uIHeight;
        const double metersPerPixel = CIRCUMFERENCE / (TILE_SIZE * zoomLevel);;

        std::vector<Missile*> missiles;

    private:

    OsmDataHandler handler;
    Menu* menu;
    int lastMousePosX;
    int lastMousePosY;
};

#endif