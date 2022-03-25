#include <iostream>
using namespace std;

//ф-ция поиска
int barrierSearch(int *x, int n, int key){
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
    
    //вывод массива
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    //ключ
    cout<<endl<<"key: ";
    cin>>key;
    
    cout<<"index of "<<key<<" is "<<barrierSearch(arr,n,key)+1;
    return 0;
}
