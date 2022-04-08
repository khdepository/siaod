#include <iostream>
#include <limits.h>
#include <string>
#include <vector>

using namespace std;

vector<int> digitsForA;
vector<int> digitsForB;
vector<int> result;

int arrayConvert(string str,vector<int> digits)
{
    int is_negative=0;
    if (str.length() == 0) {}
        else {
                if (str[0] == '-') {
                        str = str.substr(1);
                        is_negative=1;
                }
                for (long long i = str.length(); i > 0; i -= 1) {
                    digits.push_back(atoi(str.substr(i - 1, 1).c_str()));
                    cout<<digits.back()<<" ";
                }
        }
    return 0;
}

int addition(){return 0;}

int main()
{
    string a;
    getline(cin,a);
    
    arrayConvert(a, digitsForA);
    arrayConvert(b, digitsForB);
    return 0;
}
