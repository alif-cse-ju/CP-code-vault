#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int a[M],dp[M],l[M],r[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,ln,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>v;
        for(i=1;i<=n;i++)l[i]=0;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            v.emplace_back(a[i]);
            r[a[i]]=i,l[a[i]]=(!l[a[i]] ? i : l[a[i]]);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        ln=(int)v.size(),ans=INT_MAX;
        for(i=ln-1;i>=0;i--)
        {
            dp[i]=1;
            if(i < ln-1  &&  r[v[i]] < l[v[i+1]])dp[i]+=dp[i+1];
            ans=min(ans,ln-dp[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}