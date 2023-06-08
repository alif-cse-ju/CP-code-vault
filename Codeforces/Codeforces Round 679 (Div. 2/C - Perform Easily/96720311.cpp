#include<bits/stdc++.h>
 using namespace std;
 const int N=1e5+5;
long long a[7],mark[N];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,l,n,r,cnt=0;
    long long x,ans=LLONG_MAX;
    for(i=1;i<7;i++)cin >> a[i];
    cin >> n;
    vector<pair<long long,int>>v;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        for(j=1;j<7;j++)v.emplace_back(x-a[j],i);
    }
    sort(v.begin(),v.end());
    l=r=0,j=v.size();
    while(r < j)
    {
        if(!mark[v[r].second])++cnt;
        ++mark[v[r].second];
        if(cnt == n)
        {
            while(l <= r  &&  mark[v[l].second] > 1)--mark[v[l++].second];
            ans=min(ans,v[r].first-v[l].first);
            --mark[v[l++].second],--cnt;
        }
        r++;
    }
    cout << ans;
    return 0;
}