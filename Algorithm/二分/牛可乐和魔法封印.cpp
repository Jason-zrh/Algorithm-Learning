// https://ac.nowcoder.com/acm/problem/235558

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n + 1, 0);

	int len = nums.size();
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}

	
	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;

		int left = 1, right = len - 1;
		int mid = 0;

		int retleft = 0;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (nums[mid] >= x)
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}

		if (nums[left] < x)
		{
			cout << 0 << endl;
			continue;
		}
		else
		{
			retleft = left;
		}

		left = 1, right = len - 1;
		mid = 0;
		while (left < right)
		{
			mid = (left + right + 1) / 2;
			if (nums[mid] <= y)
			{
				left = mid;
			}
			else
			{
				right = mid - 1;
			}
		}

		if (nums[left] <= y)
		{
			cout << left - retleft + 1 << endl;
		}
		else
		{
			cout << left - retleft << endl;
		}
	}
	return 0;
}