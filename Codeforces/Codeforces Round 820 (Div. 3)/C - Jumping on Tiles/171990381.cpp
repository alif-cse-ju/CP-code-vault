#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
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
const int M=5e5+5;
const int N=2e6+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        string s;cin >> s;
        vector<int>ans[26];
        for(int i=0;i<(int)s.size();i++)
        {
            char c=s[i];
            if(c >= min(s[0], s.back())  &&  c <= max(s[0], s.back()))ans[c-'a'].emplace_back(i+1);
        }
        int cost=0, last=-1, jump=0;
        for(int i=0;i<26;i++)
        {
            if(!ans[i].empty())
            {
                if(last > -1)cost += i-last;
                last = i, jump += (int)ans[i].size();
            }
        }
        cout << cost << ' ' << jump << '\n';
        if(s[0] > s.back())
        {
            for(int i=25;i>=0;i--)
            {
                for(int it : ans[i])cout << it << ' ';
            }
        }
        else
        {
            for(int i=0;i<26;i++)
            {
                for(int it : ans[i])cout << it << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}