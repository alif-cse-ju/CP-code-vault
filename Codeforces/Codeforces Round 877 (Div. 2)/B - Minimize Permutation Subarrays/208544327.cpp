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

int a[M],n,pos[M],pp[M];

int Check()
{
    for(int i=1;i<=n;i++)pp[a[i]]=i;
    int cnt=0, l=pp[1], r=pp[1];
    for(int i=2;i<=n;i++)
    {
        while(pp[i] < l)--l;
        while(pp[i] > r)++r;
        if(r-l+1 == i)++cnt;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i], pos[a[i]]=i;
        if(min(a[1],a[n]) == 1  &&  max(a[1],a[n]) == 2)cout << "1 1\n";
        else
        {
            int mn=INT_MAX, tmp;
            pair<int,int>ans;
            swap(a[1],a[pos[1]]);
            tmp=Check();
            if(tmp < mn)ans={1,pos[1]}, mn=tmp;
            swap(a[1],a[pos[1]]);

            swap(a[n],a[pos[1]]);
            tmp=Check();
            if(tmp < mn)ans={n,pos[1]}, mn=tmp;
            swap(a[n],a[pos[1]]);

            swap(a[1],a[pos[2]]);
            tmp=Check();
            if(tmp < mn)ans={1,pos[2]}, mn=tmp;
            swap(a[1],a[pos[2]]);

            swap(a[n],a[pos[2]]);
            tmp=Check();
            if(tmp < mn)ans={n,pos[2]}, mn=tmp;
            swap(a[n],a[pos[2]]);

            cout << ans.first << ' ' << ans.second << '\n';
        }
    }
    return 0;
}
