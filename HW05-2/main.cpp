#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include "Car.h"
#include "Police.h"

using namespace std;

void check_engine(Car &car)
{
    //global function
    cout << "##### check_engine #####" << endl;
    cout << car.my_engine << endl;
    cout << endl;
}

int main()
{
    srand(time(NULL));

    Engine myengine(1500, 2, 1);
    Car mycar(myengine);

    check_engine(mycar);
    mycar.check_my_engine();

    //call static function in class police to show engine information
    Police::check_car(mycar);

    int num_of_cars = 10; //how many car object to generate

    vector<Car> cv;

    for (int i = 0; i < num_of_cars; i++)
    {
        Engine engine_temp(rand() % 1000 + 1000, rand() % 3 + 1, 1);
        cv.push_back(Engine(engine_temp));
    }


    cout << "\n----------Original Cars----------" << endl;

    //display all cars sequentially
    for (int i = 0; i < num_of_cars; i++)
    {
        cout << cv[i] << endl;
    }

    //sort by CC
    sort(cv.begin(), cv.end());

    cout << "\n----------After Sorting----------" << endl;
    //display sorted vector
    for (int i = 0; i < num_of_cars; i++)
    {
        cout << cv[i] << endl;
    }

    return 0;
}