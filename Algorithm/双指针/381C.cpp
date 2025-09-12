// https://codeforces.com/problemset/problem/381/C
// Sereja and Prefixes
#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<int> ret;
    ret.push_back(0);
    int m;
    cin >> m;
    while(m--)
    {
        int s1;
        cin >> s1;
        // stage1 -> 直接在最后插入数字
        if(s1 == 1)
        {
            int num;
            cin >> num;
            ret.push_back(num);
        }
        // stage2 -> 复制序列并重复添加至最后
        else
        {
            int l, c;
            cin >> l >> c;
            while(c--)
            {
                int left = 1, right = l;
                while(left <= right)
                {
                    ret.push_back(ret[left++]);
                }
            }
        }
    }


    int n;
    cin >> n;
    while(n--)
    {
        int order;
        cin >> order;
        cout << ret[order] << " ";
    }

    cout << endl;
    return 0;
}