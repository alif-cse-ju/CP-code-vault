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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
 char s[M];
ordered_set<int>ost;
 void Update(int i, bool in)
{
    if(i & 1)
    {
        if(s[i] == ')')
        {
            if(in)ost.insert(i);
            else ost.erase(ost.find_by_order(ost.order_of_key(i)));
        }
    }
    else
    {
        if(s[i] == '(')
        {
            if(in)ost.insert(i);
            else ost.erase(ost.find_by_order(ost.order_of_key(i)));
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin >> n >> q >> s+1;
    if(n & 1)
    {
        while(q--)
        {
            int i;cin >> i;
            cout << "NO\n";
        }
        return 0;
    }
    for(int i=1;i<=n;i++)Update(i, 1);
    while(q--)
    {
        int i;cin >> i;
        Update(i, 0);
        if(s[i] == '(')s[i]=')';
        else s[i]='(';
        Update(i, 1);
        if(ost.empty())cout << "YES\n";
        else
        {
            int l=*ost.find_by_order(0), r=*ost.find_by_order((int)ost.size()-1);
            if(l%2  ||  !(r%2))cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}