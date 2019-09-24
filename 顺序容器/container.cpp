#include<iostream>
#include<list>
#include<deque>
#include<iterator>
using namespace std;
//输出指定容器的元素
template <class T>
void printContainer(const char* msg,const T& S)
{
    cout<<msg<<" ";
    copy(S.begin(),S.end(),ostream_iterator<int>(cout," "));
    /*
    *注意这里写成ostream_iterator<T>(cout," ")会报错
    * 
    * *
    * */
    cout<<endl;
}
int main()
{
    deque<int> s;
    for(int i=0;i<10;i++)
    {
        int x;
        cin>>x;
        s.push_front(x);
    }
    /*
    *
    * 如果没有输入满10个这里会默认将后面的元素填为最后一个
    * *
    * ***/
    printContainer("deque at first",s);
    list<int> l(s.rbegin(),s.rend());   
    printContainer("list at first:",l);
    //将容器l中的每相邻的两个元素交换
    list<int>::iterator iter=l.begin();
    while (iter!=l.end())
    {
        int c= *iter;
        iter =l.erase(iter);
        l.insert(++iter,c);
    }
    printContainer("list at second",l);
    s.assign(l.begin(),l.end());
    /*
    *s(l.begin(),l.end());这种只能在初始化的时候使用
    * /
    printContainer("deque at second ",s);
    return 0;
    */
}