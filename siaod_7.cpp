#include <iostream>
#include <list>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

void printList(list<int> L)
{
	for(int i:L)
	{cout<<i;}
}

void fillList(list<int>* L,int q)
{
	for(int i=q-1;i>=0;i--)
	{L->push_front(rand()%10);}
}

int main()
{
	list<int> L1, L2, L;
	fillList(&L1,10);
	fillList(&L2,10);

	for(int i:L1)
	{
		if(find(L2.begin(),L2.end(),i)==L2.end()&&find(L.begin(),L.end(),i)==L.end())
        {L.push_front(i);}
	}
	for(int i:L2)
	{
		if(find(L1.begin(),L1.end(),i)==L1.end()&&find(L.begin(),L.end(),i)==L.end())
        {L.push_front(i);}
	}
	cout<<"l1\n\n";
	printList(L1);
	cout<<"\n\nl2\n\n";
	printList(L2);
	cout<<"\n\nl\n\n";
	printList(L);

	return 0;
}
