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
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
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
const int mx = 1e3+5;
int par[mx];
bool dakbo[mx];
vector<int>idx[mx];
int FindParent(int p)
{
    if(par[p] == p)return p;
    return par[p]=FindParent(par[p]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    set<pair<int,int>>st;
    for(int i=1;i<=n;i++)idx[i].emplace_back(i), par[i]=i, st.insert({1,i});
    ll ans=0;
    while((int)st.size() > 1)
    {
        auto [sz,x]=*(st.begin());
        for(int i=1;i<=n;i++)dakbo[i]=1;
        for(int &y : idx[x])dakbo[y]=0;
        vector<int>a,b;
        for(int i=1;i<=n;i++)
        {
            if(dakbo[i])b.emplace_back(i);
            else a.emplace_back(i);
        }
        cout << "1 " << (int)a.size() << ' ' << (int)b.size() << endl;
        for(int &y : a)cout << y << ' ';
        cout << endl;
        for(int &y : b)cout << y << ' ';
        cout << endl;
        int y,w;cin >> x >> y >> w;
        ans += w;
        int px=FindParent(x), py=FindParent(y);
        st.erase({(int)idx[px].size(),px}), st.erase({(int)idx[py].size(),py});
        if((int)idx[px].size() >= (int)idx[py].size())
        {
            par[py]=px;
            while(!idx[py].empty())idx[px].emplace_back(idx[py].back()), idx[py].pop_back();
            st.insert({(int)idx[px].size(), px});
        }
        else
        {
            par[px]=py;
            while(!idx[px].empty())idx[py].emplace_back(idx[px].back()), idx[px].pop_back();
            st.insert({(int)idx[py].size(), py});
        }
    }
    cout << "2 " << ans << endl;
    return 0;
}