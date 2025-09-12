// 最大子段和
// https://www.luogu.com.cn/problem/P1115

#include <iostream>
#include <vector>


using namespace std;
typedef long long ll;


// 暴力求解 TLE 了哥们
// int main()
// {
//     ll n;
//     cin >> n;
//     vector<ll> v;
//     v.resize(n + 1);
//     v[0] = 0;
//     for(ll i = 1; i < n + 1; i++)
//     {
//         cin >> v[i];
//     }

//     // 前缀和数组已经构建完成
//     vector<ll> f;
//     f.resize(n + 1);
//     f[0] = 0;
//     for(ll i = 1; i < n + 1; i++)
//     {
//         f[i] = f[i - 1] + v[i];
//     }
    
//     ll ret = -1e5 + 2;
//     for(ll i = 1; i < n + 1; i++)
//     {
//         for(ll j = i; j < n + 1; j++)
//         {
//             ret = max(ret, f[j] - f[i - 1]);
//         }
//     }

//     cout << ret << endl;
//     return 0;
// }

// 改进方法

int main()
{
    int n = 0; 
    cin >> n;
    vector<int> prefix;
    prefix.resize(n);
    prefix[0] = 0;
    for(int i = 1; i < n + 1; i++)
    {
        int num;
        cin >> num;
        prefix[i] = prefix[i - 1] + num;
    }

    int ret = -2e5 + 10;
    int prevmin = 0;
    for(int i = 1; i < n + 1; i++)
    {
        ret = max(ret, prefix[i] - prevmin);
        prevmin = min(prevmin, prefix[i]); 
    }

    cout << ret << endl;
    return 0;
}