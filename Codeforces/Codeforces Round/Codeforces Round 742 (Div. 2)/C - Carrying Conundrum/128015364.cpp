#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
    string s;
    int i,l,t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=(int)s.size();
        a=b=0;
        for(i=0;i<l;i++)
        {
            if(i & 1)a=a*10+(s[i]-'0');
            else b=b*10+(s[i]-'0');
        }
        cout << (a+1)*(b+1)-2 << '\n';
    }
    return 0;
}