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
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
 int a[M],r[M],sp[20][M];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        ll ans=0;
        for(int i=1;i<=n;i++)cin >> a[i], sp[0][i]=a[i], ans+=(1ll*i*(i-1))/2;
        for(int i=1;i<=18;i++)
        {
            for(int j=1;j<=n;j++)sp[i][j]=max(sp[i-1][j], sp[i-1][j-(1 << (i-1))]);
        }
        vector<int>v;
        a[n+1]=0, v.emplace_back(n+1);
        for(int i=n;i;i--)
        {
            while(a[v.back()] > a[i])v.pop_back();
            r[i]=v.back(), v.emplace_back(i);
        }
        v.clear(), v.emplace_back(0);
        for(int i=1;i<=n;i++)
        {
            while(a[v.back()] > a[i])v.pop_back();
            int j=v.back(), k=j;
            v.emplace_back(i);
            for(int ii=18;ii>=0;ii--)
            {
                if(k >= (1 << ii)  &&  sp[ii][k] < a[i])k -= (1 << ii);
            }
            ans -= 1ll*(r[i]-i)*(j-k);
        }
        cout << ans << '\n';
    }
    return 0;
}