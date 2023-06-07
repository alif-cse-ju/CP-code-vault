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

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
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
    int t;cin >> t;
    while(t--)
    {
        string s;cin >> s;
        vector<int>v;
        for(int i=0;i<(int)s.size();i++)
        {
            while(!v.empty()  &&  s[v.back()] > s[i])v.pop_back();
            v.emplace_back(i);
        }
        vector<bool>mark((int)s.size(), 0);
        for(int &it : v)mark[it]=1;
        vector<char>vv;
        for(int i=0;i<(int)s.size();i++)
        {
            if(!mark[i])vv.emplace_back(min('9', (char)(s[i]+1)));
        }
        sort(vv.begin(),vv.end());
        reverse(v.begin(),v.end()), reverse(vv.begin(),vv.end());
        while(!v.empty()  &&  !vv.empty())
        {
            if(s[v.back()] <= vv.back())cout << s[v.back()], v.pop_back();
            else cout << vv.back(), vv.pop_back();
        }
        while(!v.empty())cout << s[v.back()], v.pop_back();
        while(!vv.empty())cout << vv.back(), vv.pop_back();
        cout << '\n';
    }
    return 0;
}