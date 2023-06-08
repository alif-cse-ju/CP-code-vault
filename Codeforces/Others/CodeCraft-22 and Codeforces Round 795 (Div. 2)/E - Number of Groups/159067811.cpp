#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
vector<int>in[M][2];
int c[M],l[M],par[M],r[M];
int FindParent(int n)
    if(par[n] == n)return n;
    return par[n]=FindParent(par[n]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        set<int>st;
        for(int i=1;i<=n;i++)cin >> c[i] >> l[i] >> r[i], st.insert(l[i]), st.insert(r[i]);
        map<int,int>mp;int cnt=0;
        for(int it : st)mp[it]=++cnt;
        for(int i=1;i<=n;i++)l[i]=mp[l[i]], r[i]=mp[r[i]];
        for(int i=1;i<=n;i++)par[i]=i;
        for(int i=1;i<=cnt;i++)in[i][0].clear(), in[i][1].clear();
        for(int i=1;i<=n;i++)in[l[i]][c[i]].emplace_back(i);
        int tag=n+1;
        int mx=-1;
        priority_queue<pair<int,int>>pq[2];
        for(int i=1;i<=cnt;i++)
        {
            for(int it : in[i][0])pq[0].emplace(-r[it],it);
            for(int it : in[i][1])pq[1].emplace(-r[it],it);
             if(!pq[0].empty()  &&  !pq[1].empty())
            {
                int mxR0=-1,mxR1=-1,id;
                while(!pq[0].empty())
                {
                    auto [r,ii]=pq[0].top();pq[0].pop();
                    par[ii]=tag;
                    if(-r > mxR0)mxR0=-r, id=ii;
                }
                pq[0].emplace(-mxR0,id);
                 while(!pq[1].empty())
                {
                    auto [r,ii]=pq[1].top();pq[1].pop();
                    par[ii]=tag;
                    if(-r > mxR1)mxR1=-r, id=ii;
                }
                pq[1].emplace(-mxR1,id);
                 mx=max(mx,max(mxR0,mxR1));
            }
             while(!pq[0].empty()  &&  -pq[0].top().first == i)pq[0].pop();
            while(!pq[1].empty()  &&  -pq[1].top().first == i)pq[1].pop();
             if(i == mx)++tag;
        }
        set<int>ans;
        for(int i=1;i<=n;i++)ans.insert(par[i]);
        cout << (int)ans.size() << '\n';
    }
    return 0;
}