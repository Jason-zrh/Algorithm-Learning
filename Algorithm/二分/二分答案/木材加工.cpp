// 木材加工
// https://www.luogu.com.cn/problem/P2440
#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> log(n);
    int right = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> log[i];
        right = max(log[i], right);
    }

    // 对答案进行二分
    int left = 0;
    int mid = 0;
    while(left < right)
    {
        int c = 0;
        mid = (left + right + 1) / 2;
        for(auto e : log)
        {
            c += (e / mid);
        }

        if(c < k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid;
        }
    }
    
    int ret = left;
    cout << ret  << endl;

    return 0;
}