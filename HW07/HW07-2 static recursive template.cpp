#include <iostream>

using namespace std;

template<class T, int length, int idx, T *array>
class printer
{

public:

    static void print()
    {
        printer<T, length, idx-1, array>::print();
        cout << array[idx-1] << " ";
    }
};


template<class T, int length, T *array>
class printer<T, length, 0, array>
{

public:

    static void print()
    {
        //terminate condition
    }
};


int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main()
{

    printer<int, 10, 10, a>::print();
    return 0;
}
