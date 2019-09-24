#include<iostream>
#include<list>
#include<iterator>
using namespace std;
int main()
{
    list<int> s;  

    /*
    *后插迭代器可以直接用back_inserter(容器对象名),也可以用auto 
    * */
   //back_inserter iter(s);
   auto iter =back_inserter(s);
    *(iter++)=5;
    copy(s.begin(),s.end(),ostream_iterator<int>(cout," "));
    return 0;
}