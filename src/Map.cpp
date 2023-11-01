#include "../include/Map.hpp"
#include "../include/Window.hpp"


int Map::mapTopLeftX;
int Map::mapTopLeftY;
double Map::mapScale;
int Map::uIHeight;

void Map::init(){
    mapTopLeftX = mapTopLeftY = 0;
    mapScale = 1;
    uIHeight = 50;
    menu = new Menu();
}

void Map::render(){
    renderBackground();
    renderBorder();
    renderUI();
    menu->render();
}

void Map::renderBackground(){
    int height,width;
    Uint8 red,green,blue = 0;
    SDL_Rect newPixel;
    Uint32 pixel;
    int rgb[3];

    //Set width and height of drawn rectangle
    newPixel.h = (1 * mapScale);
    newPixel.w = (1 * mapScale);

    SDL_Surface* surface = SDL_LoadBMP("../images/map/landMap.bmp");

    
    //Get the dimensions of image
    width = surface->w;
    height = surface->h;

    //Draw the map based on the bmp file loaded
    for(int i = 0; i < ((Window::windowHeight - uIHeight) / mapScale); i++){
        for(int j = 0; j < (Window::windowWidth / mapScale); j++){

            //Set coordinates of new pixel
            newPixel.x = j * mapScale;
            newPixel.y = (i + uIHeight) * mapScale;

            //Get coordinates of pixels to check colour
            pixel = *((Uint32*)surface->pixels + (mapTopLeftY + i) * surface->pitch / 4 + (mapTopLeftX + j));
            SDL_GetRGB(pixel, surface->format, &red, &green, &blue);

            if(red == 0 && green == 0 && blue == 0 ){
                SDL_SetRenderDrawColor(Window::renderer, 34,139,34, 255);
            }
            else if(red == 21 && green == 152 && blue == 255){
                SDL_SetRenderDrawColor(Window::renderer, 0,0,0, 255);
            }

            SDL_RenderFillRect(Window::renderer, &newPixel);
            //SDL_RenderDrawPoint(Window::renderer, (j * mapScale), (i * mapScale));

        }
    }
    SDL_FreeSurface(surface);

}

void Map::renderUI(){
    SDL_Rect userInterface;

    userInterface.w = Window::windowWidth;
    userInterface.h = uIHeight;
    userInterface.x = 0;
    userInterface.y = 0;

    SDL_SetRenderDrawColor(Window::renderer, 100,100,100, 255);

    SDL_RenderFillRect(Window::renderer, &userInterface);


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
    int tempMove = mapTopLeftY - 10;
    if(tempMove > 0 ){
        mapTopLeftY = tempMove;
    }
}
void Map::moveMapDown(){
    int tempMove = mapTopLeftY + 10;
    if(tempMove < (getMapHeight("../images/map/landMap.bmp") - ((Window::windowHeight + uIHeight) / mapScale))){
        mapTopLeftY = tempMove;
        std::cout << mapTopLeftY << "\n";
    }
}
void Map::moveMapLeft(){
    int tempMove = mapTopLeftX - 10;
    if(tempMove > 0 ){
        mapTopLeftX = tempMove;
    }
}
void Map::moveMapRight(){
    int tempMove = mapTopLeftX + 10;
    if(tempMove < (getMapWidth("../images/map/landMap.bmp") - (Window::windowWidth / mapScale))){
        mapTopLeftX = tempMove;
    }
}

void Map::zoomIn(){
    if(mapScale < 4){
        mapScale = mapScale + 1;
        std::cout << "Zoomed in" << "\n";
    }
}

void Map::zoomOut(){
    if(mapScale > 1){
        mapScale = mapScale - 1;
        std::cout << "Zoomed out" << "\n";
    }
}