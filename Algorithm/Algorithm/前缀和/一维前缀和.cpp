// 一维前缀和
// https://ac.nowcoder.com/acm/problem/226282


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
 {
   
    int n, m;
    cin >> n >> m;
    vector<int> v;
    v.resize(n + 1);
    v[0] = 0;
    for(int i = 1 ; i < n + 1; i++)
        cin >> v[i];
        
    vector<int> f;
    f.resize(n + 1);
    for(int i = 1; i < n + 1; i++)
    {
        f[i] = f[i - 1] + v[i];
    }

    while(m)
    {
        int l, r;
        cin >> l >> r;
        cout << f[r] - f[l - 1] << endl;
        m--;
    }
    return 0;
}