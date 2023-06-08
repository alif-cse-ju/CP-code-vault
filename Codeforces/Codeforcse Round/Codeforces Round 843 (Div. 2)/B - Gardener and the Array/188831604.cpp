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
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
 int freq[M];
 void Solve()
{
    int n;cin >> n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++)
    {
        int k;cin >> k;
        vector<int>tmp;
        while(k--)
        {
            int x;cin >> x;
            ++freq[x], tmp.emplace_back(x);
        }
        v.emplace_back(tmp);
    }
    bool ok=0;
    for(int i=0;i<n;i++)
    {
        bool ok2=1;
        for(int &x : v[i])
        {
            --freq[x];
            if(!freq[x])ok2=0;
        }
        for(int &x : v[i])++freq[x];
        if(ok2)ok=1;
    }
    if(ok)cout << "YES\n";
    else cout << "NO\n";
    for(int i=0;i<n;i++)
    {
        for(int &x : v[i])--freq[x];
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)Solve();
    return 0;
}