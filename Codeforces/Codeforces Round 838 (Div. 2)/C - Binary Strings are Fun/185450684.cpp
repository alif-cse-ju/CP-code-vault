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

const int M=4e5+5;
const int N=2e6+5;
const int mod=998244353;

ll pw[M];
char a[M],b[M];

void PreCal()
{
    pw[0]=1;
    for(int i=1; i<M; i++)pw[i]=(pw[i-1]*2)%mod;
}

ll Solve()
{
    int l;
    cin >> l >> a+1;
    ll ans=0;
    int _1=0, _0=0, ache=0;
    for(int i=1; i<=l; i++)
    {
        if(a[i] == '1')
        {
            ++_1;
            if(_1 < i)
            {
                if(ache < i-_1)return ans;
                ache -= i-_1, _1=i;
            }
        }
        else
        {
            ++_0;
            if(_0 < i)
            {
                if(ache < i-_0)return ans;
                ache -= i-_0, _0=i;
            }
        }
        ans += pw[ache];
        if(ans >= mod)ans -= mod;
        ++ache;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int t;
    cin >> t;
    while(t--)cout << Solve() << '\n';
    return 0;
}
