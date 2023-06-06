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
const int N=1e6+5;
const int mod=998244353;

int Solve(vector<int>v,int b)
{
    if(b < 0)return 0;
    vector<int>_0,_1;
    for(int &it : v)
    {
        if((it >> b) & 1)_1.emplace_back(it);
        else _0.emplace_back(it);
    }
    if(_0.empty())return Solve(_1,b-1);
    if(_1.empty())return Solve(_0,b-1);
    return (1 << b) + min(Solve(_0,b-1), Solve(_1,b-1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    vector<int>a(n);
    for(int &x : a)cin >> x;
    cout << Solve(a,29);
    return 0;
}
