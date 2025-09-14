// 烦恼的高考志愿
// https://www.luogu.com.cn/problem/P1678
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> school(m + 1);
    school[0] = -1e5 + 10;
    for(int i = 1; i <= m; i++)
    {
        cin >> school[i];
    }
    sort(school.begin() + 1, school.end());
    school.push_back(1e5 + 10);

    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        int score = 0;
        cin >> score;
        // 特判：分数低于所有学校
        if(score <= school[1]) 
        {
            ret += school[1] - score;
            continue;
        }
        // 特判：分数高于所有学校
        if(score >= school[m]) 
        {
            ret += score - school[m];
            continue;
        }
        // 二分查找最近的两个学校分数
        int left = 1, right = m;
        int mid = 0;
        while(left < right) 
        {
            mid = (left + right) / 2;
            if(school[mid] < score) 
            {
                left = mid + 1;
            } else 
            {
                right = mid;
            }
        }
        // left为第一个>=score的学校
        int upper = left;
        int lower = left - 1;
        ret += min(abs(score - school[lower]), abs(school[upper] - score));
    }

    cout << ret << endl;
    return 0;
}