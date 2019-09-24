/*
*list 的splice拼接操作
*
*
*/
#include<list>
#include<iostream>
#include<iterator>
#include<string>
using namespace std;
int main()
{
    string name1[]={    "Lily",
                        "Cici",
                        "Jane",
                        "Mark"
                    };
    string name2[]={    "xiaochen",
                        "xiaoxia",
                        "xiaoguo",
                        "xiaosheng"
                    };
    list<string> s1(name1,name1+4);
    list<string> s2(name2,name2+4);
    //将s1的第一个元素放到,s2的最后一个元素中去
    s2.splice(s2.end(),s1,s1.begin());
    /*
    *splice ()第一个位置插入的位置,第二个参数,要插入是那个容器对象的东西,第三第四插入的范围
    * */
    copy(s2.begin(),s2.end(),ostream_iterator<string>(cout," "));
    //将iter1指向s1的第一个元素
    list<string>::iterator iter1=s1.begin();
    advance(iter1,2);//将iter1前进2个元素指向是s1的第三个元素
    list<string>::iterator iter2=s2.begin();
    advance(iter2,2);
    list<string>::iterator iter3=iter2;
    advance(iter3,2);//iter3指向s2的第4个元素
    s1.splice(iter1,s2,iter2,iter3);
    copy(s1.begin(),s1.end(),ostream_iterator<string>(cout," "));
    cout<<endl;
    return 0;
}