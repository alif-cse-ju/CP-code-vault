#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
long long BigMod(long long val,long long pow)
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
vector<int>prime,divs[N];
void Sieve()
    int i,j;
    prime.emplace_back(2);
    for(i=2;i<N;i+=2)divs[i].emplace_back(2);
    for(i=3;i<N;i+=2)
    {
        if(divs[i].empty())
        {
            prime.emplace_back(i);
            for(j=i;j<N;j+=i)divs[j].emplace_back(i);
        }
    }
map<int,int>cnt[N];
multiset<int>mst[N];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Sieve();
    int i,n,q,x,y,z,temp,tempp;
    long long ans=1;
    cin >> n >> q;
    for(i=1;i<=n;i++)
    {
        cin >> x,y=x;
        for(int it : divs[y])
        {
            z=0;
            while(x%it == 0)x/=it,++z;
            cnt[i][it]=z,mst[it].insert(z);
        }
    }
    for(int it : prime)
    {
        if((int)mst[it].size() == n)ans=(ans*BigMod(it,*(mst[it].begin())))%mod;
    }
    while(q--)
    {
        cin >> i >> x,y=x;
        for(int it : divs[y])
        {
            z=0;
            while(x%it == 0)++z,x/=it;
            if((int)mst[it].size() == n)
            {
                temp=*(mst[it].begin());
                tempp=cnt[i][it];
                mst[it].erase(mst[it].find(tempp));
                cnt[i][it]+=z,mst[it].insert(tempp+z);
                if(*mst[it].begin() != temp)ans=(ans*BigMod(it,*(mst[it].begin())-temp))%mod;
            }
            else
            {
                if(cnt[i].find(it) != cnt[i].end())
                {
                    tempp=cnt[i][it];
                    mst[it].erase(mst[it].find(tempp));
                }
                else tempp=0;
                cnt[i][it]+=z,mst[it].insert(tempp+z);
                if((int)mst[it].size() == n)ans=(ans*BigMod(it,*(mst[it].begin())))%mod;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}