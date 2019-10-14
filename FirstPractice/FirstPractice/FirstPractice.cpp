#include "pch.h"
#include <iostream>
#include<map>
#include<iterator>
#include<string>
#include <vector>
#include<algorithm>
using namespace std;
namespace chys 
{
	/*
	*统计石头中的宝石数
	*/
	const int& Get_Jewels_in_Stone(const string& jewels,const string& stone) 
	{
		map<char, int> StoneMap;
		for (int i=0;i<stone.size();i++) 
		{	//将石头加入map中去
			char c = stone[i];
			StoneMap[c]++;
		}
		//统计宝石的数目
		static int count = 0;
		for (int i=0;i<jewels.size();i++) 
		{
			char jew = jewels[i];
			count += StoneMap.find(jew)->second;
		}
		return count;
	}
	/*
	*将一个输入的字符串按照一个标志符号，处理
	*然后将每一段存在vector<string>容器中
	*/
	const vector<string>& SplitString(const string& buff ,const char& pattern) 
	{
		static vector<string> result;
		string s;//用于存储每一次切割的部分
		//存储找到的位置
		string::size_type pos;
		int size = buff.size();
		for (int i=0;i<size;i++) 
		{	//找到要切割的地点
			pos = buff.find(pattern,i);
			if (pos < size) 
			{
				s = buff.substr(i, pos-i);
				//将切割好的放入vector<string>中去
				result.push_back(s);
				//将i游标向前移动s.size()的长度
				i = i + s.size();
			}
		}
		//返回查找的结果
		return result;
	}
/*
*
*/
	class MySolution 
	{
		private:
			vector<vector<int>> res;
			int count;
			int k;
		public:
			MySolution(int n,int k):count(n),k(k)
			{
				vector<int> s;
				for (int i=0;i<n;i++) 
				{
					s.push_back(i+1);
				}

				res = SubNet(s);
			}
			vector<vector<int>> SubNet(vector<int> &s) 
			{
				//初始化res
				res.clear();
				//对s进行排序
				sort(s.begin(), s.end());
				//tempres用于暂存
				vector<int> tempres;
				dfs(s, 0, tempres);
				return res;
			}
			/*
			*dfs 
			*/
			void dfs(vector<int> &s, int iend,vector<int>& tempres)
			{
				if (iend == s.size()) 
				{
					res.push_back(tempres);
					return;
				}
				//选择s[iend]
				tempres.push_back(s[iend]);
				dfs(s, iend + 1,tempres);
				//不选择s[iend]
				tempres.pop_back();
				dfs(s, iend + 1, tempres);
			}
			void PrintRes() 
			{
				cout << "[" << endl;
				for (int i = 0; i < res.size(); i++) 
				{
					if (res[i].size() == k) 
					{
						cout << "[ ";
						for (int j=0;j<k;j++) 
						{
							cout << res[i][j] << " ";
						}
						cout << "] ," << endl;
					}
				}
				cout << "]" << endl;
			}

	};
	void testSecond() 
	{
		using namespace chys;
		int n, k;
		cin >> n >> k;
		chys::MySolution test(n, k);
		test.PrintRes();
	}
	/*
	* test
	*/
	void testFirst() 
	{
		string jewels, stone;
		/*
		*-------------测试SplitString函数
		*/
		string buff;
		getline(cin, buff);
		char pattern = '"';
		vector<string> result = SplitString(buff, pattern);
		jewels = result[1];
		stone = result[3];
		int count = chys::Get_Jewels_in_Stone(jewels, stone);
		cout << count << endl;
	}
}
int main()
{
	using  namespace chys;
	//testFirst();
	testSecond();
	return 0;
}