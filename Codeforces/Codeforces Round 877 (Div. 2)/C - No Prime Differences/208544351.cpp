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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int>dq;
    int t;cin >> t;
    while(t--)
    {
        int m,n;cin >> n >> m;
        int cnt=0;
        if(m%2 == 0)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)cout << ++cnt << ' ';
                cout << '\n';
            }
        }
        else
        {
            int col=1;
            for(int i=1;i<=n;i++)
            {
                for(int j=col;j;j--)dq.emplace_front(++cnt);
                for(int j=col+1;j<=m;j++)dq.emplace_back(++cnt);
                for(int j=col;j;j--)cout << dq.front() << ' ', dq.pop_front();
                for(int j=col+1;j<=m;j++)cout << dq.back() << ' ', dq.pop_back();
                ++col;
                if(col > m)col=1;
                cout << '\n';
            }
        }
    }
    return 0;
}
