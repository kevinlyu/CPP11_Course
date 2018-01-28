#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
bool Equal(T first)
{
	//terminate
	return false;
}

template<class T1, class T2, class...U>
bool Equal(T1 first, T2 second, U...args)
{
	if(first == second)
	{
		return true;
	}
	else if(Equal(first, args...))
	{
		return true;
	}
	else if(Equal(second, args...))
	{
		return true;
	}
}

int main()
{
		
	
	cout << Equal(1,'1', 3, 4, 5, 'b', 'a', 3.1445) << endl;
	
	return 0;
}

