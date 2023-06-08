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
const int N=2e6+5;
const int mod=1e9+7;
char s[M];
int par[M],sum[M];
ordered_set<int>ost[3];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,l,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> s+1;
        ost[0].clear();
        ost[1].clear();
        ost[2].clear();
        ans=0;
        for(i=1;i<=l;i++)
        {
            sum[i]=sum[i-1];
            if(s[i] == '+')sum[i]++;
            else --sum[i];
            par[i]=(sum[i]%3);
            if(par[i] < 0)par[i] += 3;
        }
        for(i=l;i;i--)
        {
            ans += ost[par[i]].order_of_key(sum[i]+1);
            ost[par[i]].insert(sum[i]);
        }
        ans += ost[0].order_of_key(1);
        cout << ans << '\n';
    }
    return 0;
}