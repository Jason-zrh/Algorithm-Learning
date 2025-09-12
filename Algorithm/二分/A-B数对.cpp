// A-BÊý¶Ô
// https://www.luogu.com.cn/problem/P1102

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main()
{
	int n, c;
	cin >> n >> c;
	unordered_map<int, int> map;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		map[nums[i]]++;
	}
	
	int ret = 0;
	for (auto e : nums)
	{
		if (map[e + c] != 0)
		{
			ret += (map[e] * map[e + c]);
		}
	}

	cout << ret << endl;
	return 0;
}