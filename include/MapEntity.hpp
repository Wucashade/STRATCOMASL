#ifndef MAPENTITY_H
#define MAPENTITY_H

#include<string>

class MapEntity{

    public:

    MapEntity(std::string name, int posX, int posY);
    ~MapEntity();

    std::string getName();
    int getPosX();
    int getPosY();
    void setName(std::string newName);
    void setPosX(int x);
    void setPosY(int y);

    private:

    std::string name;
    int posX;
    int posY;

};

#endif