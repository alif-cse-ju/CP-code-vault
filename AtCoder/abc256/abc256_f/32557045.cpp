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
const int mod=998244353;

const int sz = 350;

bool inQueue[M];
ll b[M],c[M],d[M];
int a[M],curVal[M];

void Process(const int& n)
{
    for(int i=1;i<=n;i++)
    {
        a[i]=curVal[i], inQueue[i]=0;

        b[i]=b[i-1]+a[i];
        if(b[i] >= mod)b[i] -= mod;

        c[i]=c[i-1]+b[i];
        if(c[i] >= mod)c[i] -= mod;

        d[i]=d[i-1]+c[i];
        if(d[i] >= mod)d[i] -= mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> curVal[i];
    Process(n);
    vector<int>pos;
    while(q--)
    {
        int t;cin >> t;
        if(t == 1)
        {
            int i,x;cin >> i >> x;
            curVal[i]=x;
            if(!inQueue[i])pos.emplace_back(i), inQueue[i]=1;
        }
        else
        {
            int i;cin >> i;
            ll ans=0;
            if((int)pos.size() >= sz)Process(n), pos.clear();
            else
            {
                for(int it : pos)
                {
                    if(it > i)continue;
                    ll tmp=i-it+1;
                    tmp=((tmp*(tmp+1))/2)%mod;
                    tmp = ((curVal[it]-a[it]) * tmp) % mod;
                    if(tmp < 0)tmp += mod;
                    ans += tmp;
                    if(ans >= mod)ans -= mod;
                }
            }
            ans += d[i];
            if(ans >= mod)ans -= mod;
            cout << ans << '\n';
        }
    }
    return 0;
}
