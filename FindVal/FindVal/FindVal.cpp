#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
namespace  chys {
	class Solution 
	{
		public:
			template<class InputIter,class T>
			inline InputIter find(InputIter first,
								InputIter last,
								const T& val) 
			{
				while (first!=last &&!(*first==val))
				{
					first++;
				}
				return first;
			}
	};
}
int main()
{
	vector<int> vec;
	int N,val;
	cin >> N >> val;
	for (int i=0;i<N;i++) 
	{
		vec.push_back(i + 1);
	}
	vector<int>::iterator first = vec.begin();
	vector<int>::iterator last = vec.end();
	vector<int>::iterator res = find(first, last, val);
	cout << *res << endl;
}