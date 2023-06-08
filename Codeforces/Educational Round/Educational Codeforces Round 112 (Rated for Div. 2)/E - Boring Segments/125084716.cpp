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
const int M=3e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int cnt[4*N],_tree[4*N],lazy[4*N];
void Update(int nodeNum,int start,int end,int l,int r,int value)
    if(start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        cnt[nodeNum]+=value;
        if(cnt[nodeNum])_tree[nodeNum]=end-start+1;
        else _tree[nodeNum]=lazy[nodeNum];
        return;
    }
    int mid=(start+end)/2;
    Update(2*nodeNum,start,mid,l,r,value);
    Update(2*nodeNum+1,mid+1,end,l,r,value);
    lazy[nodeNum]=_tree[2*nodeNum]+_tree[2*nodeNum+1];
    if(cnt[nodeNum])_tree[nodeNum]=end-start+1;
    else _tree[nodeNum]=lazy[nodeNum];
}
 int Query(int nodeNum,int start,int end,int l,int r)
{
    if(start > end  ||  start > r  ||  end < l)return 0;
    if(start >= l  &&  end <= r)return _tree[nodeNum];
     int mid=(start+end)/2;
    int ans1=Query(nodeNum*2,start,mid,l,r);
    int ans2=Query(nodeNum*2 + 1,mid+1,end,l,r);
     return (ans1+ans2);
}
 tuple<int,int,int>a[M];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans=INT_MAX,i,l,m,n,r,w;
    cin >> n >> m;
    for(i=1; i<=n; i++)
    {
        cin >> l >> r >> w;
        a[i]=make_tuple(w,l,r);
    }
    --m;
    sort(a+1,a+n+1);
    for(l=1,r=0; l<=n; l++)
    {
        if(l > 1)
        {
            auto& [z,x,y]=a[l-1];
            Update(1,1,m,x,y-1,-1);
        }
        while(r < n  &&  Query(1,1,m,1,m) < m)
        {
            auto& [z,x,y]=a[++r];
            Update(1,1,m,x,y-1,1);
        }
        if(Query(1,1,m,1,m) == m)ans=min(ans,get<0>(a[r])-get<0>(a[l]));
        else break;
    }
    cout << ans;
    return 0;
}