#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
int val[N];
ordered_set<int>ostTree[4*N];
void Build(int nodeNum,int start,int end)
{
    if(start == end)
    {
        ostTree[nodeNum].insert(val[start]);
        return;
    }
    int i,mid=(start+end) >> 1,lChild=mid << 1,rChild=lChild+1;
    for(i=start;i<=end;i++)ostTree[nodeNum].insert(val[i]);
    Build(lChild,start,mid);Build(rChild,mid+1,end);
}
int Query(int nodeNum,int start,int end,int l,int r,long long queryVal)
{
    if(start > r  ||  end < l)return 0;
    if(start >= l  &&  end <= r)return (int)ostTree[nodeNum].size()-ostTree[nodeNum].order_of_key(queryVal+1);
    int mid=(start+end) >> 1,lChild=mid << 1,rChild=lChild+1;
    return Query(lChild,start,mid,l,r,queryVal)+Query(rChild,mid+1,end,l,r,queryVal);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x;
    long long ans=0;
    priority_queue<pair<int,int>>pq;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> val[i];
        pq.emplace(-val[i],i);
    }
    Build(1,1,n);
    while(!pq.empty())
    {
        x=-pq.top().first;
        i=pq.top().second+1;
        pq.pop();
        ans+=Query(1,1,n,i,n,x);
    }
    cout << ans;
    return 0;
}
//1316