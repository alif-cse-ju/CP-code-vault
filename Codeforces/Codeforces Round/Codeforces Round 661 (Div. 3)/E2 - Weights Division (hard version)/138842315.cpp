#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll tot;
vector<ll>v[3];
vector<tuple<int,int,int>>adj[M];
int DFS(int x,int p)
    int cnt=0,val;
    for(auto [y,w,c] : adj[x])
    {
        if(p ^ y)
        {
            val=DFS(y,x), cnt+=val, tot+=1ll*val*w;
            while(w)v[c].emplace_back(1ll*(w-w/2)*val), w/=2;
        }
    }
    return max(1,cnt);
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll s;
    int ans,c,i,l1,l2,n,t,w,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        v[1].clear(), v[2].clear();
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y >> w >> c;
            adj[x].emplace_back(y,w,c);
            adj[y].emplace_back(x,w,c);
        }
        tot=0, x=DFS(1,0);
        if(tot <= s)
        {
            cout << "0\n";
            continue;
        }
        s = tot-s;
        sort(v[1].begin(),v[1].end());
        reverse(v[1].begin(),v[1].end());
        sort(v[2].begin(),v[2].end());
        reverse(v[2].begin(),v[2].end());
        l1=(int)v[1].size(), l2=(int)v[2].size();
        for(i=1;i<l1;i++)v[1][i] += v[1][i-1];
        for(i=1;i<l2;i++)v[2][i] += v[2][i-1];
        ans=INT_MAX;
        auto it=lower_bound(v[2].begin(),v[2].end(),s);
        if(!v[2].empty()  &&  v[2].back() >= s)x=it-v[2].begin(), ans=min(ans, 2*(x+1));
        for(i=1;i<=l1;i++)
        {
            if(v[1][i-1] >= s)
            {
                ans=min(ans,i);
                break;
            }
            else
            {
                it=lower_bound(v[2].begin(),v[2].end(),s-v[1][i-1]);
                if(!v[2].empty()  &&  v[2].back() >= s-v[1][i-1])x=it-v[2].begin(), ans=min(ans,i+2*(x+1));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}