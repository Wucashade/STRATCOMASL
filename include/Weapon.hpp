#ifndef WEAPON_H
#define WEAPON_H


#include <string>

class Weapon{

    public:

        Weapon(std::string name, int range, double weight);
        ~Weapon();

        std::string getName();
        int getRange();
        int getWeight();
        void setName(std::string newName);
        void setRange(int newRange);
        void setWeight(double newWeight);

    private:
        std::string name;
        int range;
        double weight;
};

#endif