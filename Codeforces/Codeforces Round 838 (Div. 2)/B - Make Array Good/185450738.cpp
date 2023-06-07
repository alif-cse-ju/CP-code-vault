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

pair<ll,int>a[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i].first, a[i].second=i;
        sort(a+1,a+n+1);
        vector<pair<int,ll>>ans;
        for(int i=2;i<=n;i++)
        {
            auto [x1,i1]=a[i-1];
            auto [x2,i2]=a[i];
            if(x2%x1 == 0)continue;
            if(x1 > x2)ans.emplace_back(i2, x1-x2), a[i].first=x1;
            else ans.emplace_back(i2, x1-x2%x1), a[i].first+=x1-x2%x1;
        }
        cout << (int)ans.size() << '\n';
        for(auto [i,x] : ans)cout << i << ' ' << x << '\n';
    }
    return 0;
}
