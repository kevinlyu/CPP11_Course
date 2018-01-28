#include <iostream>

using namespace std;

int move(int n, char src, char tmp, char dest)
{
	if(n == 1)
	{
		//terminate condition
		cout << "move disk " << n << " from " << src << " to " << dest << endl;
	}
	
	else
	{
		move(n-1, src, dest, tmp);
		move(1, src, tmp, dest);
		move(n-1, tmp, src, dest);
	}	
}

int main(){
	
	int k; //total disk on hanoi tower
	
	cout << "k = ";
	cin >> k;
	
	move(k, 'A', 'B', 'C');
	
	system("PAUSE");
	return 0;
}
