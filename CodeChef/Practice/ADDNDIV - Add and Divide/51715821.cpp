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
const int N=4e6+5;
const int mod=1e9+7;
bool mark[M];
vector<ll>primes;
void Sieve()
{
    ll i,j;
    primes.emplace_back(2);
    for(i=3;i<M;i+=2)
    {
        if(!mark[i])
        {
            primes.emplace_back(i);
            for(j=i*i;j<M;j+=2*i)mark[j]=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll a,b,gcd;
    Sieve();
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a == 1  ||  b == 1)cout << "YES\n";
        else
        {
            gcd=__gcd(a,b);
            if(gcd == 1)cout << "NO\n";
            else
            {
                for(ll it : primes)
                {
                    if(it*it > gcd)break;
                    if(gcd%it == 0)
                    {
                        while(a%it == 0)a/=it;
                        while(gcd%it == 0)gcd/=it;
                    }
                }
                if(gcd > 1)
                {
                    while(a%gcd == 0)a/=gcd;
                }
                if(a == 1)cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    return 0;
}