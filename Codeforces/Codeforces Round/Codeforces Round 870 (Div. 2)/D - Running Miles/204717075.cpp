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
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
 int a[M],n,_tree[M][2];
 void Update(int i,int v,bool b)
{
    if(b)
    {
        while(i)_tree[i][b]=max(_tree[i][b], v), i-=(i & -i);
    }
    else
    {
        while(i <= n)_tree[i][b]=max(_tree[i][b], v), i+=(i & -i);
    }
}
 int Query(int i,int b)
{
    int ans=INT_MIN;
    if(b)
    {
        while(i <= n)ans=max(ans, _tree[i][b]), i+=(i & -i);
    }
    else
    {
        while(i)ans=max(ans, _tree[i][b]), i-=(i & -i);
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n;i++)_tree[i][0]=_tree[i][1]=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            Update(i,a[i]+i,0), Update(i,a[i]-i,1);
        }
        int ans=INT_MIN;
        for(int i=2;i<n;i++)ans=max(ans, a[i]+Query(i-1,0)+Query(i+1,1));
        cout << ans << '\n';
    }
    return 0;
}