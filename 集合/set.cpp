#include<set>
#include<iostream>
#include<iterator>
//#include<utility>
using namespace std;
int main()
{
    set<double> s;
    while(true)
    {
        double v;
        cin>>v;
        if(v==0) break;
        pair<set<double>::iterator  ,bool> r=s.insert(v);
        if(!r.second)
            cout<<v<<" is duplicated "<<endl;
    }
    //得到第一个元素的迭代器
    set<double>::iterator iter1=s.begin();
    //得到最后一个元素的迭代器
    auto iter2=s.end();
    double medium=(*iter1+*(--iter2))/2;
    cout<<"medium="<<medium<<endl;
    copy(iter1,s.upper_bound(medium),ostream_iterator<double>(cout," "));
    cout<<endl;
    copy(s.lower_bound(medium),iter2,ostream_iterator<double>(cout," "));
    cout<<endl;

    return 0;
}