#pragma GCC optimize("Ofast")
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
const int mx = 1e3;
vector<int>v;
int a[mx+mx+5],l;
ll dp[mx+5][mx+5];
ll DP(int id,int need)
{
    if(id == l)return (need == 0);
    ll &ans=dp[id][need];
    if(ans > -1)return ans;
    ans=0;
    for(int i=0;i<=min(need,v[id]);i++)
    {
        ans += DP(id+1,need-i);
        if(ans >= mod)ans -= mod;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,mnSum,mxSum,n,need,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        mnSum=mxSum=0;
        for(i=1;i<=n+n;i++)
        {
            cin >> a[i];
            if(a[i] & 1)mnSum += a[i];
            else mxSum += a[i];
        }
        if(k < mnSum  ||  k > mxSum)cout << "0\n";
        else
        {
            need=k-mnSum;
            sort(a+1,a+n+n+1);
            v.clear();
            for(i=1;i<=n+n;i++)
            {
                if(a[i] & 1)
                {
                    if(a[i] != a[i-1])x=1;
                    else ++x;
                }
                else if(x)v.emplace_back(x), x=0;
            }
            l=(int)v.size();
            for(i=0;i<l;i++)
            {
                for(j=need;j>=0;j--)dp[i][j]=-1;
            }
            cout << DP(0,need) << '\n';
        }
    }
    return 0;
}