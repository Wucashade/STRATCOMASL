#include "../include/CustomSDLFunctions.hpp"
#include <iostream>
#include <stdexcept> 

void drawFilledRect(SDL_Renderer* renderer,int width, int height, int xPos, int yPos, SDL_Color colour){
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_Rect rect;
    rect.w = width;
    rect.h = height;
    rect.x = xPos;
    rect.y = yPos;
    SDL_RenderFillRect(renderer, &rect);
}

void drawSolidText(SDL_Renderer* renderer, TTF_Font* font, std::string text, SDL_Color textColour, int width, int height, int xPos, int yPos){
    SDL_Rect rect;
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), textColour);
    if(!surface){
        throw std::runtime_error("Failed to create text surface");
    }
    SDL_Texture* words = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!words) {
        throw std::runtime_error("Failed to create texture from text surface");
    }
    rect.w = width;
    rect.h = height;
    rect.x = xPos;
    rect.y = yPos;
    SDL_RenderCopy(renderer, words, NULL, &rect);
    SDL_DestroyTexture(words);

}

void drawImage(SDL_Renderer* renderer, std::string imagePath, int posX, int posY){
    SDL_Rect rect;
    SDL_Surface* surface = IMG_Load(imagePath.c_str());
    if(!surface){
        throw std::runtime_error("Failed to create text surface");
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        throw std::runtime_error("Failed to create texture from text surface");
    }
    
    rect.w = surface->w;
    rect.h = surface->h;
    rect.x = posX - (surface->w /2);
    rect.y = posY - (surface->h /2);
    
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    // SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    

    
}