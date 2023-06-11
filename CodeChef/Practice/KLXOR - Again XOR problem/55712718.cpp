#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
char s[M];
int cnt[M],n;
void Update(int i,int v)
{
    while(i <= n)cnt[i] += v, i+=(i & -i);
}
int Query(int i)
{
    int ans=0;
    while(i)ans += cnt[i], i-=(i & -i);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,k,l,r,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s+1;
        for(i=1;i<=k;i++)cnt[i]=0;
        for(i=1;i<=n;i++)
        {
            if(s[i] == '0')continue;
            l=max(1,k+i-n), r=min(i,k);
            if(l <= r)Update(l,1), Update(r+1,-1);
        }
        ans=0;
        for(i=1;i<=k;i++)ans += (Query(i) & 1);
        cout << ans << '\n';
    }
    return 0;
}