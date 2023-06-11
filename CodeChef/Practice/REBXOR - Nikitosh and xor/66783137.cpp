#pragma GCC optimize("Ofast")
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
const int M=4e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[M],pre[M],suf[M],preTree[M*32][2],sufTree[M*32][2],preNodeCnt,sufNodeCnt,dpPre[M],dpSuf[M];
void InsertPre(int val)
{
    int cur=0;
    for(int i=30;i>=0;i--)
    {
        int b=((val >> i) & 1);
        if(!preTree[cur][b])preTree[cur][b]=++preNodeCnt;
        cur=preTree[cur][b];
    }
}
void InsertSuf(int val)
{
    int cur=0;
    for(int i=30;i>=0;i--)
    {
        int b=((val >> i) & 1);
        if(!sufTree[cur][b])sufTree[cur][b]=++sufNodeCnt;
        cur=sufTree[cur][b];
    }
}
int QueryPre(int val)
{
    int ans=0,cur=0;
    for(int i=30;i>=0;i--)
    {
        int b=1-((val >> i) & 1);
        if(preTree[cur][b])ans+=(1 << i), cur=preTree[cur][b];
        else cur=preTree[cur][1-b];
    }
    return ans;
}
int QuerySuf(int val)
{
    int ans=0,cur=0;
    for(int i=30;i>=0;i--)
    {
        int b=1-((val >> i) & 1);
        if(sufTree[cur][b])ans+=(1 << i), cur=sufTree[cur][b];
        else cur=sufTree[cur][1-b];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    InsertPre(0), InsertSuf(0);
    for(int i=1;i<=n;i++)
    {
        pre[i]=(pre[i-1] ^ a[i]);
        dpPre[i]=QueryPre(pre[i]);
        InsertPre(pre[i]);
        dpPre[i]=max(dpPre[i], dpPre[i-1]);
    }
    for(int i=n;i;i--)
    {
        suf[i]=(suf[i+1] ^ a[i]);
        dpSuf[i]=QuerySuf(suf[i]);
        InsertSuf(suf[i]);
        dpSuf[i]=max(dpSuf[i], dpSuf[i+1]);
    }
    int ans=0;
    for(int i=1;i<n;i++)ans=max(ans, dpPre[i]+dpSuf[i+1]);
    cout << ans;
    return 0;
}