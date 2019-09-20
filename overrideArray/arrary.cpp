#include<iostream>
#include<cassert>
#include "arrary.h"
using namespace std;
template <class T>
Arrary<T>::Arrary(int sz)
{//构造函数
    assert(sz>=0);
    this->size=sz;
    list = new T[size];
    cout<<"constructor called"<<endl;
}
template <class T>
Arrary<T>::Arrary(const Arrary<T> &a)
{//复制构造函数
//这里要进行深层复制构造
    this->size=a.size;
    list = new T[size];//申请新的内存空间
    for(int i=0 ;i<size;i++)
    {
        list[i]=a.list[i];
    }
}
template<class T>
Arrary<T>::~Arrary()
{
//析构函数
    delete[] list;//释放申请的内存空间
    cout<<"Deconstructor called"<<endl;
}
template <class T>
Arrary<T>& Arrary<T>::operator [](int index)
{   //重写[]符
    assert(index>=0&&index<size);
    return list[index];
}
// template <class T>
// ostream& Arrary<T>::operator <<(ostream &out,const Arrary<T> &tt,int index)
// {//重写插入运算符
//     out<<tt.list[index]<<" ";
//     return out;
// }
template <class T>
T& Arrary<T>::getElement(int index)
{
    assert(index>=0&&index<size);
    return list[index];
}