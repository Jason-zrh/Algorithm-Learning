// 二分查找：数据有序且有明显分层需求的时候可以考虑二分算法
// 二分算法模板

// 找左端点
/*
	int left = 1, right = n;
	while (left < right)
	{
		mid = (left + right) / 2;
		if(check(mid) >= target)
		{
			right = mid
		{
		else
		{
			left = mid + 1;
		}
	}
	// 判断left所指位置与target关系
*/


// 找右端点

/*
	int left = 1, right = n;
	while(left < right)
	{
		mid = (left + right + 1) / 2;
		if(check(mid) <= target)
		{
			left = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	// 判断left所指位置与target关系
*/

//https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// 在排序数组中查找第一个和最后一个位置
#include<iostream>
#include<vector>
using namespace std;

//class Solution
//{
//public:
//    vector<int> searchRange(vector<int>& nums, int target)
//    {
//        if (nums.size() == 0)
//        {
//            return { -1, -1 };
//        }
//        vector<int> ret;
//        // 先找到第一个出现的位置
//        int left, right;
//        left = 0, right = nums.size() - 1;
//        int mid = 0;
//        while (left < right)
//        {
//            mid = (left + right) / 2;
//            // mid大于目标值
//            if (nums[mid] >= target)
//            {
//                right = mid;
//            }
//            // mid小于目标值
//            else
//            {
//                left = mid + 1;
//            }
//        }
//
//        // 走到这里left和right已经重叠了，判断是否命中目标值
//        if (nums[left] != target)
//        {
//            return { -1, -1 };
//        }
//        else
//        {
//            ret.push_back(left);
//        }
//
//
//        // 再找最后一个位置
//        left = 0, right = nums.size() - 1;
//
//        while (left < right)
//        {
//            mid = (left + right + 1) / 2;
//            if (nums[mid] > target)
//            {
//                right = mid - 1;
//            }
//            else
//            {
//                left = mid;
//            }
//        }
//
//        ret.push_back(left);
//        return ret;
//    }
//};


