#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;
int range;
vector<ll>tmp,prime;
bool mark[M],segmentMark[N];
void Sieve()
{
    int i,j;
    range=sqrt(M);
    mark[0]=mark[1]=1;
    prime.emplace_back(2);
    for(i=4;i<M;i+=2)mark[i]=1;
    for(i=3; i<=range; i+=2)
    {
        if(mark[i] == 0)
        {
            prime.emplace_back(i);
            for(j=i*i; j<M; j+=2*i)mark[j]=1;
        }
    }
    j=range+(range%2)+1;
    for(i=j; i<M; i+=2)
    {
        if(!mark[i])prime.emplace_back(i);
    }
}
void SegmentSieve(ll a,ll b)
{
    ll i,j,base,araSize=b-a+1;
    memset(segmentMark,0,sizeof(segmentMark));
    for(i=0; prime[i]*prime[i]<=b; i++)
    {
        base=(a/prime[i])*prime[i];
        if(base<a)base+=prime[i];
        for(j=base; j<=b; j+=prime[i])segmentMark[j-a]=1;
        if(base<range)
        {
            if(!mark[base])segmentMark[base-a]=0;
        }
    }
    if(a == 1)segmentMark[0]=1;
    for(i=0; i<araSize; i++)
    {
        if(!segmentMark[i])tmp.emplace_back(i+a);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans=0,i,l,r;
    cin >> l >> r;
    Sieve();
    SegmentSieve(l,r);
    l=(int)tmp.size();
    for(i=1;i<l;i++)ans+=(tmp[i]-tmp[i-1] == 2);
    cout << ans;
    return 0;
}