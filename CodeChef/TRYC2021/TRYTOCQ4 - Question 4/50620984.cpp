#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;
bool mark[N];
vector<ll>primes;
void Sieve()
{
    ll i,j;
    primes.emplace_back(2);
    for(i=3;i<N;i+=2)
    {
        if(!mark[i])
        {
            primes.emplace_back(i);
            for(j=i*i;j<N;j+=2*i)mark[j]=1;
        }
    }
}
ll Solve(ll n, ll val)
{
    if(n == 1ll)return val;
    vector<ll>v;
    ll m=n;
    for(ll it : primes)
    {
        if(it*it > m)break;
        if(m%it == 0ll)
        {
            v.emplace_back(it);
            while(m%it == 0ll)m/=it;
        }
    }
    if(m > 1ll)v.emplace_back(m);
    return val*(Solve(n/v.back(),v.back())+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll ans=0,i,N;
    cin >> n;
    Sieve();
    while(n--)
    {
        cin >> N;
        ans+=Solve(N,1ll);
    }
    cout << ans;
    return 0;
}