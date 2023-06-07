#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e7+5;
const int mod=1e9+7;
ll cnt[N],dp[N];
vector<int>primes;
void PreCal()
    int i,j;
    bitset<N>sieve;
 sieve.flip();
 int finalBit = sqrt(sieve.size()) + 1;
 for(j=4;j<N;j+=2)sieve.reset(j);
 for(i=3;i<finalBit;i+=2)
    {
  if(sieve.test(i))
        {
            for(j=i*i;j<N;j+=2*i)sieve.reset(j);
        }
 }
 primes.emplace_back(2);
 for(i=3;i<N;i+=2)
    {
        if(sieve.test(i))primes.emplace_back(i);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,mx=0,n,x;
    PreCal();
    cin >> n;
    while(n--)cin >> x, ++cnt[x], mx=max(x,mx);
    for(int it : primes)
    {
        for(i=mx/it;i;i--)cnt[i] += cnt[i*it];
    }
    for(i=mx;i;i--)
    {
        dp[i]=cnt[i]*i;
        for(int it : primes)
        {
            if(1ll*i*it > mx)break;
            dp[i]=max(dp[i],(cnt[i]-cnt[i*it])*i+dp[i*it]);
        }
    }
    cout << dp[1];
    return 0;
}