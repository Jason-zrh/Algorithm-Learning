// 唯一的雪花
// https://www.luogu.com.cn/problem/UVA11572
// 双指针使用环境：
// 单调性不回退的时候才可以用
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, ret = 0; 
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        // 双指针
        int left, right;
        left = right = 0;
        // 用哈希表维护窗口
        unordered_map<int, int> window;
        while(right < n)
        {
            
            // 先进窗口, unordered_map的[]的妙用
            window[nums[right]]++;
            // 判断窗口是否合法，如果不合法则移动左指针
            while(window[nums[right]] > 1)
            {
                window[nums[left]]--;
                left++;
            }

            // 走到这里窗口已经合法
            ret = max(ret, right - left + 1);
            right++;
        }

        cout << ret << endl;
    }
    return 0;
}