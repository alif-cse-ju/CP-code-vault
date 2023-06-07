#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

ll fact[M];
bool visited[M];
int a[M],pos[M];

long long BigMod(long long val,long long pow)
{
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}

void PreCal()
{
    fact[0]=1;
    for(int i=1;i<M;i++)fact[i]=(fact[i-1]*i)%mod;
}

ll nCr(int n,int r)
{
    return (fact[n] * BigMod(fact[r]*fact[n-r], mod-2)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        visited[n]=0;
        for(int i=1;i<=n;i++)cin >> a[i], pos[a[i]]=i, visited[i-1]=0;
        ll ans=1;
        int l=pos[0], r=pos[0], mex;
        for(mex=0;l > 1  ||  r < n;mex++)
        {
            if(pos[mex] >= l  &&  pos[mex] <= r)ans=(ans * (r-l+1-mex)) % mod;
            else
            {
                if(pos[mex] < l)l=pos[mex];
                else r=pos[mex];
            }
            //cout << mex << ' ' << ans << '\n';
        }
        ans=(ans * fact[n-mex]) % mod;
        cout << ans << '\n';
    }
    return 0;
}
