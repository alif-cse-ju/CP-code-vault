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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

bool nichi[M];
int a[M],ans[M],n;

vector<int>Solve(vector<int>v,int j)
{
    vector<int>vv;
    for(int i=0;i<(int)v.size();i++)
    {
        if((a[v[i]] >> j) & 1)vv.emplace_back(v[i]);
    }
    if(vv.empty())return v;
    return vv;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i], nichi[i]=0;
        int pre=0, j=0;
        for(int i=29;i>=0;i--)
        {
            if((pre >> i) & 1)continue;
            vector<int>v;
            for(int k=1;k<=n;k++)
            {
                if((a[k] >> i) & 1)v.emplace_back(k);
            }
            if(v.empty())continue;
            for(int k=i-1;k>=0;k--)
            {
                if((pre >> k) & 1)continue;
                v=Solve(v,k);
            }
            ans[++j]=a[v[0]], nichi[v[0]]=1, pre=(pre | ans[j]);
        }
        for(int i=1;i<=n;i++)
        {
            if(!nichi[i])ans[++j]=a[i];
        }
        for(int i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
