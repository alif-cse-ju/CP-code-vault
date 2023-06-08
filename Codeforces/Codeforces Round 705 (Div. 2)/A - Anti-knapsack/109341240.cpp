#include<bits/stdc++.h>
using namespace std;
const int N=1024+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,m,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        m=(k+1)/2;
        cout << n-m << '\n';
        for(i=m;i<=n;i++)
        {
            if(i == k)continue;
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;