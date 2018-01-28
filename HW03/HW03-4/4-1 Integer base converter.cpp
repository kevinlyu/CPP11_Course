#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

string num_set = "0123456789ABCDEF";

bool check(const string &str, int base) {

	if(base == 0 || base == 1){
		return false;
	}

    for (int i = base; i <= 16; i++) {

        if (str.find(num_set[i]) != string::npos) {
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv) {

	//get parameters from command line 
    string num_s(argv[1]);
    int base = atoi(argv[2]);
    int d_base = atoi(argv[3]);

    //testing set
    /*string num_s = "11111";
    int base = 2;
    int d_base = 16;*/

	//get the length of input string
    int l = num_s.length();
    for(int i=0; i<l; i++)
    {
    	//for convenience, convert alphabets to upper case
        num_s[i] = toupper(num_s[i]);
    }

    if(check(num_s, base))
    {
        string result = ""; //append converted digits to the string
        unsigned int num = 0; 

        //convert to decimal number presentation
        for(int i=0; i<l; i++)
        {
        	//look up table "num_set" and get the value
            num = num + num_set.find(num_s[i])*pow(base, l-1-i);
        }

        while(num){

            result += num_set[num % d_base];
            num /= d_base;
        }

        reverse(result.begin(), result.end());
        cout << result << endl;

    }
    else
    {
        cout << "wrong base presentation." << endl;
    }

    return 0;
}
