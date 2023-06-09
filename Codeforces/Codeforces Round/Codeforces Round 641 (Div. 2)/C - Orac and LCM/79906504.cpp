#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
bool mark[200005];
vector<LL>primes,cnt[200005];
LL BigMod(LL val,LL pow)
    LL res = 1;
    while(pow > 0)
    {
        if(pow & 1)res *= val;
        pow = pow >> 1,val *= val;
    }
    return res;
void Sieve()
    LL i,j,k,n=200000;
    primes.emplace_back(2);
    for(i=3;i<n;i+=2)
    {
        if(!mark[i])
        {
            primes.emplace_back(i);
            for(j=i*i,k=2*i;j<=n;j+=k)mark[j]=1;
        }
    }
void Factorize()
    int i,ans=0;
    LL x;
    cin >> x;
    for(i=0;primes[i]*primes[i] <= x;i++)
    {
        if(x%primes[i] == 0)
        {
            ans=0;
            while(x%primes[i] == 0)
            {
                ++ans;
                x/=primes[i];
            }
            cnt[primes[i]].emplace_back(ans);
        }
    }
    if(x > 1)cnt[x].emplace_back(1);
}
 int main()
{
    FAST();
    int i,n;
    LL gcd=1;
    Sieve();
    cin >> n;
    for(i=0;i<n;i++)Factorize();
    for(LL x : primes)
    {
        if(cnt[x].size() < n-1)continue;
        sort(cnt[x].begin(),cnt[x].end());
        if(cnt[x].size() == n)gcd *= BigMod(x,cnt[x][1]);
        else gcd *= BigMod(x,cnt[x][0]);
    }
    cout << gcd;
    return 0;
}