#include <iostream>
#include <tuple>

using namespace std;

/*
 * function template can not be partial specialized
 * http://harttle.com/2015/10/03/cpp-template.html
 * http://en.cppreference.com/w/cpp/language/partial_specialization
*/

//declared as a global function
tuple<int, int, int> data = make_tuple(111, 222, 333);

template<class tuple, int index>
class PrintTuple
{
public:
    static void printer(const tuple &t)
    {
        cout << get<index - 1>(t) << endl;
        PrintTuple<tuple, index - 1>::printer(t);

    }
};

template<class tuple>
class PrintTuple<tuple, 1>
{
    //partial specialization
public:
    static void printer(const tuple &t)
    {
        cout << get<0>(t) << endl;
    }
};

//encapsulate
template<class ...args>
void printer(const tuple<args...> &t)
{
    //tuple<args...> &t --> can receive a tuple which contains arbitrary elements
    PrintTuple<decltype(t), sizeof...(args)>::printer(t);
}

int main()
{

    printer(data);

    //Without encapsulation(line 33), we have to point out <tuple<int, int, int>, 3>, like the code below
    //PrintTuple<tuple<int, int, int>, 3>::printer(data);
    
    return 0;
}