#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

void rotate(int **src, int w)
{
    //create a matrix, which has the same size with src
    int **dest = new int *[w];
    for (int i = 0; i < w; i++)
    {
        dest[i] = new int[w];
    }

    
    //w*w matrix, w is even
    for (int i = 0; i < w; i++)
    {
    	for (int j = 0; j < w; j++)
    	{
        	dest[j][w-i-1] = src[i][j];
        }
    }

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < w; j++)
        {
            src[i][j] = dest[i][j];
        }        
	}

    //release memory space
    for (int i = 0; i < w; i++)
    {
        delete[]dest[i];
    }
    delete[]dest;

}

int main()
{
    srand(time(NULL));
    ofstream file_A("FileA.txt");
    ofstream file_B("FileB.txt");

    int k;

    cout << "k = ";
    cin >> k;

    //dynamic generating a 2D matrix
    int **m = new int *[k];
    for (int i = 0; i < k; i++)
    {
        m[i] = new int[k];
    }

    //fill up the matrix with random numbers, and output the content to FileA.txt
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int v = rand();
            m[i][j] = v;
            file_A << v << "\t";
        }
        file_A << endl;
    }

    rotate(m, k);
    rotate(m, k);
    rotate(m, k);


    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            file_B << m[i][j] << "\t";
        }
        file_B << endl;
    }

    //release memory space
    for (int i = 0; i < k; i++)
    {
        delete[]m[i];
    }
    delete[]m;

    file_A.close();
    file_B.close();

    return 0;
}
