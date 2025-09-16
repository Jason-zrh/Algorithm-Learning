// 排座位
// https://www.luogu.com.cn/problem/P1056
#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;

struct Node
{
    int index;
    int cnt;
}row[N], col[N];


bool cmpcnt(Node& x, Node& y)
{
    return x.cnt > y.cnt;
}

bool cmpindex(Node& x, Node& y)
{
    return x.index < y.index;
}
int main()
{
    int m, n, k, l, d;
    cin >> m >> n >> k >> l >> d;
    for(int i = 1; i <= m; i++)
    {
        row[i].index = i;
    }
    for(int j = 1; j <= n; j++)
    {
        col[j].index = j;
    }
    while(d--)
    {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        if(x == p)
        {
            col[min(y, q)].cnt++;
        }
        else
        {
            row[min(x, p)].cnt++;
        }
    }

    sort(col + 1, col + 1 + n, cmpcnt);
    sort(row + 1, row + 1 + m, cmpcnt);

    sort(col + 1, col + 1 + l, cmpindex);
    sort(row + 1, row + 1 + k, cmpindex);

    for(int i = 1; i <= k; i++)
    {
        cout << row[i].index << " ";
    }
    cout << endl;
    for(int i = 1; i <= l; i++)
    {
        cout << col[i].index << " ";
    }
    cout << endl;

    return 0;
}