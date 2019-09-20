#include<iostream>
#include<cassert>
using namespace std;
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
int main()
{
    int count;
    cin>>count;
    Arrary<int> a0(count);
    // for(int i=0;i<count;i++)
    // {
    //     a0[i]=i;
    // }
    // cout<<endl;
    // for(int i=0;i<count;i++)
    // {
    //     cout<<a0.getElement(i).list;
    // }
    // Arrary<double> a1(40);
    return 0;
}
