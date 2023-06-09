#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mx=15000000;
int a[300005],cnt[mx+5],fact[mx+5];
void Sieve()
    int i,j,l=0;
    vector<int>primes;
    for(i=2;i<=mx;i++)
    {
        if(!fact[i])
        {
            ++l,fact[i]=i;
            primes.emplace_back(i);
        }
        for(j=0;j<l  &&  primes[j] <= fact[i]  &&  i*primes[j] <= mx;j++)fact[i*primes[j]]=primes[j];
    }
int main()
    FAST();
    Sieve();
    int i,j,n,x,ans=0,gcd=0;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        gcd=__gcd(a[i],gcd);
    }
    for(i=1;i<=n;i++)
    {
        j=a[i]/gcd;
        while(j > 1)
        {
            x=fact[j];
            ++cnt[x];
            while(fact[j] == x)j/=x;
        }
    }
    for(i=2;i<=mx;i++)ans=max(ans,cnt[i]);
    if(!ans)cout << "-1";
    else cout << n-ans;
    return 0;
}