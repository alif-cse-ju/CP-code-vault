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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
 int a[M],cnt[M],xr[M],pre[M];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin >> n >> q;
    map<int,int>mp[2];
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        cnt[i]=cnt[i-1]+(a[i]>0);
        xr[i]=(xr[i-1]^a[i]);
        mp[i&1][xr[i]]=i;
        if(mp[1-(i&1)].find(xr[i]) != mp[1-(i&1)].end())pre[i]=mp[1-(i&1)][xr[i]];
    }
    while(q--)
    {
        int l,r;cin >> l >> r;
        if((xr[r]^xr[l-1]) != 0)cout << "-1\n";
        else if(cnt[r]-cnt[l-1] == 0)cout << "0\n";
        else if((r-l+1) & 1)cout << "1\n";
        else
        {
            if(!a[l]  ||  !a[r])cout << "1\n";
            else if(pre[r] >= l)cout << "2\n";
            else cout << "-1\n";
        }
    }
    return 0;
}