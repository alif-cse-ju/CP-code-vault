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
const int mod=1e9+7;

int pos[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;cin >> x;
    pos[x]=1;
    for(int i=2;i<=1000;i++)
    {
        cout << "+ 1" << endl;
        int x;cin >> x;
        if(pos[x])
        {
            cout << "! " << i-1 << endl;
            exit(0);
        }
        pos[x]=i;
    }
    int len=1000;
    for(int i=2000; ;i+=1000)
    {
        cout << "+ 1000" << endl;
        int x;cin >> x;
        len += 1000;
        if(pos[x])
        {
            cout << "! " << len-pos[x] << endl;
            exit(0);
        }
        pos[x]=i;
    }
    return 0;
}
///
