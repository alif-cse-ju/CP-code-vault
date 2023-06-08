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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
vector<int>idx[M];
int a[M],b[M],dp[M],_tree[M];
void Update(int i,int v)
    ++i;
    while(i)
    {
        _tree[i]=max(v,_tree[i]);
        i -= (i & -i);
    }
int Query(int i)
    ++i;
    int ans=0;
    while(i < M)
    {
        ans=max(ans,_tree[i]);
        i += (i & -i);
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans=0,i,n;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        b[i]=i-a[i];
        idx[a[i]].emplace_back(i);
    }
    for(i=M-5;i;i--)
    {
        for(int j : idx[i])
        {
            if(b[j] < 0)continue;
            dp[j]=1+Query(b[j]);
            ans=max(ans,dp[j]);
        }
        for(int j : idx[i])
        {
            if(b[j] < 0)continue;
            Update(b[j],dp[j]);
        }
    }
    cout << ans;
    return 0;
}