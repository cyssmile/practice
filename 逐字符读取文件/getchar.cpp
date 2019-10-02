#include<fstream>
#include<iostream>
using namespace std;
int main()
{
    ifstream inFlieStream;
    inFlieStream.open("./test.in",ios::in|ios::binary);
    ofstream outFile("b.text");
    if(!inFlieStream)
    {
        cout<<"open txt failed"<<endl;
        return 1;
    }
    char c;
    while (!inFlieStream.eof())
    {//判断是否读取到文件的末尾了    !inFlieStream.eof()
        inFlieStream.get(c);//逐字符的读取文件
        outFile<<c;
    }
    inFlieStream.close();
    return 0;
}