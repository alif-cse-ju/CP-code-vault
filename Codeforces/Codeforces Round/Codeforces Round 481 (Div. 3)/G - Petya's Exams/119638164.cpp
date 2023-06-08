#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e2+5;
const int N=2e5+5;
const int mod=1e9+7;
int ans[M],c[M],d[M];
vector<pair<int,int>>s[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,x,y,z;
    cin >> n >> m;
    for(i=1;i<=m;i++)
    {
        cin >> x >> y >> z;
        c[i]=z,d[y]=i;
        s[x].emplace_back(i,y);
    }
    priority_queue<pair<int,int>>pq;
    for(i=1;i<=n;i++)
    {
        if(d[i])
        {
            if(c[d[i]])
            {
                cout << "-1";
                return 0;
            }
            ans[i]=m+1;
        }
        for(auto [ii,yy] : s[i])pq.emplace(-yy,ii);
        if(!d[i]  &&  !pq.empty())
        {
            auto [yy,ii]=pq.top();
            pq.pop();
            --c[ii],ans[i]=ii;
            if(c[ii])pq.emplace(yy,ii);
        }
    }
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}