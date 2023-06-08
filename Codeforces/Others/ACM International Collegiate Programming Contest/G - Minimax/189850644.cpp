#pragma GCC optimize("Ofast")
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
 const int mx = 505;
 int a[mx][mx],m,n,PP[mx][mx],PS[mx][mx],SP[mx][mx],SS[mx][mx];
 /// Handling PP
void UpdatePP(int i,int j,int v)
{
    while(i <= n)
    {
        for(int jj=j;jj<=m;jj+=(jj & -jj))PP[i][jj]=max(PP[i][jj],v);
        i+=(i & -i);
    }
}
 int QueryPP(int i,int j)
{
    int ans=0;
    while(i)
    {
        for(int jj=j;jj;jj-=(jj & -jj))ans=max(ans, PP[i][jj]);
        i-=(i & -i);
    }
    return ans;
}
   /// Handling PS
void UpdatePS(int i,int j,int v)
{
    while(i <= n)
    {
        for(int jj=j;jj;jj-=(jj & -jj))PS[i][jj]=max(PS[i][jj],v);
        i+=(i & -i);
    }
}
 int QueryPS(int i,int j)
{
    int ans=0;
    while(i)
    {
        for(int jj=j;jj<=m;jj+=(jj & -jj))ans=max(ans, PS[i][jj]);
        i-=(i & -i);
    }
    return ans;
}
   /// Handling SP
void UpdateSP(int i,int j,int v)
{
    while(i)
    {
        for(int jj=j;jj<=m;jj+=(jj & -jj))SP[i][jj]=max(SP[i][jj],v);
        i-=(i & -i);
    }
}
 int QuerySP(int i,int j)
{
    int ans=0;
    while(i<=n)
    {
        for(int jj=j;jj;jj-=(jj & -jj))ans=max(ans, SP[i][jj]);
        i+=(i & -i);
    }
    return ans;
}
   /// Handling SS
void UpdateSS(int i,int j,int v)
{
    while(i)
    {
        for(int jj=j;jj;jj-=(jj & -jj))SS[i][jj]=max(SS[i][jj],v);
        i-=(i & -i);
    }
}
 int QuerySS(int i,int j)
{
    int ans=0;
    while(i<=n)
    {
        for(int jj=j;jj<=m;jj+=(jj & -jj))ans=max(ans, SS[i][jj]);
        i+=(i & -i);
    }
    return ans;
}
   int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> a[i][j];
                PP[i][j]=PS[i][j]=SP[i][j]=SS[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                UpdatePP(i,j,a[i][j]), UpdatePS(i,j,a[i][j]);
                UpdateSP(i,j,a[i][j]), UpdateSS(i,j,a[i][j]);
            }
        }
        int ans=INT_MAX;
        for(int i=2;i<n;i++)
        {
            for(int j=2;j<m;j++)
            {
                vector<int>v;
                v.emplace_back(QueryPP(i-1,j-1));
                v.emplace_back(QueryPS(i-1,j+1));
                v.emplace_back(QuerySP(i+1,j-1));
                v.emplace_back(QuerySS(i+1,j+1));
                sort(v.begin(),v.end());
                ans=min(ans, v.back()-v[0]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}