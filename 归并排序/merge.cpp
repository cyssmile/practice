#include <iostream>
using namespace std;
template <class T>
void merge(T A[],int p,int q,int r)
{// p,q,r都是在A数组中的下标
    //N1 与N2都是记录两个待排的子数组中元素的个数
    int N1=q-p+1;
    int N2=r-q;
//将数组A中这两个子数组放到新的数组中去 L1,L2
    T* L1=new T[N1];
    for(int i=0;i<N1;i++)
    {
        L1[i]=A[p+i];
    }
    T* L2=new T[N2];
    for(int i=0;i<N2;i++)
    {
        L2[i]=A[q+i+1];
    }
    //开始将L1和L2中的数排序好放入A数组去
    int i=0,j=0,k=p;
    while (i<N1&&j<N2)
    {//循环直到较短的数组结束
        
        if(L1[i]<L2[j])
        {
            A[k++]=L1[i++];
        }else
        {
            A[k++]=L2[j++];
        }
    }
    //判断L1是否结束
    if(i<N1)
    {
        A[k++]=L1[i++];
    }
    //判断L2是否结束
    if(j<N2)
    {
        A[k++]=L2[j++];
    }
    //注意new的数组要释放
    delete[] L1;
    delete[] L2;
}
/*
*   将merge函数当成归并函数的子函数
*
*/
template <class T>
void mergeSort(T A[],int p,int r)
{//p和r是A[]数组中待排的区间
    if(p<r)
    {//当p和r中有存在待排的元素时进行
        //q为pr的中间下标
        int q=(p+r)/2;
        //这里是递归调用,先处理A[p.....q],再处理A[q+1.............r]
        //最后将两个数组排好序
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }

}
int main()
{
    /*
    *----------------------------------test merge()-------------------------
    * */
   int A[10];
   for(int i=0;i<4;i++)
   {//初始化
       A[i]=i+1;
   }
   for(int j=4;j<10;j++)
   {
       A[j]=j-2;
   }
    
     for(int i=0;i<10;i++)
   {
       cout<<A[i]<<" ";
   }
     cout<<endl;
     //这下面要么单独用merge 函数, 要么用归并排序
    mergeSort(A,0,9);
    //merge(A,0,3,9);
   for(int i=0;i<10;i++)
   {
       cout<<A[i]<<" ";
   }
    cout<<endl;
    /*
    *---------------------------------------测试成功------------------------------------------
    * */
    return 0;
}