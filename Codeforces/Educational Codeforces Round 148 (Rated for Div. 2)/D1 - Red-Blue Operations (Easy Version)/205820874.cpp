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

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;

const int mx = 1e3+5;

ll a[mx],b[mx];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> a[i];
    if(n == 1)
    {
        while(q--)
        {
            int k;cin >> k;
            if(k & 1)cout << a[1]+(k+1)/2 << ' ';
            else cout << a[1]-k/2 << ' ';
        }
        return 0;
    }
    sort(a+1,a+n+1);
    while(q--)
    {
        ll k;cin >> k;
        for(int i=1;i<=n;i++)
        {
            b[i]=a[i]+k;
            if(k)--k;
        }
        if(!k)
        {
            sort(b+1,b+n+1);
            cout << b[1] << ' ';
        }
        else
        {
            if(k & 1)b[n]-=++k;
            k/=2, sort(b+1,b+n+1);
            ll l=0, r=b[1];
            while(l <= r)
            {
                ll m=(l+r) >> 1ll;
                ll sum=0;
                for(int i=1;i<=n;i++)sum += b[i]-m;
                if(sum >= k)l=m+1;
                else r=m-1;
            }
            cout << l-1 << ' ';
        }
    }
    return 0;
}