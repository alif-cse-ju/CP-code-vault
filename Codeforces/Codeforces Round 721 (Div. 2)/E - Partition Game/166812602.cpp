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

const int sz = 35002;

deque<int>pos[sz];
int a[sz],dp[sz][2],l,r,totalCost;

void Compute(int grpNo,int L,int R,int optL,int optR)
{
    if(L > R)return;
    int m=(L+R) >> 1;
    int &mn=dp[m][grpNo],opt;
    mn=INT_MAX;
    for(int i=optL;i<=min(m,optR);i++)
    {
        while(l > i)
        {
            --l;
            if(!pos[a[l]].empty())totalCost -= pos[a[l]].back()-pos[a[l]][0];
            pos[a[l]].emplace_front(l);
            totalCost += pos[a[l]].back()-pos[a[l]][0];
        }
        while(r < m)
        {
            ++r;
            if(!pos[a[r]].empty())totalCost -= pos[a[r]].back()-pos[a[r]][0];
            pos[a[r]].emplace_back(r);
            totalCost += pos[a[r]].back()-pos[a[r]][0];
        }
        while(l < i)
        {
            totalCost -= pos[a[l]].back()-pos[a[l]][0];
            pos[a[l]].pop_front();
            if(!pos[a[l]].empty())totalCost += pos[a[l]].back()-pos[a[l]][0];
            ++l;
        }
        while(r > m)
        {
            totalCost -= pos[a[r]].back()-pos[a[r]][0];
            pos[a[r]].pop_back();
            if(!pos[a[r]].empty())totalCost += pos[a[r]].back()-pos[a[r]][0];
            --r;
        }
        int tmp=dp[i-1][1-grpNo]+totalCost;
        if(tmp < mn)mn=tmp, opt=i;
    }
    Compute(grpNo,L,m-1,optL,opt), Compute(grpNo,m+1,R,opt,optR);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n;cin >> n >> k;
    for(int i=1;i<=n;i++)cin >> a[i];
    l=1, r=0;
    for(int i=1;i<=n;i++)dp[i][0]=1e9;
    for(int i=1;i<=k;i++)Compute(i%2,1,n,1,n);
    cout << dp[n][k%2];
    return 0;
}