#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;
int a[M],divs[12],divCnt[12],cnt[M][12],sum[M][12];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans,j,k;
    int i,l,m,n,r,divk;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    if(k == 1)
    {
        cout << (1ll*n*(n+1))/2;
        return 0;
    }
    divk = 0;
    if(k%2 == 0)
    {
        divs[++divk]=2;
        while(k%2 == 0)k/=2, ++divCnt[1];
    }
    for(j=3;j*j<=k;j++)
    {
        if(k%j == 0)
        {
            divs[++divk]=j;
            while(k%j == 0)k/=j, ++divCnt[divk];
        }
    }
    if(k > 1)divs[++divk]=k, divCnt[divk]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=divk;j++)
        {
            while(a[i]%divs[j] == 0)a[i]/=divs[j], ++cnt[i][j];
            sum[i][j]=sum[i-1][j]+cnt[i][j];
        }
    }
    ans=0;
    for(i=0;i<n;i++)
    {
        vector<int>v;
        for(j=1;j<=divk;j++)
        {
            l=i+1,r=n;
            while(l <= r)
            {
                m=(l+r) >> 1;
                if(sum[m][j] >= sum[i][j]+divCnt[j])r=m-1;
                else l=m+1;
            }
            v.emplace_back(r+1);
        }
        sort(v.begin(),v.end());
        ans += n-v.back()+1;
    }
    cout << ans;
    return 0;
}