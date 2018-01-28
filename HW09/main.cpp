#include <iostream>
#include <vector>
#include <algorithm>
#include "functional"
#include "TRADE_DATE.h"

using namespace std;

const int n = 2;

vector<TRADE_DATE> v;

template<template<class...> class Container, class TObject>
void TD_generator(Container<TObject> &container)
{
    for (int i = 0; i < n; i++)
    {
        TRADE_DATE temp(i);
        container.push_back(temp);
    }
}

template<class T>
class functor
{
public :

    bool operator()(T &t1, T &t2)
    {
        return (t1 < t2);
    }
};


template<template<class ...> class Container, class T>
class intersection_finder
{
    void operator()(Container<T> &c, T t)
    {

        t.begin_date = t.begin_date - 11;
        auto lower = std::lower_bound(c.begin(), c.end(), t);
        t.begin_date = t.begin_date + 22;
        auto upper = std::upper_bound(c.begin(), c.end(), t);


        for (auto i = lower; i != upper; i++)
        {
            if (i->end_date < t.begin_date | i->begin_date > t.end_date | i->ID == t.ID)
            {
                continue;
            }

            cout << "TRADE_DATE OD: " << i->ID << " overlaps with TRADE_DATE_ID: " << i->ID << " by ";

            if (i->begin_date < t.begin_date && i->end_date >= t.end_date)
            {
                cout << TRADE_DATE::dur_calculate(i->end_date, t.begin_date);
            }

            else if (i->begin_date < t.begin_date && i->end_date >= t.end_date)
            {
                cout << TRADE_DATE::dur_calculate(t.end_date, t.begin_date);
            }

            else if (i->end_date < t.end_date)
            {
                cout << TRADE_DATE::dur_calculate(i->end_date, t.end_date);
            }

            else
            {
                cout << TRADE_DATE::dur_calculate(t.end_date, i->begin_date);
            }

            cout << " days" << endl;
            cout << t << endl;
            cout << *i << endl;

        }

    }
};

int main()
{

    TD_generator(v);

    auto select = v[7];

    //functor<TRADE_DATE> fc;
    //fc(v);

    sort(v.begin(), v.end());

    sort(v.begin(), v.end(), [](TRADE_DATE &t1, TRADE_DATE &t2)
    { return (t1.begin_date < t2.begin_date); });

    for (int i = 0; i < n; i++)
    {
        v[i].display();
    }


    function<void(TRADE_DATE)> new_function = bind(intersection_finder<vector, TRADE_DATE>(), v, placeholders::_1);

    new_function(select);

    return 0;
}