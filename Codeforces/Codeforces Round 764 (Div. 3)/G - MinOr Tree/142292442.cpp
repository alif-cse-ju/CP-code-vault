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
int par[M];
bool mark[M];
int FindParent(int p)
    if(par[p] == p)return p;
    return par[p]=FindParent(par[p]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,cnt,i,j,m,n,px,py,t,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<tuple<int,int,int>>v,vv;
        for(i=1;i<=m;i++)
        {
            cin >> x >> y >> z;
            v.emplace_back(make_tuple(x,y,z));
        }
        ans=0;
        for(i=30;i>=0;i--)
        {
            vv.clear();
            for(auto [x,y,z] : v)
            {
                if(!((z >> i) & 1))vv.emplace_back(make_tuple(x,y,z));
            }
            for(j=1;j<=n;j++)par[j]=j, mark[j]=0;
            for(auto [x,y,z] : vv)
            {
                px=FindParent(x), py=FindParent(y);
                if(px != py)par[py]=px;
            }
            cnt=0;
            for(j=1;j<=n  &&  cnt < 2;j++)
            {
                px=FindParent(j);
                if(!mark[px])mark[px]=1, ++cnt;
            }
            if(cnt < 2)v=vv;
            else ans |= (1 << i);
        }
        cout << ans << '\n';
    }
    return 0;
}