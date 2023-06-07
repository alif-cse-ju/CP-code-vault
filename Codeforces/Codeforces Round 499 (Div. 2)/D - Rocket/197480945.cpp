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

const int M=5e5+5;
const int N=1.1e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> m >> n;
    vector<int>truth(n);
    for(int i=0;i<n;i++)
    {
        cout << 1 << endl, cin >> truth[i];
        if(!truth[i]) return 0;
        truth[i]=max(0, truth[i]);
    }
    int i=0,l=2,r=m;
    while(l <= r)
    {
        int m=(l+r) >> 1;
        cout << m << endl;
        int q;cin >> q;
        if(!q)return 0;
        if(!truth[i%n])q=-q;
        if(q == 1)l=m+1;
        else r=m-1;
        ++i;
    }
    return 0;
}