#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool mark[N];
long long ans[N];
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
            for(j=i*i;j<N;j+=2*i)mark[j]=1;
        }
    }
    for(i=1001;i<N;i+=2)
    {
        if(!mark[i])primes.emplace_back(i);
    }
}
void PreCal()
{
    int i,l=primes.size();
    for(i=0;i<l;i++)ans[i+1]=ans[i]+primes[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    Sieve();
    PreCal();
    int n,t,idx;
    cin >> t;
    while(t--)
    {
        cin >> n;
        idx=upper_bound(primes.begin(),primes.end(),n)-primes.begin();
        cout << ans[idx]%10 << '\n';
    }
    return 0;
}