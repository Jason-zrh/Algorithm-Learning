// A-B数对
// https://www.luogu.com.cn/problem/P1102

#include <iostream>
#include <vector>


// A - B = C
//    |
// B = A - C 
// 可以枚举所有的A - C，看看有多少个B，这时就存在二段性
using namespace std;

int main()
{
	int n, c;
	cin >> n >> c;
	vector<int> nums(n + 1);
	for(int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}


	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		int retleft = 0;
		int target = nums[i] - c;


		// 二分查找有多少个target
		// 先找左端点
		int left = 1, right = i;
		int mid = 0;
		while(left < right)
		{
			mid = (left + right) / 2;
			if(nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		if(nums[left] != target)
		{
			continue;
		}
		else
		{
			retleft = left;
		}


		// 找右侧端点	
		left = 1, right = i;
		mid = 0;
		while(left < right)
		{
			mid = (left + right + 1) / 2;
			if(nums[mid] > target)
			{
				right = mid - 1;
			}
			else
			{
				left = mid;
			}
		}
		// 更新结果
		ret += (left - retleft + 1);
	}

	cout << ret << endl;
	return 0;
}
