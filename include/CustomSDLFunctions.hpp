#ifndef CUSTOMSDLFUNCTIONS_H
#define CUSTOMSDLFUNCTIONS_H

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>

#include<string>



double calculateAngle(int xOrg, int xDes, int yOrg, int yDes);

void drawFilledRect(SDL_Renderer* renderer,int width, int height, int xPos, int yPos, SDL_Color colour);
void drawSolidText(SDL_Renderer* renderer, TTF_Font* font, std::string text, 
                                SDL_Color textColour, int width, int height, int xPos, int yPos);
void drawImage(SDL_Renderer* renderer, std::string imagePath, int posX, int posY);
void drawImageWithAngle(SDL_Renderer* renderer, std::string imagePath, int posX, int posY, int destPosX, int destPosY);




#endif