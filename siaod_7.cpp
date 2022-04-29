#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> digitsForA;
vector<int> digitsForB;
vector<int> result;
int count=0;

int arrayConvert(string str)
{
    if(count!=1){
        int i=0;
        int is_negative=0;
        if(str[0]=='-')
        {
            is_negative=1;
        }
        while(i!=str.length())
        {
            digitsForA.push_back(str[i]);
            i++;
        }
        if(is_negative==1)
        {
            digitsForA.push_back(-1);
        }
        count++;
    }
    else
    {
        int i=0;
        int is_negative=0;
        if(str[0]=='-')
        {
            is_negative=1;
        }
        while(i!=str.length())
        {
            digitsForB.push_back(str[i]);
            i++;
        }
        if(is_negative==1)
        {
            digitsForB.push_back(-1);
        }
    }
    return 0;
}

int addition()
{
    int add=0;
    int a_m=1,b_m=1;
    int a=0;
    int b=0;
    if(!digitsForA.empty()){int a=digitsForA.back();}
    if(!digitsForB.empty()){int b=digitsForB.back();}
    if(a==-1)
    {
        digitsForA.pop_back();
        a_m=-1;
    }
    if(b==-1)
    {
        digitsForB.pop_back();
        b_m=-1;
    }
    int r=0;
    while(max(digitsForA.size(),digitsForB.size())!=0)
    {
        a=0;
        b=0;
        add=0;
        if(!digitsForA.empty()){a=digitsForA.back()*a_m-48;}
        if(!digitsForB.empty()){b=digitsForB.back()*b_m-48;}
        if(!digitsForA.empty()){digitsForA.pop_back();}
        if(!digitsForB.empty()){digitsForB.pop_back();}
        r=a+b+add;
        if(r>9)
        {
            r=r-10;
            add=1;
        }
        result.push_back(r);
    }
    if(add!=0)
    {
        result.push_back(add);
    }
    return 0;
}

int printVector()
{
    int i=result.size()-1;
    while(i!=-1)
    {
        cout<<result[i];
        i--;
    }
    return 0;
}

int main()
{
    string a;
    getline(cin,a);
    string b;
    getline(cin,b);
    arrayConvert(a);
    arrayConvert(b);
    addition();
    printVector();
    return 0;
}
