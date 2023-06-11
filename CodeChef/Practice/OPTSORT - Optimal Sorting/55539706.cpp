#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[M],ID[M],mnID[4*M],mnNode[4*M],mxNode[4*M];
void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        mnID[nodeNum]=ID[l], mnNode[nodeNum]=mxNode[nodeNum]=a[l];
        return;
    }
    int m=(l+r) >> 1;
    Build(2*nodeNum,l,m), Build(2*nodeNum+1,m+1,r);
    mnID[nodeNum]=min(mnID[2*nodeNum], mnID[2*nodeNum+1]);
    mnNode[nodeNum]=min(mnNode[2*nodeNum], mnNode[2*nodeNum+1]);
    mxNode[nodeNum]=max(mxNode[2*nodeNum], mxNode[2*nodeNum+1]);
}
int QueryID(int nodeNum,int start,int end,int l,int r)
{
    if(start >= l  &&  end <= r)return mnID[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return QueryID(2*nodeNum,start,m,l,r);
    if(l > m)return QueryID(2*nodeNum+1,m+1,end,l,r);
    return min(QueryID(2*nodeNum,start,m,l,m), QueryID(2*nodeNum+1,m+1,end,m+1,r));
}
int QueryMN(int nodeNum,int start,int end,int l,int r)
{
    if(start >= l  &&  end <= r)return mnNode[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return QueryMN(2*nodeNum,start,m,l,r);
    if(l > m)return QueryMN(2*nodeNum+1,m+1,end,l,r);
    return min(QueryMN(2*nodeNum,start,m,l,m), QueryMN(2*nodeNum+1,m+1,end,m+1,r));
}
int QueryMX(int nodeNum,int start,int end,int l,int r)
{
    if(start >= l  &&  end <= r)return mxNode[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return QueryMX(2*nodeNum,start,m,l,r);
    if(l > m)return QueryMX(2*nodeNum+1,m+1,end,l,r);
    return max(QueryMX(2*nodeNum,start,m,l,m), QueryMX(2*nodeNum+1,m+1,end,m+1,r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,j,mn,n,t,val;
    cin >> t;
    while(t--)
    {
        cin >> n;
        map<int,int>startID;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            if(startID.find(a[i]) == startID.end())startID[a[i]]=i;
        }
        vector<pair<int,int>>v;
        for(auto [x,y] : startID)v.emplace_back(x,y);
        sort(v.begin(),v.end());
        mn=INT_MAX;
        while(!v.empty())mn=min(mn, v.back().second), startID[v.back().first]=mn, v.pop_back();
        for(i=1;i<=n;i++)ID[i]=startID[a[i]];
        Build(1,1,n);
        ans=0;
        for(i=n;i;i--)
        {
            j=i;
            while(true)
            {
                val=QueryID(1,1,n,i,j);
                if(val == i)break;
                i=val;
            }
            ans += QueryMX(1,1,n,i,j) - QueryMN(1,1,n,i,j);
        }
        cout << ans << '\n';
    }
    return 0;
}