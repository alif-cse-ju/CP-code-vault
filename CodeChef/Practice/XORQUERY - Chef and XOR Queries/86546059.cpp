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
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int par[M],xr[M];
vector<int>idx[M];
int FindPar(int x)
{
    if(par[x] == x)return x;
    return par[x]=FindPar(par[x]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n,q;cin >> n >> q;
        for(int i=1;i<n;i++)
        {
            int x,y;cin >> x >> y;
        }
        for(int i=1;i<=n;i++)par[i]=i, xr[i]=0, idx[i].clear(), idx[i].emplace_back(i);
        while(q--)
        {
            int op;cin >> op;
            if(op == 1)
            {
                int x,y,z;cin >> x >> y >> z;
                int px=FindPar(x), py=FindPar(y);
                if(px == py)
                {
                    if((xr[x] ^ xr[y]) == z)cout << "AC\n";
                    else cout << "WA\n";
                }
                else
                {
                    cout << "AC\n";
                    if((int)idx[px].size() >= (int)idx[py].size())
                    {
                        par[py]=px;
                        int v=(xr[x]^xr[y]^z);
                        while(!idx[py].empty())
                        {
                            int b=idx[py].back(); idx[py].pop_back();
                            xr[b]^=v, idx[px].emplace_back(b);
                        }
                    }
                    else
                    {
                        par[px]=py;
                        int v=(xr[x]^xr[y]^z);
                        while(!idx[px].empty())
                        {
                            int b=idx[px].back(); idx[px].pop_back();
                            xr[b]^=v, idx[py].emplace_back(b);
                        }
                    }
                }
            }
            else
            {
                int x,y;cin >> x >> y;
                int px=FindPar(x), py=FindPar(y);
                if(px != py)cout << "-1\n";
                else cout << (xr[x]^xr[y]) << '\n';
            }
        }
    }
    return 0;
}