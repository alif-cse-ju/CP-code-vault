#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
long long sum[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,q,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        map<int,int>pos;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            pos[x]=i;
            sum[i]=sum[i-1]+x;
        }
        while(q--)
        {
            cin >> x;
            x=pos[x];
            cout << min(sum[x],sum[n]-sum[x-1]) << '\n';
        }
    }
    return 0;
}