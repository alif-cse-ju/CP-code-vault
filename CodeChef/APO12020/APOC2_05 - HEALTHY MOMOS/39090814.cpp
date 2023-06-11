#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N],b[N],fr[N],rv[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n;
    long long C,ans=0;
    cin >> n >> C;
    for(i=1;i<=n;i++)cin >> a[i] >> b[i];
    for(i=1;i<=n;i++)fr[i]=fr[i-1]+b[i];
    for(i=1;i<=n;i++)fr[i]-=a[i];
    for(i=n;i>0;i--)rv[i]=rv[i+1]+b[i];
    for(i=n;i>0;i--)rv[i]-=(C-a[i]);
    multiset<long long>mst;
    for(i=1;i<=n;i++)mst.insert(rv[i]);
    for(i=1;i<=n;i++)
    {
        mst.erase(mst.find(rv[i]));
        ans=max(ans,fr[i]+max(0LL,(i == n ? 0 : *(--mst.end())-a[i])));
    }
    for(i=1;i<=n;i++)mst.insert(fr[i]);
    for(i=n;i>0;i--)
    {
        mst.erase(mst.find(fr[i]));
        ans=max(ans,rv[i]+max(0LL,(i == 1 ? 0 : *(--mst.end())-C+a[i])));
    }
    cout << ans;
    return 0;
}