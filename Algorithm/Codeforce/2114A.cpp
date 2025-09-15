#include <iostream>
#include <vector>
using namespace std;

bool all_different(int a, int b, int c) 
{
    return a != b && b != c && a != c; 
}

int main() 
{
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;
        vector<int> a(n+1);
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            sum[i] = sum[i-1]+a[i];
        }

        bool found = false;
        for(int l=1;l<=n-2 && !found;l++)
        {
            for(int r=l+1;r<=n-1 && !found;r++)
            {
                int s1 = sum[l]%3;
                int s2 = (sum[r]-sum[l])%3;
                int s3 = (sum[n]-sum[r])%3;

                if(s1==s2 && s2==s3 || all_different(s1,s2,s3))
                {
                    cout << l << " " << r << "\n";
                    found = true;
                }
            }
        }
        if(!found) cout << "0 0\n";
    }
    return 0;
}