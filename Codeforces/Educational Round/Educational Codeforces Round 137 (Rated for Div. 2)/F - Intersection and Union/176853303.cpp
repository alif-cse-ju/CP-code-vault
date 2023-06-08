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
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=1e6+5;
const int mod=998244353;
 int lastIdx[M];
ll pw2[M],pw3[M];
vector<int>in[M],out[M];
 void PreCal()
{
    pw2[0]=pw3[0]=1;
    for(int i=1;i<M;i++) pw2[i]=(pw2[i-1]*2)%mod, pw3[i]=(pw3[i-1]*3)%mod;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int n;cin >> n;
    for(int i=1;i<=n;i++)
    {
        int l,r;cin >> l >> r;
        in[l].emplace_back(i), out[r].emplace_back(i);
    }
    set<int>st;
    for(int i=0;i<M;i++)
    {
        for(int it : in[i])st.insert(it);
        if(st.empty())continue;
        lastIdx[i]=*(--st.end());
        for(int it : out[i])st.erase(it);
    }
    ll ans=0;
    for(int i=0;i<M;i++)
    {
        if(!lastIdx[i])continue;
        int pore=n-lastIdx[i]+(lastIdx[i] > 1);
        int age=n-pore-1;
        ans += (pw2[pore] * pw3[age]) % mod;
        if(ans >= mod)ans -= mod;
    }
    cout << ans;
    return 0;
}