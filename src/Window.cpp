#include "../include/Window.hpp"


SDL_Renderer* Window::renderer = nullptr;

Window::Window(){};

Window::~Window(){};



void Window::init(const char* title, int positionX, int positionY){
    //Attempt to initialise SDL subsystems
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystems initialised" << '\n';
        //Create a window
        window = SDL_CreateWindow(title, positionX, positionY, 1280, 720, SDL_WINDOW_RESIZABLE);
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