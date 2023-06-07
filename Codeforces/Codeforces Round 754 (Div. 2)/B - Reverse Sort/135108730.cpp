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
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,l,t,_0,_1;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        _0=_1=0;
        for(char c : s)
        {
            if(c == '0')++_0;
            else ++_1;
        }
        vector<int>v;
        for(i=0;i<_0;i++)
        {
            if(s[i] == '1')v.emplace_back(i+1);
        }
        for(i=_0;i<l;i++)
        {
            if(s[i] == '0')v.emplace_back(i+1);
        }
        if(v.empty())cout << "0\n";
        else
        {
            cout << "1\n";
            cout << (int)v.size();
            for(int it : v)cout << ' ' << it;
            cout << '\n';
        }
    }
    return 0;
}