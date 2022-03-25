#include <iostream>
using namespace std;

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

    //переменные 2
    bool flag=false;
    int l=0;
    int r=n-1;
    int m;

    //поиск
    while ((l<=r) && (flag!=true)){
        m=(l+r)/2;

        if (arr[m]==key){flag=true;}
        if (arr[m]>key){r=m-1;}
        else l=m+1;
    }

    if (flag)cout<<"item \""<<key<<"\" index: "<<m+1<<endl;
    return 0;
}
