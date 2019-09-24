/*
*
*利用优先队列实现细胞分裂
*
*
*
*/
#include<iostream>
#include<queue>
#include<ctime>
using namespace std;
const int SPLIT_TIME_MIN=500;
const int SPLIT_TIME_MAX=2000;
class Cell;
priority_queue<Cell> cellQueue;
class Cell
{
    private:
        static int count;//细胞总数
        int time;//细胞分裂时间
        int id;//当前细胞的编号
    public:
        //构造函数
        Cell(int birth):id(count++)
        {
            time=birth+(rand()%(SPLIT_TIME_MAX-SPLIT_TIME_MIN))+SPLIT_TIME_MIN; 
        }
        int getId() const
        {
            return id;
        }
        int getSplitTime() const
        {
            return time;//获取当前的分裂时间
        }
        bool operator <(const Cell &c)const
        {
            return time>c.time;
        }
        void split()const
        {
            //细胞分裂
            Cell child1(time),child2(time);
            cout<<time<<"##cell"<<id<<"split to "<<"cell# "<<child1.getId()
            <<"and cell2#"<<child2.getId()<<endl;
            cellQueue.push(child1);
            cellQueue.push(child2);
        }
};
 int Cell::count=0;
 int main()
 {
     srand(static_cast<unsigned>(time(0)));
     int t;//输入时间
     cout<<"模拟时间:";
     cin>>t;
     cellQueue.push(Cell(0));//将第一个细胞压入优先队列
     while (cellQueue.top().getSplitTime()<=t)
     {
         cellQueue.top().split();
         //cellQueue.top().
         cellQueue.pop();
     }
     return 0;

 }