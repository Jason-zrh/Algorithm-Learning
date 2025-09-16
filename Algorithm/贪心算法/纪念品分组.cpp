// 纪念品分组
// https://www.luogu.com.cn/problem/P1094
// 交换论证法：当最优解不失最优性的前提下可以调整到贪心解
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int w, n;
    cin >> w >> n;
    vector<int> value(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    sort(value.begin(), value.end());

    int left = 0, right = n - 1;
    int ret = 0;
    while(left <= right)
    {
        if(value[left] + value[right] <= w) left++, right--;
        else right--;
        
        ret++;
    }

    cout << ret << endl;
    return 0;
}