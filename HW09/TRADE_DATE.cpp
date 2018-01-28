//
// Created by Kevin on 2016/11/16.
//

#include "TRADE_DATE.h"
#include <algorithm>
#include <iostream>

int m1[7] = {1, 3, 5, 7, 8, 10, 12}; //month has 31 days
int m2[4] = {4, 6, 9, 11}; //month has 30 days

TRADE_DATE::TRADE_DATE(int id)
{
    int year, month, day;
    int days_in_the_month;

    random_device rd;
    default_random_engine gen = default_random_engine(rd());
    uniform_int_distribution<int> year_dis(1900, 2000); //range of year: 1900 to 2000 A.D
    uniform_int_distribution<int> month_dis(1, 12); //range of month
    uniform_int_distribution<int> day_dis_28(1, 28); //range of day
    uniform_int_distribution<int> day_dis_29(1, 29); //range of day
    uniform_int_distribution<int> day_dis_31(1, 31); //range of day
    uniform_int_distribution<int> day_dis_30(1, 30); //range of day
    uniform_int_distribution<int> duration_dis(1, 10); //range of duration

    year = year_dis(gen);
    month = month_dis(gen);
    this->duration = duration_dis(gen);
    this->ID = id;

    if (year % 400 == 0 && year % 100 == 0 && month == 2)
    {
        //閏年
        day = day_dis_29(gen);
        days_in_the_month = 29;
    }

    else
    {
        //非閏年的處理
        if (find(m1, m1 + 7, month))
        {
            day = day_dis_31(gen);
            days_in_the_month = 31;
        }

        else if (find(m2, m2 + 4, month))
        {
            day = day_dis_30(gen);
            days_in_the_month = 30;
        }

        else
        {
            //平年的2月
            day = day_dis_28(gen);
            days_in_the_month = 28;
        }
    }

    begin_date = make_tuple(year, month, day);

    day = day + duration;

    if (day > days_in_the_month)
    {
        month++;
        day = day - days_in_the_month;
    }

    if (month > 12)
    {
        year++;
        month = 1;
    }

    end_date = make_tuple(year, month, day);

}

void TRADE_DATE::display()
{

    cout << ID << " " << get<0>(begin_date) << "/" << get<1>(begin_date) << "/" << get<2>(begin_date) << "\tto\t";
    cout << get<0>(end_date) << "/" << get<1>(end_date) << "/" << get<2>(end_date) << "\tdur = " << duration << endl;

}

bool TRADE_DATE::operator<(const TRADE_DATE &t) const
{

    if (get<0>(begin_date) < get<0>(t.begin_date))
    {
        return true;
    }

    else if (get<0>(begin_date) == get<0>(t.begin_date))
    {
        if (get<1>(begin_date) < get<1>(t.begin_date))
        {
            return true;
        }

        else if (get<1>(begin_date) == get<1>(t.begin_date))
        {
            if (get<2>(begin_date) <= get<2>(t.begin_date))
            {
                return true;
            }
        }
    }

    return false;
}

void TRADE_DATE::operator+(int dur)
{
    get<2>(begin_date) += dur;

    if (find(m1, m1 + 7, get<1>(begin_date)) && get<2>(begin_date) > 31)
    {
        get<2>(begin_date) %= 31;
        get<1>(begin_date)++;
    }

    else if (find(m2, m2 + 4, get<1>(begin_date)) && get<2>(begin_date) > 30)
    {
        get<2>(begin_date) %= 30;
        get<1>(begin_date)++;
    }

    else if (get<0>(begin_date) % 100 == 0 && get<0>(begin_date) % 400 == 0 && get<0>(begin_date) == 2 &&
             get<2>(begin_date) > 29)
    {
        get<2>(begin_date) %= 29;
        get<1>(begin_date)++;
    }

    else if (get<0>(begin_date) == 2 && get<2>(begin_date) > 28)
    {
        get<2>(begin_date) %= 28;
        get<1>(begin_date)++;
    }

    if (get<1>(begin_date) > 12)
    {
        get<1>(begin_date) %= 12;
        get<2>(begin_date)++;
    }

}

void TRADE_DATE::operator-(int dur)
{

    get<2>(begin_date) -= dur;

    if (get<2>(begin_date) < 1)
    {
        if (find(m1, m1 + 7, get<1>(begin_date)))
        {
            get<1>(begin_date)--;
            get<0>(begin_date) += 31;
        }

        else if (find(m2, m1 + 4, get<1>(begin_date)))
        {
            get<1>(begin_date)--;
            get<0>(begin_date) += 30;
        }

        else if (get<0>(begin_date) % 100 == 0 && get<0>(begin_date) % 400 == 0 && get<0>(begin_date) == 2)
        {
            get<1>(begin_date)--;
            get<0>(begin_date) += 29;
        }

        else if (get<0>(begin_date) == 2)
        {
            get<1>(begin_date)--;
            get<0>(begin_date) += 28;
        }

    }

}

int TRADE_DATE::dur_calculate(tuple<int, int, int> &t1, tuple<int, int, int> &t2)
{
    if (t1 < t2)
    {
        return dur_calculate(t2, t1);
    }

    int table[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    auto leapyear = [](int year)
    {
        if (year % 100 == 0 && year % 400 == 0)
        {
            return true;
        }

        else if (year % 4 == 0)
        {
            return true;
        }

        return false;
    };

    int dur = get<0>(t1) - get<0>(t2) + table[get<1>(t1)] - table[get<1>(t2)];

    if (get<1>(t1) > 2 && leapyear(get<0>(t1)))
    {
        dur += 1;
    }


    if (get<1>(t2) > 2 && leapyear(get<0>(t2)))
    {
        dur -= 1;
    }


    for (int i = get<0>(t2); i < get<0>(t1); i++)
    {

        dur += 365;
        if (leapyear(i))
        {
            dur++;
        }

    }

    return dur + 1;
}


