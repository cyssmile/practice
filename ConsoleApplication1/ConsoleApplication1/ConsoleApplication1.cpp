#include "pch.h"
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
/*
*给定M*N 的矩阵若其中的某个元素为0，就将该行和列都转换成0
*/
namespace chys
{
	class MySolution
	{
	private:
		int M;//M行
		int N;//N列
		vector<int> res;//这里准备将M*N的矩阵保存为vector
	public:
		MySolution(int M, int N);//构造函数
		MySolution(vector<int> &ores, int M, int N);
		~MySolution();//析构函数
		void changeRow(vector<int> &res, int j);//改变列
		void changeLine(vector<int> &res, int i);//改变行
		void PrintMN();
		int getM()const;
		int getN()const;
	};
	int MySolution::getM()const 
	{
		return M;
	}
	int MySolution::getN()const
	{
		return N;
	}
	//改变行数据
	void  MySolution::changeLine(vector<int> &res, int i)
	{    //在每一次处理到行末尾的时候调用
		int num = 0;
		num += (i * N);
		for (int j = num; j < num + N; j++)
		{
			res[j] = 0;
		}
	}
	//处理列
	void  MySolution::changeRow(vector<int> &res, int j)
	{//将j列的所有的3改为0
		for (int i = j; i < M*N;)
		{
			res[i] = 0;
			i = i + N;//处理下一行的该列
		}
	}
	//处理传入矩阵的情况
	MySolution::MySolution(vector<int> &ores, int M, int N):M(M),N(N)
	{
		//先判断第一行是否有零，后将第一行当作存储空间
		bool isChangeFirstLine = false;
		for (int i=0;i<N;i++) 
		{
			if (ores[i] == 0) 
			{
				isChangeFirstLine = true;
			}
		}
		for (int i=0;i<M;i++) 
		{//遍历所有的元素,将需要将j列置为0的记录
			bool iscChangeELine = false;
			//从第2行开始需要将行换为0,的在行末尾进行操作
			for (int j=0;j<N;j++) 
			{
				if (ores[i*N + j] == 0) 
				{
					ores[j] == 0;
					if (i > 1) 
					{
						iscChangeELine = true;
					}
				}
				if (j %N == N - 1 && iscChangeELine)
				{
					//如果到了一行的末尾isChangeLine为真，就要处理该行
					changeLine(ores, i);
				}
			}
		}
		for (int i = 0; i < N; i++) 
		{
			//读取第一行，若存在某个元素为0将该列处理为0
			if (ores[i] == 0) 
			{
				changeRow(ores, i);
			}
		}
		//处理第一行
		if (isChangeFirstLine) 
		{
			for (int i=0;i<N;i++) 
			{
				ores[i] = 0;
			}
		}
		res = ores;
	}
	MySolution::MySolution(int M, int N) :M(M), N(N)
	{
		vector<int> res1(M*N);//申请M*N大小的一维数组		
		cout << " input the M*N martix" << endl;
		//初始化res1
		for (vector<int>::iterator iter=res1.begin();iter!=res1.end();iter++) 
		{
			*iter = 1;
		}
		for (int i = 0; i < M; i++)
		{
			//用于判断是否要处理行
			bool isChangeLine = false;
			int x;
			for (int j = 0; j < N; j++)
			{
				cin >> x;
				if (x == 0)
				{//如果该元素为零
				//处理列
					isChangeLine = true;
					changeRow(res1, j);
				}
				if (j %N == N - 1 && isChangeLine)
				{
					//如果到了一行的末尾isChangeLine为真，就要处理该行
					changeLine(res1, i);
				}
				//将该元素放入res1中
				if (res1[i*N + j] != 0) 
				{
					res1[i*N + j] = x;
				}	
			}
		}
		//返回给res
		res = res1;
	}
	MySolution::~MySolution(){}
	//输出处理的数据
	void MySolution::PrintMN()
	{
		cout << "输出的"<<MySolution::getM()<<"*"<< MySolution::getN() <<"矩阵为：" << endl;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << res[i*N + j] << " ";
			}
			cout << endl;
		}
	}
	/*
	*------------------
	*/
}

int main()
{
	while (true)
	{
		int M, N;
		cout <<"input the M and N" << endl;
		cin >> M >> N;
		using namespace chys;
		chys::MySolution mys(M, N);
		mys.PrintMN();

	}
	/*
	*添加一个动态的二维数组处理办法，省略输入
	*/

}