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

const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;

const int mx = 5000;

bitset<mx>parbe[mx];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> m >> n;
    vector<int>idx, p(n);
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
        idx.emplace_back(i);
        for(int j=0;j<n;j++)parbe[i].set(j);
    }
    while(m--)
    {
        vector<int>r(n);
        for(int &x : r)cin >> x;
        sort(idx.begin(), idx.end(), [&](int i,int j)
             {
                 return r[i] < r[j];
             });
        bitset<mx>ager;
        for(int i=0;i<n;)
        {
            int j=i;
            while(j < n  &&  r[idx[i]] == r[idx[j]])parbe[idx[j]] &= ager, ++j;
            while(i < j)ager.set(idx[i]), ++i;
        }
    }
    vector<ll>dp(n);
    for(int i=0;i<n;i++)dp[i]=p[i];
    for(int &i : idx)
    {
        for(int j=0;j<n;j++)
        {
            if(parbe[i].test(j))dp[i]=max(dp[i], p[i]+dp[j]);
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++)ans=max(ans, dp[i]);
    cout << ans;
    return 0;
}
