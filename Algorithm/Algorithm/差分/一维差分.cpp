// 一维差分
//  https://ac.nowcoder.com/acm/problem/226303
// 使用差分数组：f[i] = a[i] - a[i - 1]
// 或者直接用性质创建:
//f[i] += a[i]; 
//f[i + 1] -= a[i]
// 原数组a[]: L -> R 位置+k.  f[]:  f[L] += k, f[R + 1] -= k
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    nums.resize(n + 2, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    vector<int> dif;
    dif.resize(n + 2);
    // 多走一格处理边界情况
    for(int i = 1; i <= n + 1; i++)
    {
        dif[i] = nums[i] - nums[i - 1];
    }

    // 处理m次问询
    while(m)
    {
        int l, r, k;
        cin >> l >> r >> k;
        dif[l] += k;
        dif[r + 1] -= k;
        m--;
    }

    // 前缀和还原数组
    vector<int> prefix;
    prefix.resize(n + 2, 0);
    for(int i = 1; i <= n; i++)
    {
        prefix[i] = dif[i] + prefix[i - 1];
    }

    for(int i = 1; i <= n; i++)
    {
        cout << prefix[i] << " ";
    }
    cout << endl;

    return 0;
} 