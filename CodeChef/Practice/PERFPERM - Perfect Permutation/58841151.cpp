#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(k == n-1)
        {
            cout << n << ' ';
            for(i=2;i<n;i++)cout << i << ' ';
            cout << "1\n";
            continue;
        }
        for(i=1;i<=k;i++)cout << i << ' ';
        for(i=k+1;i<n;i++)cout << i+1 << ' ';
        if(k < n)cout << k+1;
        cout << '\n';
    }
    return 0;
}