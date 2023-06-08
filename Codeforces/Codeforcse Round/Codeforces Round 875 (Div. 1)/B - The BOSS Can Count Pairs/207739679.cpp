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
 int a[M],b[M],cnt[635][M];
 ll Cal(int n)
{
    return (1ll*n*(n-1))/2;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int mx=n+n, rt=sqrt(mx);
        for(int i=1; i<=n; i++)cin >> a[i];
        for(int i=1; i<=rt; i++)
        {
            for(int j=1; j<=n; j++)cnt[i][j]=0;
        }
        for(int i=1; i<=n; i++)
        {
            cin >> b[i];
            if(a[i] <= rt)++cnt[a[i]][b[i]];
        }
        ll ans=0;
        for(int i=1; i<=n; i++)
        {
            if(a[i] <= rt)
            {
                if(a[i]*a[i]-b[i] >= 1  &&  a[i]*a[i]-b[i] <= n)ans += cnt[a[i]][a[i]*a[i]-b[i]];
            }
        }
        for(int i=2; i<=rt; i+=2)ans-=cnt[i][i*i/2];
        ans/=2;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=rt  &&  j<a[i]  &&  j*a[i]<=2*n; j++)
            {
                if(1ll*j*a[i]-b[i] >= 1  &&  j*a[i]-b[i] <= n) ans+=cnt[j][j*a[i]-b[i]];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
///