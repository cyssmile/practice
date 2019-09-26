#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
const double rate1=0.15;
const double rate2=0.25;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("./txt.in");
    outFile.open("./txt.out");
    string buff;
    if(inFile)
    {
        while (getline(inFile,buff,'\n'))
        {
            reverse(buff.begin(),buff.end());
            outFile<<buff<<'\n';
        }
    }else
    {
        cout<<"open erro"<<endl;
        exit(0);
    }
    inFile.close();
    outFile.close();
    return 0;
}