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
const int N=2e6+5;
const int mod=1e9+7;

int posP[M],posQ[M];

ll Cal(int n)
{
    return (1ll*n*(n+1))/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;cin >> x;
        posP[x]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int x;cin >> x;
        posQ[x]=i;
    }
    int l=min(posP[1], posQ[1]);
    int r=max(posP[1], posQ[1]);
    ll ans=Cal(l-1) + Cal(n-r) + Cal(r-l-1) + 1;
    for(int i=2;i<=n;i++)
    {
        if(posP[i] >= l  &&  posP[i] <= r)l=min(l, posQ[i]), r=max(r, posQ[i]);
        else if(posQ[i] >= l  &&  posQ[i] <= r)l=min(l, posP[i]), r=max(r, posP[i]);
        else if(posP[i] < l  &&  posQ[i] < l)
        {
            ans += 1ll * (n-r+1) * (l-max(posP[i], posQ[i]));
            l=min({l, posP[i], posQ[i]});
        }
        else if(posP[i] > r  &&  posQ[i] > r)
        {
            ans += 1ll * l * (min(posP[i], posQ[i])-r);
            r=max({r, posP[i], posQ[i]});
        }
        else
        {
            int x=posP[i], y=posQ[i];
            if(x > y)swap(x,y);
            ans += 1ll * (l-x) * (y-r);
            l=min(l, x), r=max(r, y);
        }
    }
    cout << ans;
    return 0;
}