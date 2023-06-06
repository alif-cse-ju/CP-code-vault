#pragma GCC optimize("Ofast")

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

const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;

bool mark[18][26];

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    ll ans=0,tmp;
    int ache,bit,cnt,i,j,k,l,L,n;
    cin >> n >> L;
    for(i=0;i<n;i++)
    {
        cin >> s;
        for(char &c : s)mark[i][c-'a']=1;
    }
    l=(1 << n);
    for(i=1;i<l;i++)
    {
        bit=__builtin_popcount(i), cnt=0;
        for(j=0;j<26;j++)
        {
            ache=0;
            for(k=0;k<n;k++)
            {
                if((i >> k) & 1)ache += mark[k][j];
            }
            if(ache == bit)++cnt;
        }
        tmp=BigMod(cnt,L);
        if(bit & 1)ans += tmp;
        else ans -= tmp;
        ans %= mod;
    }
    if(ans < 0)ans += mod;
    cout << ans;
    return 0;
}