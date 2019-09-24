#include<deque>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;
/*
*利用双端队列实现 对输入的一串数字 按照奇数从大到小,偶数从小到大排序
*/
int main()
{
    istream_iterator<int> i1(cin),i2;//建立一队输入的迭代器,i1接受 i2结束
    vector<int> s1(i1,i2);  //通过输入流迭代器从标准输入流输入数据  
    sort(s1.begin(),s1.end());    
    //遍历s1
    deque<int> s2;
    for(vector<int>::iterator iter=s1.begin();iter!=s1.end();++iter)
    {
        if(*iter%2==0)
        {
            s2.push_back(*iter);
        }else
        {
            s2.push_front(*iter);
        }   
    }
    copy(s2.begin(),s2.end(),ostream_iterator<int>(cout," "));
    return 0;
}