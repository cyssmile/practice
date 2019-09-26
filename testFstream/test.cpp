#include<fstream>
#include<iostream>
#include<cstdlib>
using namespace std;
const double rate1=0.15;
const double rate2=0.25;
int main()
{
    ifstream inFile;
    ofstream outFile;
    double inputCount;
    double outputCount;
    inFile.open("./a.text");
    outFile.open("./out.text");
    if(inFile)
    {
        while (inFile>>inputCount)
        {
            if(inputCount<=1000)
            {
                outFile<<"money="<<inputCount*rate1<<" "
                <<"rate="<<rate1<<endl;
            }else
            {
                outFile<<"money="<<inputCount*rate2<<" "
                <<"rate="<<rate2<<endl;
            }
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