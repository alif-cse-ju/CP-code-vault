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
 map<pair<int,int>,int>mp;
 int Ask(int x,int y)
{
    if(mp.find({x,y}) != mp.end())return mp[{x,y}];
    cout << "? " << x << ' ' << y << endl;
    int z;cin >> z;
    return mp[{x,y}]=mp[{y,x}]=z;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        if(n == 2)cout << "! 1 2" << endl;
        else
        {
            mp.clear();
            int x=1, y=2;
            for(int i=3;i<=n;i++)
            {
                vector<tuple<int,int,int>>bal;
                int a=Ask(x,y), b=Ask(x,i), c=Ask(y,i);
                bal.emplace_back(make_tuple(min(a,b), max(a,b), x));
                bal.emplace_back(make_tuple(min(a,c), max(a,c), y));
                bal.emplace_back(make_tuple(min(b,c), max(b,c), i));
                sort(bal.begin(),bal.end());
                x=get<2>(bal[1]), y=get<2>(bal[2]);
            }
            cout << "! " << x << ' ' << y << endl;
        }
        int ans;cin >> ans;
        if(ans == 1)continue;
        else break;
    }
    return 0;
}