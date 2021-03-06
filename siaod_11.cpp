#include <iostream>
#include <list>

using namespace std;

class HRTL
{
    int capacity;
    list<int>* stl;

    public:
        HRTL(int V);
        void insertItem(int key,int data);
        void deleteItem(int key);

    int checkPrime(int n)
    {
        int i;

        if(n==1||n==0)
        {return 0;}

        for(i=2;i<n/2;i++)
        {if(n%i==0){return 0;}}

        return 1;
    }

    int getPrime(int n)
    {
        if(n%2==0)
        {n++;}

        while(!checkPrime(n))
        {n += 2;}

        return n;
    }

    int hashFunction(int key)
    {return (key % capacity);}

    void displayHash();
};

HRTL::HRTL(int c)
{
    int size=getPrime(c);
    this->capacity=size;
    stl=new list<int>[capacity];
}
void HRTL::insertItem(int key,int data)
{
    int imfine=hashFunction(key);
    stl[imfine].push_back(data);
}

void HRTL::deleteItem(int key)
{
    int imfine=hashFunction(key);

    list<int>::iterator i;
    for (i=stl[imfine].begin();i!=stl[imfine].end();i++)
    {
        if(*i==key)
        {break;}
    }

    if(i!=stl[imfine].end())
    {stl[imfine].erase(i);}
}

void HRTL::displayHash()
{
    for(int i=0;i<capacity;i++)
    {
        cout<<"chair["<<i<<"]";
        for(auto x:stl[i])
        {cout<<">"<<x;}

        cout << endl;

        cout<<"table["<<i<<"]";
        for(auto x:stl[i])
        {cout<<">"<<x;}

        cout<<"\n";
    }
}
int main()
{
    int key[]={6,5,4,3,2,1};
    int data[]={1,2,3,4,5,6};

    int n=sizeof(key)/sizeof(key[0]);

    HRTL h(n);

    for(int i=0;i<n;i++)
    {h.insertItem(key[i],data[i]);}

    h.deleteItem(12);
    h.displayHash();
}
