#include<fstream>
#include<iostream>
#include<set>
#include<string>
#include<cstdlib>
#include<map>
#include<cctype>
using namespace std;
namespace chys
{
} 
//统计文件中大小字母的个数
void getAllAlpha(string infliename)
{
    ifstream inFile;
    inFile.open(infliename.c_str());
    if(!inFile)
    {
        ifstream inFile;
        //判断文件是否正确的读取
        std::cout<<"文件路径错误"<<endl;
        exit(0);
    }
    map<char,int> Alpha;
    char c;
    string str;
    int count=0;//用于统计字母的个数
    //每次读入一行,逐行处理
    while (getline(inFile,str))
    {
        for(int i=0;i<str.size();i++)
        {
            c=str[i];
            if(isalpha(c))
            {//判断是否是字母
                c=tolower(c);//转换大小写
                Alpha[c]++;//没有就插入,存在就加加
                count++;
            }
        }
    }
    cout<<"统计完毕,请输入结果保存位置:";
    string outputFilename;
    cin>>outputFilename;
    ofstream outFile(outputFilename.c_str());
    //先在文本中输出总共的字母的个数
    outFile<<"总的字母的个数:"<<count<<endl;
    for(auto iter=Alpha.begin();iter!=Alpha.end();iter++)
    {
        outFile<<iter->first<<" "<<iter->second<<endl;
    }
    inFile.close();
    outFile.close();
    cout<<"处理完毕!"<<endl;
}
//将文本中大写转小写,或者小写转大写
void textTolowerOrToUpper(string inFileName,string oper)
{
    ifstream inFile;
    inFile.open(inFileName.c_str());
    if(!inFile)
    {
        ifstream inFile;
        //判断文件是否正确的读取
        std::cout<<"文件路径错误"<<endl;
        exit(0);
    }
    cout<<"请输入结果保存位置:";
    string outputFilename;
    cin>>outputFilename;
    ofstream outFile(outputFilename.c_str());
    string buff;
    while (getline(inFile,buff))
    {
        for(int i=0;i<buff.size();i++)
        {
           // char c=buff[i];
            if(isalpha(buff[i]))
            {
                if(oper=="UPPER")
                {
                    buff[i]=toupper(buff[i]);
                }else
                {
                   buff[i]=tolower(buff[i]);
                }    
            }
        }
        outFile<<buff<<endl;
    }
    inFile.close();
    outFile.close();
    cout<<"处理完毕"<<endl;
}
/*
*
*   查询文件中关键字出现的次数,并且输出每次出现的行数
*   并且能将结果保存在文件中
*
*/
void FindKey(string infilename,string key)
{
    ifstream inFile;
    inFile.open(infilename.c_str());
    if(!inFile)
    {
        ifstream inFile;
        //判断文件是否正确的读取
        std::cout<<"文件路径错误"<<endl;
        exit(0);
    }
    cout<<"请输入结果保存位置:";
    string outputFilename;
    cin>>outputFilename;
    ofstream outFile(outputFilename.c_str());
    string buff;
    int count=0;
    while (getline(inFile,buff))
    {
        count++;
        if(buff.find(key)!=buff.npos)
        {
            outFile<<"在第"<<count<<"行"
            <<"的"<<buff.find(key)<<"处"
            <<"  内容为:"<<buff<<endl;
        }
    }
    cout<<" 处理完毕"<<endl;
    inFile.close();
    outFile.close();
}
/*
*
* 关键词测试并且替换
*
*/
void replaceOrDeleteKey(string infilename,string key,string rkey,string oper)
{

    ifstream inFile;
    inFile.open(infilename.c_str());
    if(!inFile)
    {
        ifstream inFile;
        //判断文件是否正确的读取
        std::cout<<"文件路径错误"<<endl;
        exit(0);
    }
    cout<<"请输入结果保存位置:";
    string outputFilename;
    cin>>outputFilename;
    ofstream outFile(outputFilename.c_str());
    string buff;
    while (getline(inFile,buff))
    {
        if(buff.find(key)!=buff.npos)
        {
            if(oper=="REPLACE")
            {
                buff.replace(buff.find(key),buff.find(key)+rkey.size(),rkey);
            }
            else
            {
                buff.erase(buff.find(key),buff.find(key)+key.size());
            }
            
        }
            outFile<<buff<<endl;
    }
    if(oper=="REPLACE")
    {
        cout<<" 关键词替换处理完毕"<<endl;
    }else
    {
        cout<<" 关键词删除处理完毕"<<endl;
    }
    inFile.close();
    outFile.close();
}
int main()
{
    /*
    *--------------------------统计测试-------------------------------
    * */
    //统计文本中字母的个数
    //getAllAlpha(infliename);
    //将文件转为大写或者小写
    /*
    *
    * -----------------------------------大小写测试--------------------
    * */
    // string opr;
    // cout<<" 请输入将文件中字母大写还是小写:UPPER or LOWER:";
    // cin>>opr;
    // textTolowerOrToUpper(infliename,opr);
    /*
    *
    * ----------------关键词查找测试----------------------------
    * *
    * */
    // string key;
    // cout<<" 请输入要查找的关键字:";
    // cin>>key;
    // FindKey(infliename,key);
    /*
    *
    *-----------------------测试替换功能---------------------
    *-------------------------- 关键词删除--------------------
    *  *
    * ***/
    // string key;
    // cout<<" 请输入要替换的关键字:";
    // cin>>key;
    // cout<<" 请输入要替换为:";
    // string rkey;
    // cin>>rkey;
    // string oper;
    // //oper="REPLACE";
    // oper="DELETE";
    // replaceOrDeleteKey(infliename,key,rkey,oper);
    /*
    *
    * 
    * *----------------------------------main-----------------------------------
    *                          主函数
    * **/
    char c;
    do{
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<" 请输入你要进行的操作:  "<<endl;
    cout<<"q(统计文本字母) f(大小写) r(替换关键词) d(删除关键词) e(退出程序))  "<<endl;
    cin>>c;
    string infliename;
    string opr;
    string rkey;
    string key;
    switch (c)
    {
    case 'q':
        cout<<"请输入要处理的文件的位置:\n";
        cin>>infliename;
        getAllAlpha(infliename);
    break;
    case 'f':
        cout<<"请输入要处理的文件的位置:\n";
        cin>>infliename;
        cout<<" 请输入将文件中字母大写还是小写:UPPER or LOWER:";
        cin>>opr;
        textTolowerOrToUpper(infliename,opr);
    break;
    case 'r':
        cout<<"请输入要处理的文件的位置:\n";
        cin>>infliename;
        cout<<" 请输入要替换的关键字:";
        cin>>key;
        cout<<" 请输入要替换为:";
        cin>>rkey;
        opr="REPLACE";
    // oper="DELETE";
        replaceOrDeleteKey(infliename,key,rkey,opr);
        break;
    case 'd':
        cout<<"请输入要处理的文件的位置:\n";
        cin>>infliename;
        cout<<" 请输入要删除的关键字:";
        cin>>key;
        opr="DELETE";
        replaceOrDeleteKey(infliename,key,key,opr);
    break;
    default:
        break;
    }
    }while (c!='e');
   
    
    return 0;
}