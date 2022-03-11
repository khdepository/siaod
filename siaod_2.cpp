#include <iostream>
#include <list>
#include <time.h>
using namespace std;

int count=0;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
        count++;
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Sort(int arr[], int low, int high)
{
	count++;
	if (low < high)
    {
        int a = partition(arr, low, high);
 
        Sort(arr, low, a - 1);
        Sort(arr, a + 1, high);
    }
	
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
	
	clock_t start, end;
	start = clock();
	Sort(a,0,n-1);
	end = clock();
	cout<<count<<endl;
	printf("time %.4f(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printArray(a,n);
} 
