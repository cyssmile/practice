/*
* 利用栈反向输出单词
*
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;
/*
*
注意栈不支持迭代器
**/
int main()
{
    stack<char> st;
    string str;
    cin >>str;
    //for(string::iterator iter=str.begin();iter!=str.end();++iter)
    for(auto iter=str.begin();iter!=str.end();++iter)
    {
        st.push(*iter);
    }
    while (!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
    
    return 0;
}