//
// Created by Kevin on 2016/10/31.
//

#ifndef HW05_2_POLICE_H
#define HW05_2_POLICE_H

#endif //HW05_2_POLICE_H

class Car;

class Police{

public:
    static void check_car(Car &car);
};

void Police::check_car(Car &car){

    cout << "police ";
    check_engine(car);
}