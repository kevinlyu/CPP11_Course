#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
	
	int line_num = 0; //record line number witch error occurs
	int a, b, c; //a * b = c, read a, b, c from input data, and check if they are correct
	 
	string line;
	ifstream infile("output2.txt");
	
	while(!infile.eof()){
		
		line_num++;
		getline(infile, line);
		
		int x_loc = line.find("x");
		int eq_loc = line.find("=");
		
		//spilt the string, and convert 
		a = atoi(line.substr(0, x_loc).c_str());
		b = atoi(line.substr(x_loc+1, eq_loc).c_str());
		c = atoi(line.substr(eq_loc+1, line.length()).c_str());
		
		if(a*b != c){
			cout << "Find error in line " << line_num << endl;
		}		
	}
	return 0;
}
