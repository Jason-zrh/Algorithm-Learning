#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        ll y;
        cin >> n >> y;
        vector<int> c(n);
        unordered_map<int, int> oldCount;
        int maxC = 0;
        for (int i = 0; i < n; i++) 
        {
            cin >> c[i];
            oldCount[c[i]]++;
            maxC = max(maxC, c[i]);
        }
        set<int> xset;
        int sqrtC = 450;
        for (int i = 0; i < n; ++i) 
        {
            for (int k = 1; k * k <= c[i]; ++k) 
            {
                int x = (c[i] + k - 1) / k;
                if (x > 1) xset.insert(x);
            }
            for (int x = 2; x <= sqrtC && x <= c[i]; ++x) 
            {
                xset.insert(x);
            }
        }
        xset.insert(maxC + 1);
        ll best = LLONG_MIN;
        vector<int> xlist(xset.begin(), xset.end());
        for (int idx = 0; idx < xlist.size(); ++idx) 
        {
            int x = xlist[idx];
            unordered_map<int, int> newCount;
            for (int i = 0; i < n; ++i) 
            {
                int newPrice = (c[i] + x - 1) / x;
                newCount[newPrice]++;
            }
            ll matches = 0;
            for (auto &p : newCount) 
            {
                int val = p.first;
                if (oldCount.count(val)) 
                {
                    matches += min(oldCount[val], p.second);
                }
            }
            ll printed = n - matches;
            ll income = 0;
            for (auto &p : newCount) income += 1LL * p.first * p.second;
            income -= printed * y;
            best = max(best, income);
        }
        cout << best << endl;
    }
    return 0;
}