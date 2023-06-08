#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
bool ok;
int clr[M],cnt0,cnt1;
vector<pair<int,int>>adj[M],revAdj[M];
void DFS(int x)
    if(!ok)return;
    for(auto [y,z] : adj[x])
    {
        if(clr[y] == -1)
        {
            if(clr[x])
            {
                if(z)++cnt1,clr[y]=1;
                else ++cnt0,clr[y]=0;
            }
            else
            {
                if(!z)++cnt1,clr[y]=1;
                else ++cnt0,clr[y]=0;
            }
            DFS(y);
        }
        else
        {
            if(clr[x])
            {
                if(z  &&  !clr[y])ok=0;
                else if(!z  &&  clr[y])ok=0;
            }
            else
            {
                if(z  &&  clr[y])ok=0;
                else if(!z  &&  !clr[y])ok=0;
            }
        }
    }
    for(auto [y,z] : revAdj[x])
    {
        if(clr[y] == -1)
        {
            if(clr[x])
            {
                if(z)++cnt1,clr[y]=1;
                else ++cnt0,clr[y]=0;
            }
            else
            {
                if(!z)++cnt1,clr[y]=1;
                else ++cnt0,clr[y]=0;
            }
            DFS(y);
        }
        else
        {
            if(clr[x])
            {
                if(z  &&  !clr[y])ok=0;
                else if(!z  &&  clr[y])ok=0;
            }
            else
            {
                if(z  &&  clr[y])ok=0;
                else if(!z  &&  !clr[y])ok=0;
            }
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int ans,i,m,n,t,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            clr[i]=-1;
            adj[i].clear();
            revAdj[i].clear();
        }
        while(m--)
        {
            cin >> x >> y >> s;
            if(s == "imposter")z=0;
            else z=1;
            adj[x].emplace_back(y,z);
            revAdj[y].emplace_back(x,z);
        }
        ans=ok=1;
        for(i=1;i<=n  &&  ok;i++)
        {
            if(clr[i] == -1)
            {
                clr[i]=0;
                cnt0=1,cnt1=0;
                DFS(i);
                ans+=max(cnt0,cnt1);
            }
        }
        if(!ok)cout << "-1\n";
        else cout << ans-1 << '\n';
    }
    return 0;
}