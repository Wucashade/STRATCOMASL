#ifndef MENU_H
#define MENU_H

//Include SDL headers

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>

class Menu{
    public:

    Menu();
    ~Menu();

    void render();
    void renderToolMenu();

    bool getInfoMenuStatus();
    void setInfoMenuStatus(bool status);
    bool getToolMenuStatus();
    void setToolMenuStatus(bool status);
    void setMouseClickPos(int x, int y);
    int getMouseClickPosX();
    int getMouseClickPosY();


    void handleMouseButtonDown(SDL_MouseButtonEvent& b);

    private:

    bool infoMenuOn;
    bool toolMenuOn;
    int lastMousePosX;
    int lastMousePosY;
    
};

#endif