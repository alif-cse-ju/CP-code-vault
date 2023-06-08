#pragma GCC optimize("Ofast")
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
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    int l,n,t;
    string s,ss;
    cin >> t;
    while(t--)
    {
        ok=0;
        cin >> n;
        set<string>st,voda;
        while(n--)
        {
            cin >> s;
            l=(int)s.size();
            ss=s, reverse(ss.begin(),ss.end());
            if(s[0] == s[l-1]  ||  st.find(ss) != st.end()  ||  (l == 2  &&  voda.find(ss) != voda.end()))ok=1;
            else if(l > 2)
            {
                ss=s, reverse(ss.begin(),ss.end()), ss.pop_back();
                if(st.find(ss) != st.end())ok=1;
                else ss=s, ss.pop_back(), voda.insert(ss);
            }
            st.insert(s);
        }
        if(ok)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}