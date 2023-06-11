#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int a[M],par[M],sum[M];
int FindParent(int x)
{
    if(par[x] == x)return x;
    return par[x]=FindParent(par[x]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,q,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            a[i]=__builtin_popcount(a[i])%2,par[i]=i,sum[i]=a[i];
        }
        while(q--)
        {
            cin >> x >> y >> z;
            if(x == 1)
            {
                y=FindParent(y),z=FindParent(z);
                if(y != z)sum[y]+=sum[z],par[z]=y;
            }
            else if(x == 2)
            {
                z=__builtin_popcount(z)%2;
                sum[FindParent(y)]+=z-a[y],a[y]=z;
            }
            else
            {
                y=FindParent(y);
                if(sum[y] >= z  &&  (sum[y]-z)%2 == 0)cout << "Yes\n";
                else cout << "No\n";
            }
        }
    }
    return 0;
}