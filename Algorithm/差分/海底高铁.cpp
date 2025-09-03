// 海底高铁
// https://www.luogu.com.cn/problem/P3406
#include <iostream>
#include <vector>

using namespace std;

vector<int> journey;

int main()
{
    int n, m;
    cin >> n >> m;
    // 存储车站信息
    journey.resize(m);
    for(int i = 0; i < m; i++)
    {
        cin >> journey[i];
    }

    

    // 创建差分数组, 这里的初始差分数组全为0
    vector<int> dif;
    dif.resize(n + 1, 0);
    // 双指针遍历车站信息，处理差分数组
    for(int l = 0; l < m - 1; l++)
    {
        int r = l + 1;
        // 此时的prev , next 相当于l， r
        // 判断一下往回坐的情况
        int pl, pr = 0;
        pl = min(journey[l], journey[r]);
        pr = max(journey[l], journey[r]);
        
        dif[pl]++, dif[pr]--;
    }

   

    //处理车站信息完成，前缀和还原数组
    vector<int> prefix;
    prefix.resize(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + dif[i];
    }

    // 储存结果
    int ret;
    for(int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ret += min(a * prefix[i], c + b * prefix[i]);
    }

    cout << ret << endl;

    return 0;
}