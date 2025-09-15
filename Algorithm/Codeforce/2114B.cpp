#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// 主逻辑函数：计算单个测试用例的最大 cost
int solveSingleCase(int n, const vector<int>& p) 
{
    vector<int> present(n + 1, 0);   // 标记哪些数已经出现
    vector<int> zeroPositions;       // 记录 0 的位置

    for (int i = 1; i <= n; i++) 
    {
        if (p[i] == 0) 
        {
            zeroPositions.push_back(i);
        } 
        else 
        {
            present[p[i]] = 1;
        }
    }

    // 找出缺失的数
    vector<int> missing;
    for (int v = 1; v <= n; v++) 
    {
        if (!present[v]) 
        {
            missing.push_back(v);
        }
    }

    // 计算第一个和最后一个“错位”的位置
    int left = 1;
    while (left <= n && p[left] == left) 
    {
        left++;
    }
    int right = n;
    while (right >= 1 && p[right] == right) 
    {
        right--;
    }

    // 如果没有错位，说明排列已经有序
    if (left > right) 
    {
        return 0;
    }

    // 特殊情况：唯一的零和唯一的缺失值恰好对应
    if (zeroPositions.size() == 1 && missing.size() == 1 &&
        zeroPositions[0] == missing[0]) 
    {
        int z = zeroPositions[0];

        // 重新计算 left, right（因为 p[z] = z 被迫对位）
        int newLeft = 1;
        while (newLeft <= n && (newLeft == z || p[newLeft] == newLeft)) 
        {
            newLeft++;
        }
        int newRight = n;
        while (newRight >= 1 && (newRight == z || p[newRight] == newRight)) 
        {
            newRight--;
        }

        if (newLeft > newRight) 
        {
            return 0;
        }
        return newRight - newLeft + 1;
    }

    // 正常情况
    return right - left + 1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) 
        {
            cin >> p[i];
        }
        cout << solveSingleCase(n, p) << "\n";
    }

    return 0;
}