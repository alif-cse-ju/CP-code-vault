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
const int sz = 1e7+5;
ll ans[sz];
int cnt[sz];
bool mark[sz];
ordered_set<int>primes;
void Sieve()
    int i,j,k,rt=sqrt(sz);
    primes.insert(2);
    mark[1]=1;
    for(i=4;i<sz;i+=2)mark[i]=1;
    for(i=3;i<sz;i+=2)
    {
        if(!mark[i])
        {
            primes.insert(i);
            if(i <= rt)
            {
                for(j=i*i, k=2*i;j<sz;j+=k)mark[j]=1;
            }
        }
    }
}
 void PreCal()
{
    int i,j;
    for(i=4;i<sz;i+=2)cnt[2] += cnt[i];
    for(i=1e7-1;i>2;i-=2)
    {
        if(!mark[i])
        {
            for(j=i+i;j<sz;j+=i)cnt[i] += cnt[j];
        }
    }
    i=1;
    for(int it : primes)ans[i]=ans[i-1]+cnt[it], ++i;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,m,n,r,x;
    cin >> n;
    for(i=0;i<n;i++)cin >> x, ++cnt[x];
    Sieve();
    PreCal();
    cin >> m;
    while(m--)
    {
        cin >> l >> r;
        cout << ans[primes.order_of_key(r+1)]-ans[primes.order_of_key(l)] << '\n';
    }
    return 0;
}