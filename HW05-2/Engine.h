//
// Created by Kevin on 2016/10/31.
//

#ifndef HW05_2_ENGINE_H
#define HW05_2_ENGINE_H

#endif //HW05_2_ENGINE_H

#include <iostream>

class Car; //避免重複定義，告知有外部類別

using namespace std;

class Engine
{

private:

    int CC;
    int type;
    int weight;

public:

    Engine();

    Engine(const int &c, const int &t, const int &w);

    ~Engine();

    Engine(const Engine &e);

    Engine &operator=(const Engine &e);

    Engine(Engine &&e);

    Engine &operator=(Engine &&e);

    //friend class Car;

    friend void check_engine(Car &car);

    friend ostream &operator<<(ostream &os, Engine &e);

    friend ostream &operator<<(ostream &os, Car &car);

    friend class Car;

};

Engine::Engine()
{
    //default constructor
    //cout << "default costructor" << endl;
}

Engine::Engine(const int &c, const int &t, const int &w)
{
    //non default constructor
    //cout << "non default constructor" << endl;
    CC = c;
    type = t;
    weight = w;
}

Engine::~Engine()
{
    //destructor
    //cout << "destructor is called." << endl;
}


Engine::Engine(const Engine &e)
{

    //copy constructor
    //cout << "copy constructor is called." << endl;
    CC = e.CC;
    type = e.type;
    weight = e.weight;
}

Engine &Engine::operator=(const Engine &e)
{
    //assigment operator
    //cout << "assigment operator is called." << endl;
    CC = e.CC;
    type = e.type;
    weight = e.weight;

    return *this;
}

Engine::Engine(Engine &&e)
{
//move consructor
    //cout << "move constructor is called." << endl;

    CC = e.CC;
    type = e.type;
    weight = e.weight;
}

Engine &Engine::operator=(Engine &&e)
{

    //assigment operator
    //cout << "move assigment operator is called." << endl;
    CC = e.CC;
    type = e.type;
    weight = e.weight;

    return *this;
}

ostream &operator<<(ostream &os, Engine &e)
{
    os << "[CC] " << e.CC << " [Type] " << e.type << " [Weight] " << e.weight;
    return os;
}