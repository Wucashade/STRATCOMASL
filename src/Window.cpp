#include "../include/Window.hpp"


SDL_Renderer* Window::renderer = nullptr;

int Window::windowHeight = 1080;
int Window::windowWidth = 1920;

Window::Window(){};

Window::~Window(){};



void Window::init(const char* title, int positionX, int positionY){
    //Attempt to initialise SDL subsystems
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        TTF_Init();
        IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
        std::cout << "Subsystems initialised" << '\n';
        //Create a window
        window = SDL_CreateWindow(title, positionX, positionY, Window::windowWidth, Window::windowHeight, SDL_WINDOW_RESIZABLE);
        if(window == NULL){
            std::cout << "Window cannot be created, SDL_Error" << SDL_GetError() << '\n';
            isRunning = 0;
        }
        else{
            std::cout << "Window created" << '\n';
            //Create a renderer
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(renderer == NULL){
                std::cout << "Renderer cannot be created, SDL_Error" << SDL_GetError() << '\n';
                isRunning = 0;
            }
            else{
                std::cout << "Renderer created" << '\n';
                SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
                map = new Map();
                map->init();
                isRunning = 1;
                
            }
        }
        
        
    }else{

        std::cout << "SDL didn't initialize, SDL_Error: " << SDL_GetError() << '\n';
        isRunning = 0;
    }
}

void Window::update(){

}

void Window::render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderClear(renderer);

    map->render();

    SDL_RenderPresent(renderer);
}

void Window::eventManager()
{

    // Manages events that relate to SDL 

    SDL_Event windowEvent;
    while (SDL_PollEvent(&windowEvent))
    {
        switch (windowEvent.type)
        {
            case SDL_QUIT:
                isRunning = 0;
                break;
            case SDL_WINDOWEVENT:
                if (windowEvent.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) 
                {
                    resize(windowEvent.window.data1, windowEvent.window.data2);
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                map->handleMouseButtonDown(windowEvent.button);
                break;
            case SDL_KEYDOWN:
                switch(windowEvent.key.keysym.sym){
                    case SDLK_UP:
                        map->moveMapUp();
                        break;
                    case SDLK_DOWN:
                        map->moveMapDown();
                        break;
                    case SDLK_RIGHT:
                        map->moveMapRight();
                        break;
                    case SDLK_LEFT:
                        map->moveMapLeft();
                        break;
                    case SDLK_EQUALS:
                        map->zoomIn();
                        break;
                    case SDLK_MINUS:
                        map->zoomOut();
                        break;
                    
                    default:
                        break;
                }
                break;
                
            default:
                break;

        }
    }
}

void Window::close(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Window::running(){
    return isRunning;
}

void Window::resize(int newWidth, int newHeight)
{
    Window::windowHeight = newHeight;
    Window::windowWidth = newWidth;
}
