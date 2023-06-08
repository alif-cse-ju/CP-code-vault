#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
set<int>AtoB[N],BtoC[N],CtoD[N];
pair<long long,int>a[N],b[N],c[N],d[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n[5],x,y;
    long long ans=LLONG_MAX;
    for(i=1;i<5;i++)cin >> n[i];
    for(i=1;i<=n[1];i++)
    {
        cin >> a[i].first;
        a[i].second=i;
    }
    for(i=1;i<=n[2];i++)
    {
        cin >> b[i].first;
        b[i].second=i;
    }
    for(i=1;i<=n[3];i++)
    {
        cin >> c[i].first;
        c[i].second=i;
    }
    for(i=1;i<=n[4];i++)
    {
        cin >> d[i].first;
        d[i].second=i;
    }
    cin >> m;
    while(m--)
    {
        cin >> x >> y;
        AtoB[x].insert(y);
    }
    cin >> m;
    while(m--)
    {
        cin >> x >> y;
        BtoC[x].insert(y);
    }
    cin >> m;
    while(m--)
    {
        cin >> x >> y;
        CtoD[x].insert(y);
    }
    sort(d+1,d+n[4]+1);
    for(i=1;i<=n[3];i++)
    {
        for(j=1;j<=n[4];j++)
        {
            if(CtoD[c[i].second].find(d[j].second) == CtoD[c[i].second].end())
            {
                c[i].first+=d[j].first;
                break;
            }
        }
        if(j > n[4])c[i].first=1e10;
    }
    sort(c+1,c+n[3]+1);
    for(i=1;i<=n[2];i++)
    {
        for(j=1;j<=n[3];j++)
        {
            if(BtoC[b[i].second].find(c[j].second) == BtoC[b[i].second].end())
            {
                b[i].first+=c[j].first;
                break;
            }
        }
        if(j > n[3])b[i].first=1e10;
    }
    sort(b+1,b+n[2]+1);
    for(i=1;i<=n[1];i++)
    {
        for(j=1;j<=n[2];j++)
        {
            if(AtoB[a[i].second].find(b[j].second) == AtoB[a[i].second].end())
            {
                a[i].first+=b[j].first;
                ans=min(ans,a[i].first);
                break;
            }
        }
    }
    if(ans >= 1e10)cout << "-1";
    else cout << ans;
    return 0;
}
//