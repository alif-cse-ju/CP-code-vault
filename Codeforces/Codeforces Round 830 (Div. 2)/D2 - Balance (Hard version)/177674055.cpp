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
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
 const int magic = 320;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;cin >> q;
    set<ll>st;
    map<ll,ll>dp;
    vector<ll>baadDichi;
    st.insert(0);
    while(q--)
    {
        string s; ll k; cin >> s >> k;
        if(s[0] == '+')st.insert(k);
        else if(s[0] == '-')st.erase(k), baadDichi.emplace_back(k);
        else
        {
            while(st.find(dp[k]) != st.end())dp[k] += k;
            ll ans=dp[k];
            for(ll &it : baadDichi)
            {
                if(st.find(it) != st.end())continue;
                if(it%k == 0)ans=min(ans, it);
            }
            cout << ans << '\n';
        }
        if((int)baadDichi.size() == magic)dp.clear(), baadDichi.clear();
    }
    return 0;
}