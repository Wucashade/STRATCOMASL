#include "../include/Map.hpp"
#include "../include/Window.hpp"

void Map::init(){

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

    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            
            newPixel.x = w;
            newPixel.y = h;

            //Get coordinates of pixels
            pixel = *((Uint32*)surface->pixels + h * surface->pitch / 4 + w);
            SDL_GetRGB(pixel, surface->format, &red, &green, &blue);

            if(red == 0 && green == 0 && blue == 0 ){
                SDL_SetRenderDrawColor(Window::renderer, 34,139,34, 255);
            }
            else if(red == 21 && green == 152 && blue == 255){
                SDL_SetRenderDrawColor(Window::renderer, 0,0,0, 255);
            }

            SDL_RenderDrawRect(Window::renderer, &newPixel);
        }
    }


}

void Map::renderBorder(){

}