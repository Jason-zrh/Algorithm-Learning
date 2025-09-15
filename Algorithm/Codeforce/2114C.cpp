#include<iostream>
#include<vector>
using namespace std;

const long long MOD = 998244353;

int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];

        // dp[i][0] = 第i个不交换，dp[i][1] = 第i个交换
        vector<vector<long long>> dp(n+1, vector<long long>(2,0));

        dp[1][0] = 1; // 第1个不交换
        dp[1][1] = 1; // 第1个交换

        for(int i=2;i<=n;i++)
        {
            // 不交换
            if(a[i] >= a[i-1] && b[i] >= b[i-1]) dp[i][0] = (dp[i][0] + dp[i-1][0]) % MOD;
            if(a[i] >= b[i-1] && b[i] >= a[i-1]) dp[i][0] = (dp[i][0] + dp[i-1][1]) % MOD;
            // 交换
            if(b[i] >= a[i-1] && a[i] >= b[i-1]) dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
            if(b[i] >= b[i-1] && a[i] >= a[i-1]) dp[i][1] = (dp[i][1] + dp[i-1][1]) % MOD;
        }

        cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }
    return 0;
}