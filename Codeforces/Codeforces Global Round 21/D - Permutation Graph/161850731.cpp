#pragma GCC optimize("Ofast")
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
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[M],id[M],maxNode[4*M],minNode[4*M],n;
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        maxNode[nodeNum]=minNode[nodeNum]=a[l];
        return;
    }
    int m=(l+r) >> 1;
    Build(2*nodeNum,l,m), Build(2*nodeNum+1,m+1,r);
    maxNode[nodeNum]=max(maxNode[2*nodeNum], maxNode[2*nodeNum+1]);
    minNode[nodeNum]=min(minNode[2*nodeNum], minNode[2*nodeNum+1]);
int Query(int nodeNum,int start,int end,int l,int r,bool _max)
{
    if(start >= l  &&  end <= r)
    {
        if(_max)return maxNode[nodeNum];
        return minNode[nodeNum];
    }
    int m=(start+end) >> 1;
    if(r <= m)return Query(2*nodeNum,start,m,l,r,_max);
    else if(l > m)return Query(2*nodeNum+1,m+1,end,l,r,_max);
    if(_max)return max(Query(2*nodeNum,start,m,l,r,_max), Query(2*nodeNum+1,m+1,end,l,r,_max));
    return min(Query(2*nodeNum,start,m,l,r,_max), Query(2*nodeNum+1,m+1,end,l,r,_max));
}
 int Solve(int l,int r,bool _max)
{
    if(l == r)return 0;
    int mx=Query(1,1,n,l,r,1), mn=Query(1,1,n,l,r,0);
    if((a[l] == mn  &&  a[r] == mx)  ||  (a[l] == mx  &&  a[r] == mn))return 1;
    if(_max)return Solve(l,id[mx],0) + Solve(id[mx],r,0);
    return Solve(l,id[mn],1) + Solve(id[mn],r,1);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i], id[a[i]]=i;
        Build(1,1,n);
        cout << Solve(1,n,1) << '\n';
    }
    return 0;
}