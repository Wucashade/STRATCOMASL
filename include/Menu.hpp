//Include SDL headers
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>

class Menu{
    public:

    Menu(){}
    ~Menu(){}

    void init();
    void render();

    void renderToolMenu

    bool getInfoMenuStatus();
    void setInfoMenuStatus(bool status);
    bool getToolMenuStatus();
    void setToolMenuStatus(bool status);

    private:

    bool infoMenuOn = 0;
    bool toolMenuOn = 0;
}