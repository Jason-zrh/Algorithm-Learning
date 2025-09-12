// 二维差分
// https://ac.nowcoder.com/acm/problem/226337
#include <iostream>
#include <vector>
using namespace std;


int main()
{   
    int n, m, q;
    cin >> n >> m >> q;
    
    // 利用性质创建差分数组
    vector<vector<int>> dif(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int k;
            cin >> k;
            dif[i][j] += k;
            dif[i + 1][j + 1] += k;

            dif[i + 1][j] -= k;
            dif[i][j + 1] -= k;
        }
    }
    
    // 处理q次修改
    while(q)
    {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        dif[x1][y1] += k;
        dif[x2 + 1][y2 + 1] += k;
        
        dif[x2 + 1][y1] -= k;
        dif[x1][y2 + 1] -= k;
        q--;
    }


    // 前缀和还原数组
    vector<vector<int>> prefix(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            prefix[i][j] = dif[i][j] + prefix[i][j - 1] + prefix[i - 1][j] -  prefix[i - 1][j - 1];
        }
    }


    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}