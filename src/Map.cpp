#include "../include/Map.hpp"
#include "../include/Window.hpp"

void Map::init(){

}

void Map::render(){
    renderBackground();
    renderBorder();
}

void Map::renderBackground(){
    int h,w;

    SDL_Surface* surface = SDL_LoadBMP("../images/map/landMap.bmp");
    w = surface->w;
    h = surface->h;

    std::cout<< "Width " << w << "Height " << h << "\n";
}

void Map::renderBorder(){

}