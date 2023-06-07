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
int l,sum[N];
char grid[1002][1002];
void Update(int i,int v)
    while(i <= l)sum[i] += v, i += (i & -i);
int Query(int i)
    int ans=0;
    while(i)ans += sum[i], i -= (i & -i);
    return ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,q;cin >> n >> m >> q;
    for(int i=1;i<=n;i++)cin >> grid[i]+1;
    int cnt=0; l=m*n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(grid[i][j] == '*')++cnt, Update((j-1)*n + i, 1);
        }
    }
    while(q--)
    {
        int i,j;cin >> i >> j;
        if(grid[i][j] == '*')grid[i][j]='.', --cnt, Update((j-1)*n + i, -1);
        else grid[i][j]='*', ++cnt, Update((j-1)*n + i, 1);
         cout << cnt-Query(cnt) << '\n';
    }
    return 0;
}