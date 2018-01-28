//
// Created by Kevin on 2016/10/31.
//

#ifndef HW05_2_CAR_H
#define HW05_2_CAR_H

#endif //HW05_2_CAR_H

#include <iostream>
#include "Engine.h"

using namespace std;

class Car
{

private:

    Engine my_engine;

public:

    Car(const Engine &my_engine);

    void check_my_engine();

    friend void check_engine(Car &car);

    bool operator<(const Car &car);

    friend ostream &operator<<(ostream &os, Car &car);
};


void Car::check_my_engine()
{
    cout << "##### check_my_engine #####" << endl;
    cout << my_engine << endl;

    cout << endl;
}


bool Car::operator<(const Car &car2)
{
    if (this->my_engine.CC < car2.my_engine.CC)
    {
        return true;
    }
    return false;
}

Car::Car(const Engine &my_engine) : my_engine(my_engine)
{

}

ostream &operator<<(ostream &os, Car &car)
{
    os << "[CC] " << car.my_engine.CC << " [Type] " << car.my_engine.type << " [Weight] " << car.my_engine.weight;
    return os;
}
