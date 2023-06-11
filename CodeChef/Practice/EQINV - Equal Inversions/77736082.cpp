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
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=1e6+5;
const int mod=998244353;
char a[M],b[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n >> a+1 >> b+1;
        vector<int>ans1, ans2;
        for(int i=1;i<=n;i++)
        {
            if(a[i] != b[i])ans1.emplace_back(i);
            else ans2.emplace_back(i);
        }
        if((int)ans1.size() <= (int)ans2.size()+1)
        {
            cout << (int)ans1.size() << '\n';
            for(int &it : ans1)cout << "1 " << it << '\n';
        }
        else
        {
            cout << (int)ans2.size()+1 << '\n';
            for(int &it : ans2)cout << "1 " << it << '\n';
            cout << "2\n";
        }
    }
    return 0;
}
//1268