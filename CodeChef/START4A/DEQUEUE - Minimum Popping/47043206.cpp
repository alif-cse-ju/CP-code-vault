#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[N],pos[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,t,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)pos[i]=INT_MAX;
        for(i=1;i<=m;i++)
        {
            cin >> a[i];
            pos[a[i]]=min(i,pos[a[i]]);
        }
        set<int>vals,idx;
        for(i=1;i<=n;i++)
        {
            vals.insert(i);
            idx.insert(pos[i]);
        }
        idx.insert(0);
        ans=*(--idx.end());
        for(i=m;i;i--)
        {
            if(vals.find(a[i]) != vals.end())vals.erase(a[i]),idx.erase(pos[a[i]]);
            x=*(--idx.end());
            ans=min(ans,m+x+1-i);
        }
        cout << ans << '\n';
    }
    return 0;
}