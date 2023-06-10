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
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int ans[M];
bool cmp(tuple<int,int,int>x, tuple<int,int,int>y)
{
    auto [l1,r1,i1]=x;
    auto [l2,r2,i2]=y;
    if(l1 == l2)return r1 >= r2;
    return l1 <= l2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        vector<tuple<int,int,int>>v;
        for(int i=1;i<=n;i++)
        {
            ans[i]=0;
            int l,r;cin >> l >> r;
            v.emplace_back(make_tuple(l,r,i));
        }
        sort(v.begin(),v.end(),cmp);
        int B=0, Y=0;
        for(auto [l,r,i] : v)
        {
            if(r <= B  &&  r <= Y)continue;
            if(B <= Y)B=r;
            else Y=r, ans[i]=1;
        }
        for(int i=1;i<=n;i++)cout << ans[i];
        cout << '\n';
    }
    return 0;
}