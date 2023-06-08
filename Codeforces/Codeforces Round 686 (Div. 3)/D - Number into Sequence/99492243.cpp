#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
bool mark[N];
vector<int>primes;
void Sieve()
    int i,j,rt=sqrt(N);
    primes.emplace_back(2);
    for(i=3;i<N;i+=2)
    {
        if(!mark[i])
        {
            primes.emplace_back(i);
            if(i <= rt)
            {
                for(j=i*i;j<N;j+=2*i)mark[j]=1;
            }
        }
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,t;
    long long m,n;
    Sieve();
    l=(int)primes.size();
    cin >> t;
    while(t--)
    {
        cin >> n;
        m=n;
        vector<pair<int,long long>>v;
        for(i=0;i<l  &&  m > 1;i++)
        {
            if(m%primes[i] == 0)
            {
                v.emplace_back(0,primes[i]);
                while(m%primes[i] == 0)
                {
                    ++v.back().first;
                    m/=primes[i];
                }
            }
        }
        if(m > 1)v.emplace_back(1,m);
        sort(v.begin(),v.end());
        vector<long long>ans;
        for(i=1;i<v.back().first;i++)
        {
            ans.emplace_back(v.back().second);
            n/=v.back().second;
        }
        ans.emplace_back(n);
        cout << (int)ans.size() << '\n';
        for(long long it : ans)cout << it << ' ';
        cout << '\n';
    }
    return 0;
}