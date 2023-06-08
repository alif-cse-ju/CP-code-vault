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
const int M=3e5+5;
const int N=1e6+5;
const int mod=998244353;
int sum[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,l,n,q,r,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> q >> s;
        for(i=1;i<=n;i++)
        {
            sum[i]=sum[i-1];
            if(i & 1)
            {
                if(s[i-1] == '+')++sum[i];
                else --sum[i];
            }
            else
            {
                if(s[i-1] == '-')++sum[i];
                else --sum[i];
            }
        }
        while(q--)
        {
            cin >> l >> r;
            if((l & 1)  &&  sum[r]-sum[l-1] == 0)cout << "0\n";
            else if(!(l & 1)  &&  sum[l-1]-sum[r] == 0)cout << "0\n";
            else if((r-l) & 1)cout << "2\n";
            else cout << "1\n";
        }
    }
    return 0;
}