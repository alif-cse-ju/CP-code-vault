/// Lower bound on BIT in O(logn)
/// https://codeforces.com/contest/992/problem/E
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
 int a[M];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i], a[i]+=a[i-1];
        int l=1, r=n;
        while(l < r)
        {
            int m=(l+r) >> 1;
            cout << "? " << m-l+1;
            for(int i=l;i<=m;i++)cout << ' ' << i;
            cout << endl;
            int s;cin >> s;
            if(s > a[m]-a[l-1])r=m;
            else l=m+1;
        }
        cout << "! " << r << endl;
    }
    return 0;
}