#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t;
    long long x,y,mx,sum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum=mx=0;
        for(i=0;i<n;i++)
        {
            cin >> x;
            sum+=x;
            mx=max(mx,x);
        }
        y=(sum+n-2)/(n-1);
        if(mx > y)cout << mx*(n-1)-sum << '\n';
        else cout << y*(n-1)-sum << '\n';
    }
    return 0;