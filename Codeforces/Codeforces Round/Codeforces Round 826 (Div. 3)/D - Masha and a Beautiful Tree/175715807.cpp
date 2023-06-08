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
 const int mx = 262144 + 5;
 int a[mx],ans,b[mx];
 void Solve(int l,int r)
{
    if(l == r)
    {
        b[l]=a[l];
        return;
    }
    int m=(l+r) >> 1;
    Solve(l,m), Solve(m+1,r);
    int L=l, R=m+1;
    if(b[L] > b[R])++ans, swap(L,R);
    for(int i=l;i<=m;i++)a[i]=b[L++];
    for(int i=m+1;i<=r;i++)a[i]=b[R++];
    for(int i=l;i<=r;i++)b[i]=a[i];
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        ans=0;
        for(int i=1;i<=n;i++)cin >> a[i];
        Solve(1,n);
        for(int i=1;i<=n;i++)
        {
            if(a[i] != i)ans=-1;
        }
        cout << ans << '\n';
    }
    return 0;
}