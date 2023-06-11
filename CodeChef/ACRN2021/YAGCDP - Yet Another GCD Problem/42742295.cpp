#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
bool mark[N];
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
            for(j=i*i;j<1000;j+=2*i)mark[j]=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Sieve();
    int i,n,t,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        map<int,int>cnt;
        for(i=0;i<n;i++)
        {
            cin >> x;
            for(int it : primes)
            {
                if(it*it > x)break;
                if(x%it == 0)
                {
                    ++cnt[it];
                    while(x%it == 0)x/=it;
                }
            }
            if(x > 1)++cnt[x];
        }
        ans=0;
        for(auto it : cnt)ans=max(ans,it.second);
        if(!ans)cout << "-1\n";
        else cout << n-ans << '\n';
    }
    return 0;
}
//