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
 int a[M],pos[M];
 ll Cal(ll n)
{
    return (n*(n+1))/2;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i], pos[a[i]]=i;
        ll ans=1;
        int l=pos[0], r=pos[0];
        ordered_set<int>ost; ost.insert(0);
        for(int i=1;i<n;i++)
        {
            if(ost.order_of_key(i+1) > i)continue;
            bool ok=((int)ost.size() <= i+i);
            int L,R,nibo=max(0, i+i-(int)ost.size());
            if(pos[i] < l)
            {
                L=min(l-pos[i]-1, 2*i-(int)ost.size()), R=min(n-r, 2*i-(int)ost.size());
                while(l > pos[i])--l, ost.insert(a[l]);
            }
            else
            {
                L=min(l-1, 2*i-(int)ost.size()), R=min(pos[i]-r-1, 2*i-(int)ost.size());
                while(r < pos[i])++r, ost.insert(a[r]);
            }
            if(!ok)continue;
            if(L < R)swap(L, R);
            ans += 1ll*min(nibo-R+1, L+1)*(R+1);
            ans += Cal(R) - Cal(R-L+min(nibo-R, L));
        }
        cout << ans << '\n';
    }
    return 0;
}