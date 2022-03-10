#include <iostream>
#include <time.h>
using namespace std;

void Sort(int* arr,int n){
	clock_t start, end;
	start = clock();
	int counter=0;
	for(int i=1;i<n;i++){
		for(int j=i; j>0 && arr[j-1]>arr[j];j--){
			counter++;
			int tmp=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=tmp;
		}
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";
		cout << endl;
	cout<<counter<<endl;
	end = clock();
	printf("time %.4f(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
}

int main()
{
	cout << "array lenght: ";
	int n;
	cin >> n;
	
	int* a = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000;
	}
	
	Sort(a,n);
} 
