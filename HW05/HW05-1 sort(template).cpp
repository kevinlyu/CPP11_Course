#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <typeinfo>

using namespace std;

template <typename T>
void bubble_sort(vector<T> &v){
	
	const int size = v.size();
	
	for(int i=0; i<size; i++){
		
		for(int j=0; j<size-i-1; j++){
			if(v[j+1] < v[j]){
				swap(v[j+1], v[j]);
			}
		}
	}
}

template <typename T>
void insertion_sort(vector<T> &v){
	
	const int size = v.size();
	int j;

	for(int i=1; i<size; i++){
		
		T temp = v[i];
		
		for(j = i-1; j>=0 && v[j] > temp; j--){
			v[j+1] = v[j];
		}

		v[j+1] = temp;
	}
}

template <typename T>
void input(vector<T> &v){
	
	T data;
	while(cin >> data){
		v.push_back(data);
	}

	cin.clear();
	cin.ignore();
}

template <typename T>
void output(vector<T> &v){

	cout << "Data Sorted:" << endl;
	
	for(const auto &i : v){
		cout << i << " ";
	}
	cout << endl;
}

int main(){

	vector<int> v;
	
	cout << "Input data  (Ctrl^D to terminate):" << endl;
	input(v);
	void  (*fptr[2])(vector<int> &v) = {bubble_sort, insertion_sort};		
	
	int op;
	cout << "[1] Bubble Sort  [2] Insertion Sort" << endl;
	

	while(true){
		cin >> op;
		
		if(op == 1 || op == 2)
		{
			fptr[op-1](v);
			output(v);
			break;
		}
		else
		{
			cout << "Error input. " << endl;		
		}
	}
	
	return 0;
}
