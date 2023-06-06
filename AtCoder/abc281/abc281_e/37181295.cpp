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

ll a[M],pre[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,m,n;cin >> n >> m >> k;
    for(int i=1;i<=n;i++)cin >> a[i];
    if(k == m)
    {
        for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
        for(int i=m;i<=n;i++)cout << pre[i]-pre[i-m] << ' ';
    }
    else
    {
        ll sum=0;
        ordered_set<int>ost;
        for(int i=1;i<=m;i++)ost.insert(a[i]);
        for(int i=0;i<k;i++)sum += *ost.find_by_order(i);
        cout << sum << ' ';
        for(int i=m+1;i<=n;i++)
        {
            int it=ost.order_of_key(a[i-m]);
            ost.erase(ost.find_by_order(it));
            if(it < k)sum += *ost.find_by_order(k-1)-a[i-m];
            it=ost.order_of_key(a[i]);
            if(it < k)sum += a[i]-*ost.find_by_order(k-1);
            ost.insert(a[i]);
            cout << sum << ' ';
        }
    }
    return 0;
}
