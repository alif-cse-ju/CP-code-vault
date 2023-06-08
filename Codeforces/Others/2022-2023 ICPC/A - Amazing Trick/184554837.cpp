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
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
 int pos[M];
 int generateSeed (int i) {
    return rand() % i;
}
 void Solve()
{
    int n;cin >> n;
    vector<int>p(n), q(n);
    for(int i=1;i<=n;i++)
    {
        int x;cin >> x;
        pos[x]=q[i-1]=i;
    }
    int iter=0;
    srand ( unsigned ( time(0) ) );
    while(iter < 100)
    {
        ++iter;
        random_shuffle(q.begin(), q.end(), generateSeed);
        for(int i=0;i<n;i++)p[q[i]-1]=pos[i+1];
        bool ok=1;
        for(int i=0;i<n  &&  ok;i++)
        {
            if(p[i] == i+1)ok=0;
            if(q[i] == i+1)ok=0;
        }
        if(ok)
        {
            cout << "Possible\n";
            for(int i=0;i<n;i++)cout << p[i] << ' ';
            cout << '\n';
            for(int i=0;i<n;i++)cout << q[i] << ' ';
            cout << '\n';
            return;
        }
    }
    cout << "Impossible\n";
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)Solve();
    return 0;
}