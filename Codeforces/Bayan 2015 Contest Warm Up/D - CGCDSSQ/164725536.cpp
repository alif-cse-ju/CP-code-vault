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
const int mod=1e9+7;
int k,n,a[M],ans[M][20],lg[M];
void Build()
   int i,j;
   lg[1]=0;
   k=log2(n)+1;
   for(i=0;i<n;i++)ans[i][0]=a[i];
   for(i=2;i<=n;i++)lg[i]=lg[i/2]+1;
   for(j=1;j<=k;j++)
   {
       for(i=0;i+(1 << j)<=n;i++)ans[i][j]=__gcd(ans[i][j-1],ans[i+(1 << (j-1))][j-1]);
   }
int Query(int l,int r)
{
    int j=lg[r-l+1];
    return __gcd(ans[l][j],ans[r-(1 << j)+1][j]);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    Build();
    map<int,ll>cnt;
    for(int i=n-1;i>=0;i--)
    {
        ++cnt[a[i]];
        for(int j=i+1;j<n;)
        {
            int gcd=Query(i, j), l=j, r=n-1;
            while(l <= r)
            {
                int m=(l+r) >> 1;
                if(gcd == Query(i, m))l=m+1;
                else r=m-1;
            }
            cnt[gcd] += l-j, j=l;
        }
    }
    int q;cin >> q;
    while(q--)
    {
        int x;cin >> x;
        cout << cnt[x] << '\n';
    }
    return 0;
}