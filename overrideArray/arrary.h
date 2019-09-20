#ifndef _ARRARY_H_
#define _ARRARY_H_
#include <iostream>
template <class T>
class Arrary
{
    private:
        T* list;//记录类型数组的首地址
        int size;//记录数组元素的个数
    public:
    Arrary(int sz=50);//构造函数
    Arrary(const Arrary<T> &a);//复制构造函数
    ~Arrary();//析构函数
    Arrary<T>& operator [](int index);//重写[]
    //ostream& operator <<(ostream &out,const Arrary<T> &tt,int index);//重写插入运算符
    T& getElement(int index);
};
#endif