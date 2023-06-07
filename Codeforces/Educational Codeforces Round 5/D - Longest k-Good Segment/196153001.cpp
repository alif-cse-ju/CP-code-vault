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

const int M=5e5+5;
const int N=1e6+5;
const int mod=1e9+7;

int a[M], cnt[N];

bool Check(const int& m,const int& n,const int& k)
{
    int dist=0;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=m;i++)
    {
        ++cnt[a[i]];
        if(cnt[a[i]] == 1)++dist;
    }
    if(dist <= k)return 1;
    for(int i=m+1;i<=n;i++)
    {
        ++cnt[a[i]];
        if(cnt[a[i]] == 1)++dist;
        --cnt[a[i-m]];
        if(!cnt[a[i-m]])--dist;
        if(dist <= k)return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n;cin >> n >> k;
    for(int i=1;i<=n;i++)cin >> a[i];
    int l=1, r=n;
    while(l <= r)
    {
        int m=(l+r) >> 1;
        if(Check(m,n,k))l=m+1;
        else r=m-1;
    }
    int ln=l-1;
    memset(cnt,0,sizeof(cnt));
    int dist=0;
    for(int i=1;i<=ln;i++)
    {
        ++cnt[a[i]];
        if(cnt[a[i]] == 1)++dist;
    }
    if(dist <= k)
    {
        cout << "1 " << ln;
        return 0;
    }
    for(int i=ln+1;i<=n;i++)
    {
        ++cnt[a[i]];
        if(cnt[a[i]] == 1)++dist;
        --cnt[a[i-ln]];
        if(!cnt[a[i-ln]])--dist;
        if(dist <= k)
        {
            cout << i-ln+1 << ' ' << i;
            return 0;
        }
    }
    return 0;
}
