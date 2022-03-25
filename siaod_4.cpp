#include <iostream>
using namespace std;

//ф-ция поиска
int barrierSearch(int *x, int n, int key){
    x=(int*)realloc(x,(n+1)*sizeof(int));
    x[n]=key;
    int i=0;
    while(x[i]!=key)i++;
    return i<n?i:-1;
}

int main() {
    //объявление переменных
    int key, n, i, j, buff;
    
    //ввод размера массива
    cout<<"array size:";
    cin>>n;
    
    //динамический массив + его заполнение
    int* arr=new int[n];
    for (int i=0;i<n;i++)
    {
        arr[i]=rand()%10000;
    }
    cout<<endl;
    
    //сортировка
    for (i=1;i<n;i++)
    {
        buff=arr[i];
        for (j=i-1;j>=0 && arr[j]>buff;j--)
            arr[j+1]=arr[j];

        arr[j+1]=buff;
    }
    
    //вывод массива
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    //ключ
    cout<<endl<<"key: ";
    cin>>key;
    
    cout<<"index of "<<key<<" is "<<barrierSearch(arr,n,key);
    return 0;
}
