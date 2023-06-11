#pragma GCC optimize("Ofast")
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
        if(n & 1)
        {
            for(i=1;i<=n;i++)cout << i << ' ';
        }
        else
        {
            if(n == 2)cout << "-1";
            else
            {
                cout << "2 3 1 4 ";
                for(i=5;i<=n;i++)cout << i << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}