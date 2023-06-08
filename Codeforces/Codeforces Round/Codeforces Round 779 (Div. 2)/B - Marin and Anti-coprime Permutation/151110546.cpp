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
const int mod=998244353;
ll fact[M];
void Fact()
    fact[0]=1;
    for(int i=1;i<M;i++)fact[i]=(fact[i-1]*i)%mod;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int n,t;
    Fact();
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n & 1)cout << "0\n";
        else
        {
            ans=fact[n/2];
            ans=(ans*ans)%mod;
            cout << ans << '\n';
        }
    }
    return 0;
}