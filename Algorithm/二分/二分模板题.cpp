// ���ֲ��ң����������������Էֲ������ʱ����Կ��Ƕ����㷨
// �����㷨ģ��

// ����˵�
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
	// �ж�left��ָλ����target��ϵ
*/


// ���Ҷ˵�

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
	// �ж�left��ָλ����target��ϵ
*/

//https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// �����������в��ҵ�һ�������һ��λ��
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
//        // ���ҵ���һ�����ֵ�λ��
//        int left, right;
//        left = 0, right = nums.size() - 1;
//        int mid = 0;
//        while (left < right)
//        {
//            mid = (left + right) / 2;
//            // mid����Ŀ��ֵ
//            if (nums[mid] >= target)
//            {
//                right = mid;
//            }
//            // midС��Ŀ��ֵ
//            else
//            {
//                left = mid + 1;
//            }
//        }
//
//        // �ߵ�����left��right�Ѿ��ص��ˣ��ж��Ƿ�����Ŀ��ֵ
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
//        // �������һ��λ��
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


