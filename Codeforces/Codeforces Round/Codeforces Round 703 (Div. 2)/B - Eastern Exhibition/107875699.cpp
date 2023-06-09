#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
long long x[1002],y[1002];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> x[i] >> y[i];
        if(n & 1)cout << "1\n";
        else
        {
            sort(x+1,x+n+1);
            sort(y+1,y+n+1);
            cout << (x[n/2+1]-x[n/2]+1)*(y[n/2+1]-y[n/2]+1) << '\n';
        }
    }
    return 0;