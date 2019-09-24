#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
template <class T,class InputIterator,class OutputIterator>

void  Mysort(InputIterator first,InputIterator last,OutputIterator result)
{
    vector<T> S;
    for(;first!=last;++first)
    {
        S.push_back(*first);
    }
    sort(S.begin(),S.end());//对S进行排序
    copy(S.begin(),S.end(),result);//将S放到输出迭代器中进行输出
}
int main()
{
    double a[5]={1.1,3.3,5.5,6.6,4.4};
   Mysort<double>(a,a+5,ostream_iterator<double>(cout," "));//注意这里要指定类型
   Mysort<int>(istream_iterator<int>(cin),istream_iterator<int>(),ostream_iterator<int>(cout," "));
   cout<<endl;
    return 0;
}