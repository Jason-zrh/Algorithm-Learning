// 烦恼的高考志愿
// https://www.luogu.com.cn/problem/P1102

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int main()
{
    ll m, n;
    cin >> m >> n;
    vector<ll> school(m + 1);
    for(int i = 1; i <= m; i++)
    {
        cin >> school[i];
    }
    sort(school.begin() + 1, school.end());


    ll ret = 0;
    for(ll i = 1; i <= n; i++)
    {

        
        ll score = 0;
        cin >> score;



        // 二段性，左侧都是比score小的，右边都是比score大的，然后看左右哪个与score的差值更小
        ll left = 1, right = m;
        ll mid = 0;
        while(left < right)
        {   
            mid = (left + right) / 2;
            if(school[mid] < score)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if(school[left] > score)
        {
            left--;
        }
        ll retleft = left;



        left = 1, right = m;
        mid = 0;
        while(left < right)
        {
            mid = (left + right + 1) / 2;
            if(school[mid] > score)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }
        if(school[left] < score)
        {
            right++;
        }
        ll retright = right;


        ret += min((score - school[retleft]), (school[retright] - score));
    }

    cout << ret << endl;
    return 0;
}