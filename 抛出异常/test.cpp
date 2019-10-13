#include<iostream>
using namespace std;
int main()
{
     string str;
    cout<<"input a string:"<<endl;
    cin>>str;
    int beg,last;
    while (true)
    {
        cout<<"erase begin to end"<<endl;
        cin>>beg>>last;
        try
        {
            str.erase(beg,last);
        }
        catch(out_of_range)
        {
            continue;
        }
        break;
    }
}