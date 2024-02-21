#ifndef MISSILE_H
#define MISSILE_H

#include "../include/Weapon.hpp"
#include <queue>
#include <utility>

class Missile: public Weapon{
    public:
        Missile(std::string name, int range, double weight, int posX, int posY, double speed);
        ~Missile(){};

        void fly();

        int getPosX();
        int getPosY();
        double getSpeed();
        std::pair<int,int> getFrontPair();

        void setPosX(int newPosX);
        void setPosY(int newPosY);
        void setSpeed(int newSpeed);
        void enqueueWaypoint(int x, int y);
        void dequeueWaypoint();
        void moveMissile(){};

    private:

        int posX;
        int posY;
        double speed;
        std::queue<std::pair<int, int> > waypoints;

};

#endif