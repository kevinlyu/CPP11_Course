#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	ofstream outfile("output.txt");
	int k;
	
	cout << "k = ";
	cin >> k;
	
	//產生九九乘法表並寫入 
	for(int i=1; i<=9; i++){
		
		outfile << k << " x " << i << " = " << k*i << endl;
	}
	
	//close file 
	outfile.close();
	
	return 0;
} 
