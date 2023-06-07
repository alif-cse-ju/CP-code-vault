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
 ll a[M],sum[M];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n,q;cin >> n >> q;
        vector<int>v;
        ordered_set<int>ost;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i], sum[i]=sum[i-1]+a[i];
            if(ost.empty()  ||  a[i] > *(--ost.end()))ost.insert(a[i]), v.emplace_back(i);
        }
        ost.insert(INT_MAX), v.emplace_back(n+1);
        while(q--)
        {
            int x;cin >> x;
            int l=ost.order_of_key(x+1);
            cout << sum[v[l]-1] << ' ';
        }
        cout << '\n';
    }
    return 0;
}