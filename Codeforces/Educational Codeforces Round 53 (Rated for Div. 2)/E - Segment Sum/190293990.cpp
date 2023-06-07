#pragma GCC optimize("Ofast")

#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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

const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;

int k,ln,d[20];
ll dp1[20][1030][2][2],dp2[20][1030][2][2],pw[22];

void PreCal()
{
    pw[0]=1;
    for(int i=1;i<=20;i++)pw[i]=(pw[i-1]*10)%mod;
}

ll DP1(int i,int mask,bool choto,bool nichi)
{
    if(i > ln)return nichi;
    ll &ans=dp1[i][mask][choto][nichi];
    if(ans != -1)return ans;
    ans=0;
    if(choto)
    {
        for(int j=0;j<10;j++)
        {
            int nMask=mask;
            if(nichi  ||  j)nMask |= (1 << j);
            if(__builtin_popcount(nMask) <= k)
            {
                ans += DP1(i+1,nMask,1,nichi|(j > 0));
                if(ans >= mod)ans -= mod;
            }
        }
    }
    else
    {
        for(int j=0;j<d[i];j++)
        {
            int nMask=mask;
            if(nichi  ||  j)nMask |= (1 << j);
            if(__builtin_popcount(nMask) <= k)
            {
                ans += DP1(i+1,nMask,1,nichi|(j > 0));
                if(ans >= mod)ans -= mod;
            }
        }
        int nMask=mask;
        if(nichi  ||  d[i])nMask |= (1 << d[i]);
        if(__builtin_popcount(nMask) <= k)
        {
            ans += DP1(i+1,nMask,0,nichi|(d[i] > 0));
            if(ans >= mod)ans -= mod;
        }
    }
    return ans;
}

ll DP2(int i,int mask,bool choto,bool nichi)
{
    if(i > ln)return 0;
    ll &ans=dp2[i][mask][choto][nichi];
    if(ans != -1)return ans;
    ans=0;
    if(choto)
    {
        for(int j=0;j<10;j++)
        {
            int nMask=mask;
            if(nichi  ||  j)nMask |= (1 << j);
            if(__builtin_popcount(nMask) <= k)
            {
                ll tmp=(j*pw[ln-i]) % mod;
                tmp=(tmp*DP1(i+1,nMask,1,nichi|(j > 0))) % mod;
                tmp += DP2(i+1,nMask,1,nichi|(j > 0));
                if(tmp >= mod)tmp -= mod;
                ans += tmp;
                if(ans >= mod)ans -= mod;
            }
        }
    }
    else
    {
        for(int j=0;j<d[i];j++)
        {
            int nMask=mask;
            if(nichi  ||  j)nMask |= (1 << j);
            if(__builtin_popcount(nMask) <= k)
            {
                ll tmp=(j*pw[ln-i]) % mod;
                tmp=(tmp*DP1(i+1,nMask,1,nichi|(j > 0))) % mod;
                tmp += DP2(i+1,nMask,1,nichi|(j > 0));
                if(tmp >= mod)tmp -= mod;
                ans += tmp;
                if(ans >= mod)ans -= mod;
            }
        }
        int nMask=mask;
        if(nichi  ||  d[i])nMask |= (1 << d[i]);
        if(__builtin_popcount(nMask) <= k)
        {
            ll tmp=(d[i]*pw[ln-i]) % mod;
            tmp=(tmp*DP1(i+1,nMask,0,nichi|(d[i] > 0))) % mod;
            tmp += DP2(i+1,nMask,0,nichi|(d[i] > 0));
            if(tmp >= mod)tmp -= mod;
            ans += tmp;
            if(ans >= mod)ans -= mod;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    ll l,r;cin >> l >> r >> k, --l;
    string a=to_string(l), b=to_string(r);
    ln=(int)b.size();
    while((int)a.size() < ln)a="0"+a;
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    for(int i=1;i<=ln;i++)d[i]=a[i-1]-'0';
    ll L=DP2(1,0,0,0);

    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    for(int i=1;i<=ln;i++)d[i]=b[i-1]-'0';
    ll R=DP2(1,0,0,0);

    cout << ((R-L)%mod + mod) % mod;
    return 0;
}