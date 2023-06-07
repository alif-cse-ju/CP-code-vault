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

int a[M];

bool Check()
{
    int n;cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    int l=1, r=n, L=1, R=n;
    while(r-l > 2)
    {
        if(a[l] == L)++l, ++L;
        else if(a[l] == R)++l, --R;
        else if(a[r] == L)--r, ++L;
        else if(a[r] == R)--r, --R;
        else
        {
            cout << l << ' ' << r << '\n';
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        bool ans=Check();
        if(!ans)cout << "-1\n";
    }
    return 0;
}
