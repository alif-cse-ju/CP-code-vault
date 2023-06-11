#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int lp;
bool mark[N];
vector<int>primes;
void Sieve()
{
    int i,j,rt=1e3;
    primes.emplace_back(2);
    for(i=3;i<N;i+=2)
    {
        if(!mark[i])
        {
            primes.emplace_back(i);
            if(i < rt)
            {
                for(j=i*i;j<N;j+=2*i)mark[j]=1;
            }
        }
    }
    lp=primes.size();
}
long long Phi(long long n)
{
    int i,x,rt=sqrt(n);
    long long ans=n;
    for(i=0;i<lp  &&  primes[i]<=rt;i++)
    {
        x=primes[i];
        if(n%x == 0)
        {
            while(n%x == 0)n/=x;
            rt=sqrt(n);
            ans/=x;
            ans*=(x-1);
        }
    }
    if(n > 1)
    {
        ans/=n;
        ans*=(n-1);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,t;
    long long x;
    Sieve();
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(k > n)cout << "0\n";
        else
        {
            x=Phi(n/k);
            cout << (x*(x-1))/2 << '\n';
        }
    }
    return 0;
}