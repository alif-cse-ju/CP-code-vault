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

const int M=3e5+5;
const int N=1e6+5;
const int mod=1e9+7;

int a[M];
bool ache[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    set<int>st;
    for(int i=1;i<=n;i++)cin >> a[i], st.insert(a[i]);
    if((int)st.size() == n)cout << "-1";
    else
    {
        map<int,int>mp;
        int dist=0;
        for(int it : st)mp[it]=++dist;
        for(int i=1;i<=n;i++)a[i]=mp[a[i]];
        vector<pair<int,int>>ans;
        for(int i=1;i<=n;i++)
        {
            int l=i, r;
            for(r=l;r<=n;r++)
            {
                ache[a[r]] ^= 1;
                if(!ache[a[r]])break;
            }
            if(r <= n)
            {
                ans.emplace_back(l,r);
                for(int j=l;j<=r;j++)ache[a[j]]=0;
            }
            i=r;
        }
        ans.back().second=n;
        cout << (int)ans.size() << '\n';
        for(auto [l,r] : ans)cout << l << ' ' << r << '\n';
    }
    return 0;
}
