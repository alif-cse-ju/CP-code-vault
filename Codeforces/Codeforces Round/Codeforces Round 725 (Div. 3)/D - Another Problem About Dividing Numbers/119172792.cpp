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
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
bool mark[M];
vector<ll>primes;
void Sieve()
    int i,j;
    primes.emplace_back(2);
    for(i=3;i<M;i+=2)
    {
        if(!mark[i])
        {
            primes.emplace_back(i);
            if(i < 1e3)
            {
                for(j=i*i;j<M;j+=2*i)mark[j]=1;
            }
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Sieve();
    int a,b,k,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> k;
        if(k == 1)
        {
            if(a != b  &&  (a%b == 0  ||  b%a == 0))cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        x=y=0;
        for(ll it : primes)
        {
            if(it*it > a  &&  it*it > b)break;
            while(a%it == 0)++x,a/=it;
            while(b%it == 0)++y,b/=it;
        }
        x+=(a > 1);
        y+=(b > 1);
        if(x+y >= k)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}