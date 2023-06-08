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
const int N=5e6+5;
const int mod=1e9+7;
ll dp[30][2];
vector<int>idx[N];
int nodeNum,_tree[N][2];
void Add(const int& x,const int& id)
    int bit,cur=0;
    for(int i=29;i>=0;i--)
    {
        bit=((x >> i) & 1);
        if(!_tree[cur][bit])_tree[cur][bit]=++nodeNum;
        cur=_tree[cur][bit], idx[cur].emplace_back(id);
    }
void DP(int id,int b)
    int l=_tree[id][0], r=_tree[id][1];
    if(l)DP(l,b-1);
    if(r)DP(r,b-1);
    if(!l  ||  !r)return;
    int i=0;
    ll inv=0;
    for(int x : idx[l])
    {
        while(i < (int)idx[r].size()  &&  idx[r][i] < x)++i;
        inv += i;
    }
    dp[b][0] += inv, dp[b][1] += 1ll*(int)idx[l].size()*(int)idx[r].size()-inv;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0;
    int i,n,x;
    cin >> n;
    for(i=1;i<=n;i++)cin >> x, Add(x,i);
    DP(0,29);
    x=0;
    for(i=29;i>=0;i--)
    {
        ans += min(dp[i][0], dp[i][1]);
        if(dp[i][1] < dp[i][0])x |= (1 << i);
    }
    cout << ans << ' ' << x;
    return 0;
}