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
int a[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i];
        vector<tuple<int,int,int>>ans;
        for(int i=29;i>=0;i--)
        {
            vector<int>one,zero;
            for(int j=1;j<=n;j++)
            {
                if((a[j] >> i) & 1)one.emplace_back(j);
                else zero.emplace_back(j);
            }
            while((int)one.size() > 2)
            {
                int x=one.back(); one.pop_back();
                int y=one.back(); one.pop_back();
                int z=one.back(); one.pop_back();
                ans.emplace_back(make_tuple(a[x], a[y], a[z]));
                int X=a[x]^a[y], Y=a[y]^a[z], Z=a[z]^a[x];
                a[x]=X, a[y]=Y, a[z]=Z;
                zero.emplace_back(x), zero.emplace_back(y), zero.emplace_back(z);
            }
            if((int)one.size() == 2)
            {
                int x=one.back(); one.pop_back();
                int y=zero.back(); zero.pop_back();
                int z=zero.back(); zero.pop_back();
                ans.emplace_back(make_tuple(a[x], a[y], a[z]));
                int X=a[x]^a[y], Y=a[y]^a[z], Z=a[z]^a[x];
                a[x]=X, a[y]=Y, a[z]=Z;
                one.emplace_back(x), zero.emplace_back(y), one.emplace_back(z);
            }
            else if((int)one.size() == 1)
            {
                int x=one.back(); one.pop_back();
                int y=zero.back(); zero.pop_back();
                int z=zero.back(); zero.pop_back();
                ans.emplace_back(make_tuple(a[x], a[y], a[z]));
                int X=a[x]^a[y], Y=a[y]^a[z], Z=a[z]^a[x];
                a[x]=X, a[y]=Y, a[z]=Z;
                one.emplace_back(x), zero.emplace_back(y), one.emplace_back(z);
                x=one.back(); one.pop_back();
                y=zero.back(); zero.pop_back();
                z=zero.back(); zero.pop_back();
                ans.emplace_back(make_tuple(a[x], a[y], a[z]));
                X=a[x]^a[y], Y=a[y]^a[z], Z=a[z]^a[x], a[x]=X, a[y]=Y, a[z]=Z;
                one.emplace_back(x), zero.emplace_back(y), one.emplace_back(z);
            }
            while((int)one.size() > 0)
            {
                int x=one.back(); one.pop_back();
                int y=one.back(); one.pop_back();
                int z=one.back(); one.pop_back();
                ans.emplace_back(make_tuple(a[x], a[y], a[z]));
                int X=a[x]^a[y], Y=a[y]^a[z], Z=a[z]^a[x];
                a[x]=X, a[y]=Y, a[z]=Z;
                zero.emplace_back(x), zero.emplace_back(y), zero.emplace_back(z);
            }
        }
        cout << (int)ans.size() << '\n';
        for(auto [x,y,z] : ans)cout << x << ' ' << y << ' ' << z << '\n';
    }
    return 0;
}