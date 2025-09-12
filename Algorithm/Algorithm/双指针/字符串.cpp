// 字符串
// https://ac.nowcoder.com/acm/problem/18386

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string str;
    cin >> str;

    // 用哈希表维护窗口信息
    unordered_map<char, int> window;
    // cnt用来维护已经出现字母个数
    int cnt = 0;

    // 初始化双指针
    int left, right, ret;
    left = right = 0;
    ret = 1e6 + 10;

    while(right < str.size())
    {
        
        if(window[str[right]] == 0)
        {
            cnt++;
        }
        window[str[right]]++;

        // 判断窗口合法
        while(cnt == 26)
        {
            // 更新结果
            ret = min(ret, right - left + 1);
            
            // 移动左指针
            window[str[left]]--;
            if(window[str[left]] == 0)
            {
                cnt--;
            }
            left++;
        }

        right++;
    }

    cout << ret << endl;
    return 0;
}