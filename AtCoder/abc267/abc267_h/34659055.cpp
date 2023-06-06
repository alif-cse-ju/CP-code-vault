#pragma GCC optimize("Ofast")

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

#include <atcoder/convolution>
using namespace atcoder;

int freq[12];
ll fact[N],invFact[N];

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
    for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i) % mod;
    invFact[N-1]=BigMod(fact[N-1], mod-2);
    for(int i=N-2;i>=0;i--)invFact[i]=(invFact[i+1]*(i+1)) % mod;
}

ll nCr(int n,int r)
{
    if(n < r)return 0;
    return (fact[n] * ((invFact[r] * invFact[n-r]) % mod)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int m,n;cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        int x;cin >> x;
        ++freq[x];
    }
    vector<ll>even(1,1), odd(1,0);
    for(int i=1;i<=10;i++)
    {
        vector<ll>curEven(i*freq[i]+1, 0), curOdd(i*freq[i]+1, 0);
        for(int j=0;j<=freq[i]  &&  i*j<=m;j+=2)curEven[i*j]=nCr(freq[i],j);
        for(int j=1;j<=freq[i]  &&  i*j<=m;j+=2)curOdd[i*j]=nCr(freq[i],j);

        vector<ll>evenEven = convolution<mod>(even, curEven);
        vector<ll>evenOdd = convolution<mod>(even, curOdd);
        vector<ll>oddEven = convolution<mod>(odd, curEven);
        vector<ll>oddOdd = convolution<mod>(odd, curOdd);

        int mx=max({(int)evenEven.size(), (int)evenOdd.size(), (int)oddEven.size(), (int)oddOdd.size()});

        while((int)odd.size() < mx)odd.emplace_back(0);
        while((int)even.size() < mx)even.emplace_back(0);

        for(int i=0;i<mx;i++)
        {
            odd[i] = evenOdd[i] + oddEven[i];
            if(odd[i] >= mod)odd[i] -= mod;

            even[i] = evenEven[i] + oddOdd[i];
            if(even[i] >= mod)even[i] -= mod;
        }
    }
    while((int)odd.size() <= m)odd.emplace_back(0);
    cout << odd[m];
    return 0;
}