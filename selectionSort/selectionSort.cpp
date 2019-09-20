#include<iostream>
using namespace std;
/*
*算法导论2.2-2 选择排序
*/
template <typename T>
void selectionSort(T A[],int N)
{//N是数组中元素个数
    for(int i=0;i<N-1;i++)
    {
        double key =A[i];//记录当前下标的值
        int minIndex=i;//记录当前已知序列中最小的值的下标
        int j=i+1;
        while (j<N)
        {
            if(A[j]<key)
            {//如果找到当前的A[j]比key 小,更新key与minIndex
                    key=A[j];
                    minIndex=j;
            }
            j++;
        }
        A[minIndex]=A[i];
        A[i]=key;
    }
}
int main()
{
    cout<<"int number:"<<endl;
    int count;
    cin>>count;
    double *ptr=new double[count];
    for(int i=0;i<count;i++)
    {
        cin>>ptr[i];
    }
    cout<<endl;
    selectionSort(ptr,count);
    for(int i=0;i<count;i++)
    {
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}