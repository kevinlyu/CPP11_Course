#include <iostream>
#include <vector>

using namespace std;

void print(int k) {
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < k - i; j++) {
            cout << "*";
        }

        if (i) {
            cout << "1";
        }
        cout << endl;
    }
}

int sum(int k) {
    int s = 0;
    for (int i = 1; i <= k; i++) {
        s += i;
    }
    return s;
    //return k*(k+1)/2
}


int comb(int m, int n) {
    int p = 1;
    int i;
    for (i = 1; i <= n; i++) {
        p = p * (m - i + 1) / i;
    }
    return p;
}

void fill(vector<int> &v, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= i; j++) {
            v.push_back(comb(i, j));
        }
    }
}

void display(vector<int> &v, const int k) {
    vector<int>::iterator it = v.begin();

    for (int i = 0; i < k; i++) {

        for(int w=0; w<k-i; w++){
            //輸出空白以調整排版
            cout << " ";
        }

        for (int j = 0; j <= i; j++) {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }
}


int main() {
    int k;
    vector<int> v;

    cout << "k = ";
    cin >> k;

    print(k);
    cout << "sum = " << sum(k) << endl;
    fill(v, k);

    display(v, k);
    return 0;
}

