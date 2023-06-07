#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
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
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    string ans,s;
    int cnt,k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> x >> s;
        cnt=0;
        vector<int>v;
        for(char c : s)
        {
            if(c == '*')++cnt;
            else
            {
                if(cnt)v.emplace_back(cnt*k+1);
                cnt=0;
            }
        }
        if(cnt)v.emplace_back(cnt*k+1);
        ans="", --x;
        while(!s.empty())
        {
            if(s.back() == 'a')ans += 'a', s.pop_back();
            else
            {
                while(!s.empty()  &&  s.back() == '*')s.pop_back();
                k=x%v.back(), x/=v.back(), v.pop_back();
                while(k--)ans += 'b';
            }
        }
        reverse(ans.begin(),ans.end());
        cout << ans << '\n';
    }
    return 0;
}