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
const int mod=1e9+7;
int a[M],m;
ll ans[M],pre[M][20],suf[M][20];
void FindAns(int start,int end,vector<tuple<int,int,int>>&queries)
    if(start == end)
    {
        for(auto [l,r,i] : queries)ans[i]=!a[start] + 1;
        return;
    }
    int mid=(start+end) >> 1;
    vector<tuple<int,int,int>>lQuery,rQuery,computeHere;
    for(auto [l,r,i] : queries)
    {
        if(r <= mid)lQuery.emplace_back(make_tuple(l,r,i));
        else if(l > mid)rQuery.emplace_back(make_tuple(l,r,i));
        else computeHere.emplace_back(make_tuple(l,r,i));
    }
    if(!lQuery.empty())FindAns(start,mid,lQuery);
    if(!rQuery.empty())FindAns(mid+1,end,rQuery);
    if(!computeHere.empty())
    {
        int i,j;
        suf[mid+1][0]=pre[mid][0]=1;
        for(i=1;i<m;i++)suf[mid+1][i]=pre[mid][i]=0;
         for(i=mid;i>=start;i--)
        {
            for(j=0;j<m;j++)
            {
                suf[i][j] = suf[i+1][j] + suf[i+1][(j+m-a[i])%m];
                if(suf[i][j] >= mod)suf[i][j] -= mod;
            }
        }
         for(i=mid+1;i<=end;i++)
        {
            for(j=0;j<m;j++)
            {
                pre[i][j] = pre[i-1][j] + pre[i-1][(j+m-a[i])%m];
                if(pre[i][j] >= mod)pre[i][j] -= mod;
            }
        }
         for(auto [l,r,id] : computeHere)
        {
            ans[id]=(suf[l][0]*pre[r][0])%mod;
            for(i=1;i<m;i++)ans[id]=(ans[id] + suf[l][i]*pre[r][m-i])%mod;
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,n,q,r;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i], a[i]%=m;
    cin >> q;
    vector<tuple<int,int,int>>queries;
    for(i=1;i<=q;i++)cin >> l >> r, queries.emplace_back(make_tuple(l,r,i));
    FindAns(1,n,queries);
    for(i=1;i<=q;i++)cout << ans[i] << '\n';
    return 0;
}