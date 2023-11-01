#include "../include/Menu.hpp"
#include "../include/Window.hpp"


Menu::Menu(){
    infoMenuOn = 0;
    toolMenuOn = 0;
    lastMousePosX = 0;
    lastMousePosY = 0;
}

void Menu::render(){
    if(toolMenuOn == 1){
        renderToolMenu();
    }
}

void Menu::renderToolMenu(){
    SDL_Rect toolMenu;
    buildRect(toolMenu, 100, 100, getMouseClickPosX(), getMouseClickPosY());
    SDL_SetRenderDrawColor(Window::renderer, 120,120,120, 255);
    SDL_RenderFillRect(Window::renderer, &toolMenu);
}

void Menu::handleMouseButtonDown(SDL_MouseButtonEvent& b){
    if(b.button == SDL_BUTTON_LEFT){
        int x, y;
        SDL_GetMouseState(&x, &y);
        setMouseClickPos(x,y);
        setToolMenuStatus(1);
        std::cout << getMouseClickPosX();
    }
    
}

void Menu::buildRect(SDL_Rect& box, int width, int height, int xPos, int yPos){
    box.w = width;
    box.h = height;
    box.x = xPos;
    box.y = yPos;
}

bool Menu::getInfoMenuStatus(){
    return infoMenuOn;
}

void Menu::setInfoMenuStatus(bool status){
    infoMenuOn = status;
}

bool Menu::getToolMenuStatus(){
    return toolMenuOn;
}

void Menu::setToolMenuStatus(bool status){
    toolMenuOn = status;
}

void Menu::setMouseClickPos(int x, int y){
    lastMousePosX = x;
    lastMousePosY = y;
}

int Menu::getMouseClickPosX(){
    return lastMousePosX;
}

int Menu::getMouseClickPosY(){
    return lastMousePosY;
}
