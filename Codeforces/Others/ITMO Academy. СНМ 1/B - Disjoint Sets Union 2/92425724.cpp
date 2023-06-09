#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int mn[N],mx[N],par[N],sz[N];
int Get(int x)
    if(par[x] == x)return x;
    return par[x]=Get(par[x]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,m,n,x,y;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        sz[i]=1;
        par[i]=mn[i]=mx[i]=i;
    }
    while(m--)
    {
        cin >> s;
        if(s[0] == 'u')
        {
            cin >> x >> y;
            x=Get(x);
            y=Get(y);
            if(x == y)continue;
            if(sz[x] >= sz[y])
            {
                par[y]=x;
                sz[x]+=sz[y];
                mn[x]=min(mn[x],mn[y]);
                mx[x]=max(mx[x],mx[y]);
            }
            else
            {
                par[x]=y;
                sz[y]+=sz[x];
                mn[y]=min(mn[x],mn[y]);
                mx[y]=max(mx[x],mx[y]);
            }
        }
        else
        {
            cin >> x;
            x=Get(x);
            cout << mn[x] << ' ' << mx[x] << ' ' << sz[x] << '\n';
        }
    }
    return 0;
}