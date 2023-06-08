#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 1000005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    ordered_set;
int mn[N*4];
int lazy[N*4];
void update(int node,int l,int r,int b,int e,int x)
    if(r<b||e<l)
    {
        return;
    }
    if(b<=l&&r<=e)
    {
        mn[node]+=x;
        lazy[node]+=x;
        return;
    }
    update(node*2,l,(l+r)/2,b,e,x);
    update(node*2+1,(l+r)/2+1,r,b,e,x);
    mn[node]=min(mn[node*2],mn[node*2+1])+lazy[node];
    return;
int query(int node,int l,int r,int b,int e)
    if(r<b||e<l)
        return 1e9;
    if(b<=l&&r<=e)
    {
        return mn[node];
    }
    return min(query(node*2,l,(l+r)/2,b,e),
               query(node*2+1,(l+r)/2+1,r,b,e))+lazy[node];
}
 int n,m;
int a[N];
int b[N];
 void solve()
{
    cin>>n>>m;
    for(int i=0;i<n*4;i++)
        mn[i]=0,lazy[i]=0;
     vector<pair<int,int>>v;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v.push_back({a[i],i});
        update(1,0,n,i,n,+1);
    }
     sort(v.begin(),v.end());
    for(int i=1;i<=m;i++)
        cin>>b[i];
    sort(b+1,b+m+1);
     ordered_set st;
    ll ans=0;
    for(int i=n;i>=1;i--)
    {
        st.insert(a[i]);
        ans+=st.order_of_key(a[i]);
    }
     int p=0,q=0;
     for(int i=1;i<=m;i++)
    {
        while(p<n&&v[p].first<=b[i])
        {
            update(1,0,n,v[p].second,n,-1);
            p++;
        }
        while(q<n&&v[q].first<b[i])
        {
            update(1,0,n,v[q].second,n,-1);
            q++;
        }
        ans+=st.order_of_key(b[i])+mn[1];
    }
    cout<<ans<<'\n';
}
 main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}