// 跳石头
// https://www.luogu.com.cn/problem/P2678

#include <iostream>
#include <vector>
using namespace std;


int calc(int mid, int n, vector<int>& len)
{
    int c = 0;
    for(int i = 0; i <= n; i++)
    {
        int j = i + 1;
        while(j <= n + 1 && len[j] - len[i] < mid)
        {
            j++;
        }
        c += j - i - 1;
        i = j - 1;
    }
    return c;
}



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
        mid = (left + right + 1) / 2;
        if(calc(mid, n, len) <= m)
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
    }

    int ret = left;
    cout << ret << endl;

    return 0;
}