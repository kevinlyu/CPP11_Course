//
// Created by Kevin on 2016/11/16.
//

#ifndef HW09_TRADE_DATE_H
#define HW09_TRADE_DATE_H

#include <tuple>

using namespace std;

class TRADE_DATE
{
public:
    int ID;
    tuple<int, int, int> begin_date;
    tuple<int, int, int> end_date;
    int duration; //number of days in this period



    TRADE_DATE(int);

    void display();

    bool operator<(const TRADE_DATE &) const;

    void operator+(int dur);

    void operator-(int dur);

    static int dur_calculate(tuple<int, int, int> &t1, tuple<int, int, int> &t2);

};

#endif //HW09_TRADE_DATE_H


