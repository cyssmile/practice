/*
*
*统计一句话中字母出现的次数
*
*/
#include<map>
#include<iostream>
#include<cctype>
using namespace std;
int main()
{
    map<char,int> Alpha;
    char c;
    do{
        cin>>c;
        if(isalpha(c))//判断c是不是字母
        {
            c=tolower(c);//不区分大小写
            Alpha[c]++;//如果未存在过,就插入,存在过就值加1
        }
    }while(c!='.');//遇到.号就结束
    for(map<char,int>::iterator iter=Alpha.begin();iter!=Alpha.end();++iter)
    {
        cout<<iter->first<<":"<<iter->second<<" ";
    }
    cout<<endl;
    return 0;
}