// https://codeforces.com/problemset/problem/381/A
// Sereja and Dima

#include <iostream>
#include <vector>


using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> cards(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> cards[i];
    }

    int Sereja = 0, Dima = 0;
    int left = 1, right = n;

    while(left <= right)
    {
        if(left == right)
        {
            Sereja += cards[left];
            break;
        }
        // Sereja先手选
        Sereja += max(cards[right], cards[left]);
        if(cards[left] > cards[right])
        {
            left++;
        }
        else
        {
            right--;
        }

        // Dima后选
        Dima += max(cards[right], cards[left]);
        if(cards[left] > cards[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << Sereja << " " << Dima << endl;
    return 0;
}