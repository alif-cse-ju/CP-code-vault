#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int pos[N];
long long cum[N];
pair<long long,int>a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,mid,m,n,r,t,cnt;
    long long x,y,ans,cur;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        map<long long,int>idx;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            cum[i]=cum[i-1]+x;
            if(idx.find(cum[i]) == idx.end())idx[cum[i]]=i;
        }
        cnt=0;
        for(auto it : idx)
        {
            ++cnt;
            a[cnt].first=it.first;
            a[cnt].second=it.second;
        }
        sort(a+1,a+cnt+1);
        pos[cnt]=a[cnt].second;
        for(i=cnt-1;i;i--)pos[i]=min(pos[i+1],a[i].second);
        while(m--)
        {
            cin >> x;
            auto it=lower_bound(a+1,a+cnt+1,make_pair(x,-1))-a;
            if(x > a[cnt].first)
            {
                if(cum[n] <= 0)cout << "-1 ";
                else
                {
                    l=1,r=1e9;
                    while(l <= r)
                    {
                        mid=(l+r) >> 1;
                        y=x-cum[n]*mid;
                        if(lower_bound(a+1,a+cnt+1,make_pair(y,-1))-a <= cnt)
                        {
                            cur=mid;
                            r=mid-1;
                        }
                        else l=mid+1;
                    }
                    ans=cur*n,x-=cum[n]*cur;
                    ans+=pos[lower_bound(a+1,a+cnt+1,make_pair(x,-1))-a];
                    cout << ans-1 << ' ';
                }
            }
            else cout << pos[(int)it]-1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
//