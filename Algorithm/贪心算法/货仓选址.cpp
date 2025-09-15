// 货仓选址
// https://www.luogu.com.cn/problem/P10452

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int n = 0;
    cin >> n;
    vector<int> store(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> store[i];
    }
    sort(store.begin(), store.end());

    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        ret += abs(store[i] - store[(n + 1) / 2]);
    }

    cout << ret << endl;
    return 0;
}