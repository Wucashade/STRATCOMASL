#include "../include/CustomSDLFunctions.hpp"

void drawFilledRect(SDL_Renderer* renderer,int width, int height, int xPos, int yPos, SDL_Color colour){
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_Rect rect;
    rect.w = width;
    rect.h = height;
    rect.x = xPos;
    rect.y = yPos;
    SDL_RenderFillRect(renderer, &rect);
}