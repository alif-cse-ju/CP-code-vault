#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
bool mark[N];
vector<int>v[N];
long long Query(int x,int l,int r)
{
    auto lb=lower_bound(v[x].begin(),v[x].end(),l);
    auto rb=upper_bound(v[x].begin(),v[x].end(),r);
    return rb-lb;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,n,q,r,x;
    long long ans,cnt1,cnt2;
    cin >> n >> q;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        mark[x]=1;
        v[x].emplace_back(i);
    }
    while(q--)
    {
        cin >> l >> r >> x;
        ans=0;
        for(i=1;i<(x+1)/2;i++)
        {
            if(!mark[i]  ||  !mark[x-i])continue;
            cnt1=Query(i,l,r);
            cnt2=Query(x-i,l,r);
            ans+=cnt1*cnt2;
        }
        if(x%2 == 0)
        {
            if(!mark[x/2])continue;
            cnt1=Query(x/2,l,r);
            ans+=(cnt1*(cnt1-1))/2;
        }
        cout << ans << '\n';
    }
    return 0;
}