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
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
struct Node
    int cnt,l,r;
    Node()
    {
        cnt=0, l=r=-1;
    }
    Node(int x,int y,int z)
    {
        l=x, r=y, cnt=z;
    }
node[40*M];
int nodeCnt,a[M],lastOccur[M],root[M];
int Build(int l,int r)
    ++nodeCnt;
    if(l == r)return nodeCnt;
    int cur=nodeCnt, mid=(l+r) >> 1;
    node[cur]=Node(Build(l,mid), Build(mid+1,r), 0);
    return cur;
}
 int Update(int nodeNum,int start,int end,int idx,int val)
{
    ++nodeCnt;
    if(start == end)
    {
        node[nodeCnt]=Node(-1,-1,node[nodeNum].cnt+val);
        return nodeCnt;
    }
    int cur=nodeCnt, mid=(start+end) >> 1;
    if(idx <= mid)node[cur]=Node(Update(node[nodeNum].l,start,mid,idx,val), node[nodeNum].r, node[nodeNum].cnt+val);
    else node[cur]=Node(node[nodeNum].l, Update(node[nodeNum].r,mid+1,end,idx,val), node[nodeNum].cnt+val);
    return cur;
}
 int Query(int nodeNum,int start,int end,int l,int r)
{
    if(r < start  ||  l > end)return 0;
    if(l <= start  &&  end <= r)return node[nodeNum].cnt;
    int mid=(start+end) >> 1;
    return Query(node[nodeNum].l,start,mid,l,r) + Query(node[nodeNum].r,mid+1,end,l,r);
}
 int QueryIdx(int nodeNum,int start,int end,int val)
{
    if(start == end)return start;
    int mid=(start+end) >> 1;
    if(node[node[nodeNum].l].cnt >= val)return QueryIdx(node[nodeNum].l,start,mid,val);
    return QueryIdx(node[nodeNum].r,mid+1,end,val-node[node[nodeNum].l].cnt);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    int ans,i,j,l,n,r;
    cin >> n;
    root[n+1]=Build(1,n);
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=n;i;i--)
    {
        r=root[i+1];
        if(lastOccur[a[i]])r=Update(r,1,n,lastOccur[a[i]],-1);
        root[i]=Update(r,1,n,i,1), lastOccur[a[i]]=i;
    }
    ok=0;
    for(i=1;i<=n;i++)
    {
        if(ok)
        {
            cout << "1 ";
            continue;
        }
        ans=0;
        for(j=1;j<=n;)
        {
            ++ans;
            if(Query(root[j],1,n,1,n) <= i)break;
            j=QueryIdx(root[j],1,n,i+1);
        }
        ok |= (ans == 1);
        cout << ans << ' ';
    }
    return 0;
}