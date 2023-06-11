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
int lvl[M];
vector<int>adj[M];
priority_queue<int>pq;
void DFS1(int x,int p)
{
    lvl[x]=lvl[p]+1;
    for(int y : adj[x])
    {
        if(p ^ y)DFS1(y,x);
    }
}
int DFS2(int x,int p)
{
    vector<int>v;
    for(int y : adj[x])
    {
        if(p ^ y)v.emplace_back(DFS2(y,x));
    }
    if((int)adj[x].size() == 1  &&  x != p)return 1;
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    while((int)v.size() > 1)
    {
        pq.emplace(v.back());
        v.pop_back();
    }
    return v.back()+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n,t,x,y,ans,cur;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)
        {
            lvl[i]=-1;
            adj[i].clear();
        }
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        ans=1;
        if(k > 1)
        {
            DFS1(1,1);
            x=1;
            for(i=2;i<=n;i++)
            {
                if(lvl[i] > lvl[x])x=i;
            }
            while(!pq.empty())pq.pop();
            pq.emplace(DFS2(x,x));
            cur=0;
            while(cur < k)
            {
                ++ans;
                cur+=pq.top();
                pq.pop();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}