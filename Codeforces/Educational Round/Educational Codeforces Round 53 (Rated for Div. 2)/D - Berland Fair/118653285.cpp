#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
long long a[N],b[N],c[N],d[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n,x;
    map<int,int>mp;
    long long ans=0,T;
    cin >> n >> T;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        ++mp[a[i]];
    }
    m=0;
    for(auto [x,y] : mp)b[++m]=x,c[m]=y,d[m]=b[m]*c[m];
    for(i=2;i<=m;i++)c[i]+=c[i-1],d[i]+=d[i-1];
    for(i=m;i;i--)
    {
        if(d[i] <= T)ans+=(T/d[i])*c[i],T%=d[i];
        if(b[i] <= T)
        {
            for(j=1;j<=n  &&  T >= b[1];j++)
            {
                if(a[j] <= T)++ans,T-=a[j];
            }
        }
    }
    cout << ans;
    return 0;
}