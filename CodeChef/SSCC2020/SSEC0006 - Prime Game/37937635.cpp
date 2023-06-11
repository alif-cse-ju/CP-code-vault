#include<bits/stdc++.h>
using namespace std;
bool mark[1002];
vector<int>primes;
void Sieve()
{
    int i,j;
    primes.emplace_back(2);
    for(i=3;i<1000;i+=2)
    {
        if(!mark[i])
        {
            primes.emplace_back(i);
            for(j=i*i;j<=1000;j+=2*i)mark[j]=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    Sieve();
    int a,b,i,j,x,l1,l2,mn,mx;
    cin >> a >> b;
    mx=a*b,mn=mx/4;
    l1=lower_bound(primes.begin(),primes.end(),a)-primes.begin();
    l2=lower_bound(primes.begin(),primes.end(),b)-primes.begin();
    for(i=l1;i<l2;i++)
    {
        for(j=i+1;j<l2;j++)
        {
            x=primes[i]*primes[j];
            if(x >= mn  &&  x <= mx)cout << primes[i] << ',' << primes[j] << '\n';
        }
    }
    return 0;
}