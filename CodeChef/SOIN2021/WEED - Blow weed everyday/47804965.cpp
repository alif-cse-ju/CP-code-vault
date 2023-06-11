#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,int>R,C;
    map<pair<int,int>,bool>mark;
    int k,m,mxC=INT_MIN,mxR=INT_MIN,n,x,y,ans;
    cin >> n >> m >> k;
    while(k--)
    {
        cin >> x >> y;
        ++R[x],++C[y],mark[{x,y}]=1;
    }
    for(auto [x,y] : R)mxR=max(mxR,y);
    for(auto [x,y] : C)mxC=max(mxC,y);
    ans=mxC+mxR;
    vector<int>c,r;
    for(auto [x,y] : C)
    {
        if(y == mxC)c.emplace_back(x);
    }
    for(auto [x,y] : R)
    {
        if(y == mxR)r.emplace_back(x);
    }
    for(int x : r)
    {
        for(int y : c)
        {
            if(mark.find({x,y}) == mark.end())
            {
                cout << ans;
                return 0;
            }
        }
    }
    cout << ans-1;
    return 0;
}