// 丢手绢
// https://ac.nowcoder.com/acm/problem/207040

#include <iostream>
#include <vector>

using namespace std;


// int main()
// {
//     int n, sum = 0;
//     cin >> n;
//     vector<int> a(n + 1);
//     for(int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         sum += a[i];
//     }

//     int left = 1, right = 1;
//     int k = 0;
//     int ret = 0;
//     while(right <= n)
//     {
//         k += a[right];
//         while(2 * k >= sum)
//         {
//             ret = max(ret, sum - k);
//             k -= a[left];
//             left++;
//         }

//         ret = max(ret, k);
//         right++;
//     }

//     cout << ret << endl;
//     return 0;
// }


int main()
{
    int n, sum = 0;
    cin >> n;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    int left, right, ret = 0;
    int k = 0;
    left = right = 1;
    // 滑动窗口
    while(right <= n)
    {
        // 直接用一个变量维护窗口
        k += nums[right];

        // 窗口不合法
        while(k * 2 >= sum)
        {
            ret = max(ret, sum - k);
            k -= nums[left];
            left++;
        }



        ret = max(ret, k);
        right++;
    }

    cout << ret << endl;
    return 0;
}