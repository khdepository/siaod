#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int hashxd(string x)
{
    int hashxd=x[0]+x[1]+x[x.length()-1];
    return hashxd;
}

int main()
{
    ifstream file("text.txt");
    int arr[100];
    int i=0;
    
    while(i<=(sizeof arr / sizeof arr[0])) {
        string str;
        getline(file, str);
        arr[i]=hashxd(str);
        i++;
    }
    cout<<"key: ";
    string key;
    cin>>key;
    
    int keyhash=hashxd(key);
    i=0;
    while(i<=(sizeof arr / sizeof arr[0]))
    {
        if (keyhash==arr[i]){cout<<"string id is "<<i+1;break;}
        i++;
    }
    
    return 0;
}
