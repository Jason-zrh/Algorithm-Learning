// // 逛画展
// // https://www.luogu.com.cn/problem/P1638

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 方法一：超时
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> nums(n + 1);
//     for(int i = 1; i <= n; i++)
//         cin >> nums[i];

//     // 依旧用哈希表维护窗口信息
//     unordered_map<int, int> window;
//     // 初始化窗口
//     for(int i = 1; i <= m; i++)
//         window[i] = 0;
    
//     // 初始化双指针
//     int left, right, prev;
//     left = right = 1;
//     prev = INT_MAX;
//     pair<int, int> ret;

//     while(right <= n)
//     {
//         window[nums[right]]++;
//         // 判断窗口是否合法
//         int flag = 0;
//         for(auto e : window)
//         {
//             if(e.second == 0)
//             {
//                 flag = 1;
//                 break;
//             }
//         }

//         // 窗口合法
//         while(flag == 0)
//         {
//             int price = 0;
//             // 比较购票价格，如果比已有方案小则替换
//             for(auto e : window)
//                 price += e.second;

//             // 比已有方案便宜, 替换解决方案
//             if(price < prev)
//             {
//                 prev = price;
//                 ret.first = left;
//                 ret.second = right;
//             }
//             // 保存方案后left一直向右走，直到窗口不合法，每次向右走都要更新一次价格
//             window[nums[left]]--;
//             left++;
//             for(auto e : window)
//             {
//                 if(e.second == 0)
//                 {
//                     flag = 1;
//                     break;
//                 }
//             }            
//         }
//         // 窗口不合法
//         right++;
//     }
    
//     cout << ret.first << " " << ret.second << endl;
//     return 0;
// }


// 方法二：优化版本， 用一个变量cnt来记录已经出现的画

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> nums[i];
    
    // 尝试用数组维护窗口信息
    vector<int> window(m + 1);
    for(int i = 1; i <= m; i++)
        window[i] = 0;
    
    int left, right, cnt;
    left = right = 1;
    cnt = 0;

    pair<int, int> ret;
    int prev = 1e6 + 10;
    while(right <= n)
    {
        if(window[nums[right]] == 0)
        {
            cnt++;
            
        }
        window[nums[right]]++;
        // 判断窗口合法
        while(cnt == m)
        {
            int cur = right - left + 1;
            if(cur < prev)
            {
                // 保存结果
                ret.first = left;
                ret.second = right;
                prev = cur;
            }

            // left右移直到不合法
            window[nums[left]]--;
            if(window[nums[left]] == 0)
                cnt--;
            left++;
        }

        // 窗口不合法
        right++;

    }

    cout << ret.first << " " << ret.second << endl;

    return 0;
}