#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
const int sz = 5e3+5;
bool ok[sz],oklast[sz];
int a[sz],dp[sz],mxDP[sz];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        map<int,int>cnt;
        multiset<int>mst;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i], dp[i]=0, mxDP[i]=-1;
             if(cnt.find(a[i]) != cnt.end())mst.erase(mst.find(cnt[a[i]]));
             if(mst.empty())ok[i]=1;
            else
            {
                if(!(i & 1))ok[i]=0;
                else
                {
                    int mx=*(--mst.end());
                    if(mx <= (i-1)/2)ok[i]=1;
                    else ok[i]=0;
                }
            }
             if(cnt.find(a[i]) != cnt.end())mst.insert(cnt[a[i]]);
             if(cnt.find(a[i]) != cnt.end())mst.erase(mst.find(cnt[a[i]]));
            ++cnt[a[i]], mst.insert(cnt[a[i]]);
        }
         cnt.clear(), mst.clear();
        for(int i=n;i;i--)
        {
            if(cnt.find(a[i]) != cnt.end())mst.erase(mst.find(cnt[a[i]]));
             if(mst.empty())oklast[i]=1;
            else
            {
                int j=n-i;
                if(j & 1)oklast[i]=0;
                else
                {
                    int mx=*(--mst.end());
                    if(mx <= j/2)oklast[i]=1;
                    else oklast[i]=0;
                }
            }
             if(cnt.find(a[i]) != cnt.end())mst.insert(cnt[a[i]]);
             if(cnt.find(a[i]) != cnt.end())mst.erase(mst.find(cnt[a[i]]));
            ++cnt[a[i]], mst.insert(cnt[a[i]]);
        }
         for(int i=n;i;i--)
        {
            if(oklast[i])dp[i]=1;
            if(i < n  &&  a[i] == a[i+1]  &&  oklast[i+1])dp[i]=dp[i+1]+1, oklast[i]=1;
             int mx=0, arektaCnt[n+1]={0};
            for(int j=i+1;j<=n;j++)
            {
                if(a[i] == a[j]  &&  (j-i)%2  &&  mx <= (j-i)/2  &&  oklast[j])dp[i]=max(dp[i], dp[j]+1), oklast[i]=1;
                else ++arektaCnt[a[j]], mx=max(mx, arektaCnt[a[j]]);
            }
        }
         int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(ok[i])ans=max(ans, dp[i]);
        }
         cout << ans << '\n';
    }
    return 0;
}