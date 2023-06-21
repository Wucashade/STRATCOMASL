#include "../include/Map.hpp"
#include "../include/Window.hpp"

int Map::mapTopLeftX;
int Map::mapTopLeftY;

void Map::init(){
    mapTopLeftX = mapTopLeftY = 0;
}

void Map::render(){
    renderBackground();
    renderBorder();
}

void Map::renderBackground(){
    int height,width;
    Uint8 red,green,blue = 0;
    SDL_Rect newPixel;
    Uint32 pixel;
    int rgb[3];

    //Set width and height of drawn rectangle
    newPixel.h = 1;
    newPixel.w = 1;

    SDL_Surface* surface = SDL_LoadBMP("../images/map/landMap.bmp");

    
    //Get the dimensions of image
    width = surface->w;
    height = surface->h;

    for(int i = 0; i < Window::windowHeight; i++){
        for(int j = 0; j < Window::windowWidth; j++){
            
            
            
            newPixel.x = j;
            newPixel.y = i;

            //Get coordinates of pixels
            pixel = *((Uint32*)surface->pixels + (mapTopLeftY + i) * surface->pitch / 4 + (mapTopLeftX + j));
            SDL_GetRGB(pixel, surface->format, &red, &green, &blue);

            if(red == 0 && green == 0 && blue == 0 ){
                SDL_SetRenderDrawColor(Window::renderer, 34,139,34, 255);
            }
            else if(red == 21 && green == 152 && blue == 255){
                SDL_SetRenderDrawColor(Window::renderer, 0,0,0, 255);
            }

            SDL_RenderFillRect(Window::renderer, &newPixel);
        }
    }
    SDL_FreeSurface(surface);

}

void Map::renderBorder(){

}

int Map::getMapWidth(std::string fileName){
    SDL_Surface* surface = SDL_LoadBMP(fileName.c_str());
    int width = surface->w;
    SDL_FreeSurface(surface);
    return width;
}

int Map::getMapHeight(std::string fileName){
    SDL_Surface* surface = SDL_LoadBMP(fileName.c_str());
    int height = surface->h;
    SDL_FreeSurface(surface);
    return height;
}

void Map::moveMapUp(){
    int tempMove = mapTopLeftY - 20;
    if(tempMove > 0 ){
        mapTopLeftY = tempMove;
    }
}
void Map::moveMapDown(){
    int tempMove = mapTopLeftY + 20;
    if(tempMove < (getMapHeight("../images/map/landMap.bmp") - Window::windowHeight)){
        mapTopLeftY = tempMove;
    }
}
void Map::moveMapLeft(){
    int tempMove = mapTopLeftX - 20;
    if(tempMove > 0 ){
        mapTopLeftX = tempMove;
    }
}
void Map::moveMapRight(){
    int tempMove = mapTopLeftX + 20;
    if(tempMove < (getMapWidth("../images/map/landMap.bmp") - Window::windowWidth)){
        mapTopLeftX = tempMove;
    }
}