#include <iostream>
#include <vector>

using namespace std;

vector<int> A; //input data set
int size; //size of vector A 
bool *visit; //record whether A[i] is choosed
bool flag = false; //If there exist a solution, flag = true

void dfs(int i, int j, int k){
	//i: index of vector, j:k-current sum
	
	if(j == 0){		
		//�F��ؼЭȡA�L�X��w���l�� 
		cout << "{";
		for(int idx=0; idx<size; idx++){
			if(visit[idx]){
				cout << A[idx] << " ";
			}
		}
		cout << "}" << endl;
		flag = true;
	}
	
	else if(i == size){
		//�F��vector���ݡA�פ�j 
		return;
	}
	
	else{
		//using traceback 
		visit[i] = true; //�����A[i] 
		dfs(i+1, j-A[i], k); //
		visit[i] = false; //�������A[i] 
		dfs(i+1, j, k);
	}
}

int main(){
	
	int k;
	int input;
	
	cout << "Input some numbers (use Ctrl+D to terminate):" << endl;
	
	while(cin >> input){
		//Ctrl+D to finish input
		A.push_back(input);
	}
	
	size = A.size();
	
	//��visit[i]�аOA[i]�O�_�Q��� 
	visit = new bool[size];
	for(int i=0; i<size; i++){
		visit[i] = false;
	}
	
	//to make cin work after Ctrl+D
	cin.clear();
	cin.sync();
	
	cout << "k = ";
	cin >> k;
		
	dfs(0,k,k);
	
	if(!flag){
		cout << "No solution" << endl;
	}
		
	return 0;
}

