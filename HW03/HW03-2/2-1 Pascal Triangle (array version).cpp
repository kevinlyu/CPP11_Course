#include <iostream>
#include <vector>

using namespace std;

void print(int k) 
{
    for (int i = 0; i <= k; i++) 
	{
        for (int j = 0; j < k - i; j++) 
		{
            cout << "*";
        }

        if (i) 
		{
            cout << "1";
        }
        cout << endl;
    }
}

int sum(int k) 
{
    int s = 0;
    for (int i = 1; i <= k; i++) 
	{
        s += i;
    }
    return s;
    //return k*(k+1)/2
}

void fill(int *vector, int k) 
{
	int **p; //2D array to generate Pascal Triangle
	p = new int*[k];
	
    //create 2D space for elements of Pascal Triangle
	for(int i=0; i<k; i++)
	{
		p[i] = new int[k];
	}
		
	//initial all elements to value 0
	for(int i=0; i<k; i++)
	{
		for(int j=0; j<k;j++)
		{
			p[i][j] = 0;
		}
	}
	
	for(int i=0; i<k; i++)
	{
		p[i][0] = 1;
	}
	
	for(int i=1; i<k; i++)
	{
		for(int j=1; j<=i; j++)
		{
			p[i][j] = p[i-1][j] + p[i-1][j-1];
		}
	}
	
	int index=0; //index of vector
	
	for(int i=0; i<k; i++){
		for(int j=0; j<=i; j++){
			vector[index++] = p[i][j];
		}
	}
}

void display(int *vector, int k)
{	
	int index=0;
	for (int i = 0; i < k; i++) {

        for(int w=0; w<k-i; w++){
            //輸出空白以調整排版
            cout << " ";
        }

        for (int j = 0; j <= i; j++) {
            cout << vector[index++] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int k;
    int *data;
	vector<int> v;

    cout << "k = ";
    cin >> k;
	
    print(k);
    
    data = new int[sum(k)];
    fill(data, k);
    cout << endl;
	display(data, k);
	
	
    return 0;
}

