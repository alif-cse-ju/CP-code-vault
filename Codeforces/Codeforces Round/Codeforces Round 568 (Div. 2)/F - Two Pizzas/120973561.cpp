#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int people[515];
vector<pair<int,int>>ans,cost[515];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c,i,j,k,m,n,x,y;
    cin >> n >> m;
    while(n--)
    {
        cin >> c;
        y=0;
        while(c--)cin >> x,--x,y |= (1 << x);
        ++people[y];
    }
    for(i=1;i<=m;i++)
    {
        cin >> c >> n;
        y=0;
        while(n--)cin >> x,--x,y |= (1 << x);
        cost[y].emplace_back(c,i);
    }
    for(i=1;i<512;i++)
    {
        sort(cost[i].begin(),cost[i].end());
        while((int)cost[i].size() > 2)cost[i].pop_back();
    }
    m=n=-1;
    for(i=1;i<512;i++)
    {
        if(cost[i].empty())continue;
        for(j=i;j<512;j++)
        {
            if(cost[j].empty())continue;
            if(i == j)
            {
                if((int)cost[i].size() < 2)continue;
                x=i,y=0;
                for(k=1;k<512;k++)
                {
                    if((k & x) == k)y+=people[k];
                }
                if(y > n)n=y,ans=cost[i],m=cost[i][0].first+cost[i][1].first;
                else if(y == n  &&  m > cost[i][0].first+cost[i][1].first)ans=cost[i],m=cost[i][0].first+cost[i][1].first;
            }
            else
            {
                x=i | j,y=0;
                for(k=1;k<512;k++)
                {
                    if((k & x) == k)y+=people[k];
                }
                if(y > n)n=y,ans={cost[i][0],cost[j][0]},m=cost[i][0].first+cost[j][0].first;
                else if(y == n  &&  m > cost[i][0].first+cost[j][0].first)ans={cost[i][0],cost[j][0]},m=cost[i][0].first+cost[j][0].first;
            }
        }
    }
    cout << ans[0].second << ' ' << ans[1].second;
    return 0;
}