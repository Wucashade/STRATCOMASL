#include "../include/Menu.hpp"
#include "../include/Window.hpp"
#include "../include/CustomSDLFunctions.hpp"


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
    
    TTF_Font* uiFont = TTF_OpenFont("../fonts/abel/abel-regular.ttf", 64);
    if (!uiFont) {
        throw std::runtime_error("Failed to open font '" + std::string("../fonts/abel/abel-regular.ttf") + "': " + TTF_GetError());
    }
    
    
    drawFilledRect(Window::renderer, 150, 300, getMouseClickPosX(), getMouseClickPosY(), {120,120,120,255});
    drawSolidText(Window::renderer, uiFont, "CREATE", {0,0,0,255}, 150, 50, getMouseClickPosX(), getMouseClickPosY());
    
}

void Menu::handleMouseButtonDown(SDL_MouseButtonEvent& b){
    
    if(b.button == SDL_BUTTON_RIGHT){
        int x, y;
        SDL_GetMouseState(&x, &y);
        setMouseClickPos(x,y);
        setToolMenuStatus(1);
        std::cout << getMouseClickPosX();
    }else if(b.button == SDL_BUTTON_LEFT && getToolMenuStatus() == 1){
        setToolMenuStatus(0);
    }
    
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
