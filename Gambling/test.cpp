#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    const int delf=8;
    ifstream in("./input.txt");
    ofstream out("./output.txt");
    string buffer;
    while(getline(in,buffer))
    {
        buffer.insert(delf,"X");
        out<<buffer<<'\n';
    }
    in.close();
    out.close();
  return 0;
}
