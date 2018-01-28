#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;

int main(){
	
	srand(time(NULL));
	ifstream infile("output.txt");
	ofstream outfile("output2.txt");
	string line; //read one line of input data
	 
	int q;//overwrite qth line with a random number 
	
	cout << "Q = "; 
	cin >> q;
	
	int counter = 0;
	
	while(!infile.eof()){
	
		counter++;
		getline(infile, line);
		
		if(counter == q){
			//replace with a random number
			outfile << line.substr(0, line.find("=")) << "= " << rand() << endl;
		}
		
		else{
			outfile << line << endl;	
		}
	}
	
	outfile.close();
	infile.close();
	
	return 0;
} 
