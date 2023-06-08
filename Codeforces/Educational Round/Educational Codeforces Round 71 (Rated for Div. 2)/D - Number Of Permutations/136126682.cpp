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
const int M=3e5+5;
const int N=1e6+5;
const int mod=998244353;
ll fact[M];
pair<int,int>a[M];
int freqX[M],freqY[M];
void Fact()
    fact[0]=1;
    for(int i=1;i<M;i++)fact[i]=(fact[i-1]*i)%mod;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans,tmp;
    int cnt,i,n,x,y;
    Fact();
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x >> y;
        a[i]={x,y}, ++freqX[x], ++freqY[y];
    }
    ans=fact[n];
    for(i=tmp=1;i<=n;i++)tmp=(tmp*fact[freqX[i]])%mod;
    ans=(ans-tmp)%mod;
    for(i=tmp=1;i<=n;i++)tmp=(tmp*fact[freqY[i]])%mod;
    ans=(ans-tmp)%mod;
    sort(a+1,a+n+1);
    for(i=1,cnt=0;i<=n;i++)cnt += (a[i].second >= a[i-1].second);
    if(cnt == n)
    {
        cnt=0, tmp=1;
        for(i=1;i<=n;i++)
        {
            if(a[i] == a[i-1])++cnt;
            else tmp=(tmp*fact[cnt])%mod, cnt=1;
        }
        tmp=(tmp*fact[cnt])%mod;
        ans=(ans+tmp)%mod;
    }
    if(ans < 0)ans += mod;
    cout << ans;
    return 0;
}