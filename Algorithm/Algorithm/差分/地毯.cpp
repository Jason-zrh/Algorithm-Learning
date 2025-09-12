// 地毯
// https://www.luogu.com.cn/problem/P3397
#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n + 2, vector<int>(n + 2));
    while(m)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        nums[x1][y1]++;
        nums[x2 + 1][y2 + 1]++;

        nums[x2 + 1][y1]--;
        nums[x1][y2 + 1]--;
        m--;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            nums[i][j] = nums[i][j - 1] + nums[i - 1][j] + nums[i][j] - nums[i - 1][j - 1];
        }
    }


    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}