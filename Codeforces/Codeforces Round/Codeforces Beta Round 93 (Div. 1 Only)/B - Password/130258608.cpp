#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
const ll base1 = 191, base2 = 307;
const ll mod1 = 1000001011, mod2 = 1000009999;
ll pow1[ N ], pow2[ N ];
void PreCal()
    pow1[ 0 ] = pow2[ 0 ] = 1;
    for(int i = 1; i < N; i += 1)
    {
        pow1[ i ] = (pow1[ i - 1 ] * base1) % mod1;
        pow2[ i ] = (pow2[ i - 1 ] * base2) % mod2;
    }
struct PolyHash
     vector<pair<ll, ll>> h;
    PolyHash(string &s)
    {
        long long x = 0, y = 0;
        for(char ch : s)
        {
            x = (x * base1 + ch) % mod1;
            y = (y * base2 + ch) % mod2;
            h.emplace_back(x, y);
        }
    }
    pair<ll, ll> GetHash(int l, int r)
    {
        ll x = h[ r ].first;
        ll y = h[ r ].second;
        if( l == 0 ) return {x, y};
        x = (x - (h[ l - 1 ].first * pow1[ r - l + 1 ]) % mod1 + mod1) % mod1;
        y = (y - (h[ l - 1 ].second * pow2[ r - l + 1 ]) % mod2 + mod2) % mod2;
        return {x, y};
    }
};
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,j,l,len,m,mx=0,r;
    pair<ll,ll>pHash,sHash,subHash;
    cin >> s;
    PreCal();
    PolyHash a(s);
    len=(int)s.size();
    l=1,r=len-2;
    while(l <= r)
    {
        m=(l+r) >> 1;
        pHash=a.GetHash(0,m-1);
        for(j=2;j+m-1 < len;j++)
        {
            subHash=a.GetHash(j-1,j+m-2);
            if(pHash == subHash)break;
        }
        if(j+m-1 == len)r=m-1;
        else mx=m,l=m+1;
    }
    if(!mx)
    {
        cout << "Just a legend";
        return 0;
    }
    for(i=mx;i;i--)
    {
        pHash=a.GetHash(0,i-1);
        sHash=a.GetHash(len-i,len-1);
        if(pHash == sHash)
        {
            for(j=0;j<i;j++)cout << s[j];
            return 0;
        }
    }
    cout << "Just a legend";
    return 0;
}