#ifndef CUSTOMSDLFUNCTIONS_H
#define CUSTOMSDLFUNCTIONS_H

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>

#include<string>

void drawFilledRect(SDL_Renderer* renderer,int width, int height, int xPos, int yPos, SDL_Color colour);
void drawSolidText(SDL_Renderer* renderer, TTF_Font* font, std::string text, 
                                SDL_Color textColour, int width, int height, int xPos, int yPos);





#endif