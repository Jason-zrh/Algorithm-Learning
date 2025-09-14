// 砍树
// https://www.luogu.com.cn/problem/P1873
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> tree(n);
    ll right = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> tree[i];
        right = max(right, tree[i]);
    }

    ll left = 0, mid = 0;
    while(left < right)
    {
        mid = (left + right + 1) / 2;
        ll c = 0;
        for(auto e : tree)
        {
            if(e >= mid)
            {
                c += (e - mid);
            }
        }

        if(c >= m)
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
    }

    ll ret = left;
    cout << ret << endl;
    return 0;
}