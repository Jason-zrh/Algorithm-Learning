// 二维前缀和
// https://ac.nowcoder.com/acm/problem/226333
#include <iostream>
#include <vector>


using namespace std;
typedef long long ll;

int main()
{
    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> prefix;
    prefix.resize(n + 1, vector<ll>(m + 1));
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            ll num;
            cin >> num;
            prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1] + num;
        }
    }


    while(q)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1] << endl;;
        q--;
    }
    return 0;
}