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

const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;

const int mx = 5e3+5;

int a[mx],dp[mx],L[mx],R[mx],visited[mx];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(!L[a[i]])L[a[i]]=i;
        R[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if(R[a[i]] != i)continue;
        bool ok=1;
        int l=L[a[i]],ans=a[i];
        visited[a[i]]=i;
        for(int j=i-1;j>=l  &&  ok;j--)
        {
            if(visited[a[j]] == i)continue;
            if(R[a[j]] > i)ok=0;
            ans^=a[j], l=min(l,L[a[j]]), visited[a[j]]=i;
        }
        if(ok)dp[i]=max(dp[i], dp[l-1]+ans);
    }
    cout << dp[n];
    return 0;
}