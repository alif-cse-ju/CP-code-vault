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
const int N=1e6+5;
const int mod=998244353;

bool selfLoop[M],visited[M];
int a[M],b[M],cntE[M],p[M],sz[M];

int FindParent(int x)
{
    if(p[x] == x)return x;
    return p[x]=FindParent(p[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i];
        for(int i=1;i<=n;i++)cin >> b[i];
        for(int i=1;i<=n;i++)cntE[i]=0, p[i]=i, selfLoop[i]=0, sz[i]=1, visited[i]=0;
        for(int i=1;i<=n;i++)
        {
            int pa=FindParent(a[i]), pb=FindParent(b[i]);
            if(pa == pb)++cntE[pa], selfLoop[pa] |= (a[i] == b[i]);
            else
            {
                if(sz[pa] >= sz[pb])cntE[pa]+=cntE[pb]+1, p[pb]=pa, selfLoop[pa]|=selfLoop[pb], sz[pa]+=sz[pb];
                else cntE[pb]+=cntE[pa]+1, p[pa]=pb, selfLoop[pb]|=selfLoop[pa], sz[pb]+=sz[pa];
            }
        }
        ll ans=1;
        for(int i=1;i<=n;i++)
        {
            int pi=FindParent(i);
            if(visited[pi])continue;
            visited[pi]=1;
            if(cntE[pi] != sz[pi])ans=0;
            else if(selfLoop[pi])ans=(ans*n)%mod;
            else ans=(ans*2)%mod;
        }
        cout << ans << '\n';
    }
    return 0;
}
