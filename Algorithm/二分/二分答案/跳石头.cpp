// 跳石头
// https://www.luogu.com.cn/problem/P2678

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> len(n + 2);
    len[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> len[i];
    }
    len[n + 1] = l;
    
    int left = 0, right = l;
    int mid = 0;
    while(left < right)
    {
        mid = (left + right) / 2;
        
    }
    return 0;
}