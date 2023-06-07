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
const int N=1e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    int mn=0,mx=0;
    for(int i=1;i<=n;i++)
    {
        string s;cin >> s;
        int odd=0, tot=0;
        for(int l=0;l<m;l++)
        {
            if(s[l] == '0')continue;
            int cnt=0,r=l;
            while(r < m  &&  s[r] == '1')++cnt, ++r;
            l=r, odd+=cnt%2, tot+=cnt;
        }

        ///for minimum
        {
            int dMax=min(m/4, (tot-odd)/2);
            mn += tot-dMax;
        }

        ///for maximum
        {
            int cnt0=0;
            for(int j=0;j+1<m;j++)
            {
                if(s[j] == '0'  ||  s[j+1] == '0')++cnt0, ++j;
            }
            mx += tot-m/4+min(cnt0,m/4);
        }
    }
    cout << mn << ' ' << mx;
    return 0;
}
