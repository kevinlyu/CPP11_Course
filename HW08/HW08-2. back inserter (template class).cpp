#include <iostream>
#include <random>
#include <deque>
#include <set>
#include <list>
#include <chrono>

/*
 * Pay attention to namespace
 * This problem occurs when using "list", "back_inserter"
 * */
 
 //If use system_clock, output duration will become 0, why?
 //use steady_clock, it works fine. 

const int data_num = 100000;
const int range_start = 1;
cons
t int range_end = 1000000;


//CONTer:underlying container, T: type of value stored in the container
template<template<class ...> class CONTer, typename T>
class back_inserter
{
    CONTer<T> qq;

    std::random_device rd;
    std::default_random_engine gen = std::default_random_engine(rd());
    std::uniform_int_distribution<T> dis{range_start, range_end}; //use {} instead of (), ask teacher

public:

    void insert_100k()
    {
        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < data_num; i++)
        {
            qq.insert(qq.end(), dis(gen));
        }

        auto end = std::chrono::steady_clock::now();


        auto t = std::chrono::duration<double>(end - start);
        std::cout << t.count() << " seconds to fill." << std::endl;
    }

    void change_to_5566()
    {
        auto start = std::chrono::steady_clock::now();
        for (auto &it:qq)
        {
            it = 5566;
        }
        auto end = std::chrono::steady_clock::now();
        auto t = std::chrono::duration<double>(end - start);
        std::cout << t.count() << " seconds to replace." << std::endl;

    }
};

template<typename T>
class back_inserter<std::set, T>
{
    std::set<T> qq;

    std::random_device rd;
    std::default_random_engine gen = std::default_random_engine(rd());
    std::uniform_int_distribution<T> dis{range_start, range_end}; //use {} instead of ()

public:

    void insert_100k()
    {
        auto start = std::chrono::steady_clock::now();

        //random algorithm
        for (int i = 0; i < data_num; i++)
        {
            qq.insert(qq.end(), dis(gen));
        }

        auto end = std::chrono::steady_clock::now();
        auto t = std::chrono::duration<double>(end - start);
        std::cout << t.count() << " seconds to fill." << std::endl;
    }


    void change_to_5566()
    {
        auto start = std::chrono::steady_clock::now();

        qq.clear();
        qq.insert(5566);

        auto end = std::chrono::steady_clock::now();
        auto t = std::chrono::duration<double>(end - start);
        std::cout << t.count() << " seconds to replace." << std::endl;
    }
};


int main()
{
    std::cout << "[vector]\n";
    back_inserter<std::vector, int> bi_v;
    bi_v.insert_100k();
    bi_v.change_to_5566();

    std::cout << "[deque]\n";
    back_inserter<std::deque, int> bi_d;
    bi_d.insert_100k();
    bi_d.change_to_5566();

    std::cout << "[set]\n";
    back_inserter<std::set, int> bi_s;
    bi_s.insert_100k();
    bi_s.change_to_5566();

    std::cout << "[list]\n";
    back_inserter<std::list, int> bi_l;
    bi_l.insert_100k();
    bi_l.change_to_5566();
    return 0;
}
