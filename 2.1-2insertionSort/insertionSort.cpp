#include <iostream>
using namespace std;
/*
*
*2.1.2重写插入排序
*
*
*
*/
template <typename T>
void insertionSort(T A[],int N)
{
    int j;
    T key;
    for(int i=1;i<N;i++)
    {
        j=i-1;
        key=A[i];
        while(j>=0 &&A[j]<key)
        {
            A[j+1]=A[j];//将元素后移
            j--;
        }
            A[j+1]=key;
    }
}
int main()
{
    int count;
    cout<<"input count:";
    cin>>count;
    double *ptr=new double[count];
    for(int i=0;i<count;i++)
    {
        cin>>ptr[i];
    }
    cout<<endl;
    cout<<"------------------------------"<<endl;
    insertionSort(ptr,count);
    for(int i=0;i<count;i++)
    {
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
    return 0;
}