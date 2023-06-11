#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(__builtin_popcount(n+1) == 1)cout << n+1 << '\n';
        else
        {
            for(i=29;i>=0;i--)
            {
                if((n >> i) & 1)
                {
                    cout << (1 << i) << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}