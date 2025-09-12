// 激光炸弹
// https://www.luogu.com.cn/problem/P2280


#include <iostream>
#include <vector>

using namespace std;

// 边长为n
const int N = 5e3 + 10;
int main() 
{
    // n个目标，炸弹边长是m
    int n, m;
    cin >> n >> m;
    vector<vector<int>> num;
    num.resize(N, vector<int>(N));

    while(n)
    {
        int x, y, v;
        cin >> x >> y >> v;
        x++,y++;
        num[x][y] += v;
        n--;
    }

    vector<vector<int>> prefix;
    prefix.resize(N, vector<int>(N));

    n = 5001;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] + num[i][j] - prefix[i - 1][j - 1];
        }
    }

    int ret = 0;
    m = min(m, n);
    for(int x2 = m; x2 <= n; x2++)
    {
        for(int y2 = m; y2 <= n; y2++)
        {
            int x1 = x2 - m + 1;
            int y1 = y2 - m + 1;

            ret = max(ret, prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1]);
        }
    }


    cout << ret << endl;

    return 0;
}