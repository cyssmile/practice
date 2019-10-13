#include <iostream>
using namespace std;
namespace FULLC
{
    template<class T>
    class  A
    {
    private:
        T i;
    public:
        A(T t):i(t){};
        T comput()
        {
            //模板返回平方
            return i*i;
        }
        void show()
        {
            cout<<comput()<<endl;
        }
    };
    //类模板的完全特化
    template<> class A<int>
    {
        private:
            int i;
        public:
            A(int t):i(t){}
        int comput()
        {
            return i*i*i;//对int类型完全特化,返回立方
        }
         void show()
         {
             cout<<comput()<<endl;
         }
    };
}
int main()
{
    using namespace FULLC;
    //没有完全特化的
    A<double> dobj(2.5);
    A<int> bobj(2);
    dobj.show();
    bobj.show();
}
