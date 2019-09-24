/*
* 从五门课中选三门并且计算学分
*
*/
#include <map>
#include <iostream>
#include<iterator>
#include<string>
using namespace std;
int main()
{
    map<string,int> course;
    map<string,int> MyCourse;
    //在course中插入五门课
    course.insert(make_pair("C++",2));
    course.insert(make_pair("CSAPP",3));
    course.insert(make_pair("MATH",5));
    course.insert(make_pair("OS",5));
    course.insert(make_pair("AN",2));
    int n=3;//可以选三门课
    int goal=0;//记录选课的总学分
    while(n)
    {
        string name;
        cin>>name;  
        map<string,int>::iterator iter=course.find(name);
        if(iter==course.end())
        {
            cout<<name<<"不存在,请重新选课"<<endl;
        }else
        {
            MyCourse.insert(make_pair(iter->first,iter->second));
            goal+=iter->second;//iter->second 指的是那个值
            course.erase(iter);
            n--;
        }
    }
    cout<<"你的选课为:";
    for(auto iter1=MyCourse.begin();iter1!=MyCourse.end();++iter1)
    {
            cout<<iter1->first<<" ";
    }
    cout<<"总学分goal:"<<goal<<endl;
    return 0;
}