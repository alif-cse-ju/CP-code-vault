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
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int freq[72];
bool mark[72];
vector<int>primes;
ll dp[2][1 << 19],pw[M];
void Sieve()
    int i,j;
    primes.emplace_back(2);
    for(i=3;i<71;i+=2)
    {
        if(!mark[i])
        {
            primes.emplace_back(i);
            for(j=i*i;j<71;j+=2*i)mark[j]=1;
        }
    }
}
 void PreCal()
{
    pw[0]=1;
    for(int i=1;i<M;i++)pw[i]=(pw[i-1]*2)%mod;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt,curMask,i,j,mask,mx,n,pCnt,x;
    Sieve();
    PreCal();
    cin >> n;
    while(n--)cin >> x, ++freq[x];
    pCnt=(int)primes.size();
    dp[0][0]=1, mx=(1 << 19);
    for(i=1;i<71;i++)
    {
        curMask=0, x=i;
        for(j=0;j<pCnt;j++)
        {
            cnt=0;
            while(x%primes[j] == 0)++cnt, x/=primes[j];
            if(cnt & 1)curMask |= (1 << j);
        }
        for(mask=0;mask<mx;mask++)
        {
            dp[i%2][mask] = dp[(i%2)+1-2*(i%2)][mask]*pw[max(0,freq[i]-1)];
            if(freq[i])dp[i%2][mask] += dp[(i%2)+1-2*(i%2)][mask ^ curMask]*pw[freq[i]-1];
            dp[i%2][mask] %= mod;
        }
    }
    cout << (dp[0][0]+mod-1)%mod;
    return 0;
}