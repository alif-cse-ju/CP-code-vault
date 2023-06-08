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
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
const int sz = 1e5+5;
ll dp[sz][2],curCost;
int a[sz],cnt[sz],l=1,r;
void Add(int x)
    x=a[x], curCost+=cnt[x], ++cnt[x];
void Reduce(int x)
    x=a[x], --cnt[x], curCost-=cnt[x];
 void Update(int L,int R)
{
    while(l > L)Add(--l);
    while(r < R)Add(++r);
    while(l < L)Reduce(l++);
    while(r > R)Reduce(r--);
}
 void Compute(int grpNo,int L,int R,int optL,int optR)
{
    if(L > R)return;
    int m=(L+R) >> 1,opt;
    ll &ans=dp[m][grpNo];
    ans=LLONG_MAX;
    for(int i=optL;i<=min(m,optR);i++)
    {
        Update(i,m);
        ll tmp=dp[i-1][grpNo^1]+curCost;
        if(tmp < ans)ans=tmp, opt=i;
    }
    Compute(grpNo,L,m-1,optL,opt), Compute(grpNo,m+1,R,opt,optR);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n;cin >> n >> k;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++)dp[i][0]=1e12;
    for(int i=1;i<=k;i++)Compute(i%2,1,n,1,n);
    cout << dp[n][k%2];
    return 0;
}