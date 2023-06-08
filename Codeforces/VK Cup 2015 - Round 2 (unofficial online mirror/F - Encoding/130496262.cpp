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
const ll base1 = 611953, base2 = 611957;
const ll mod1 = 1000001011, mod2 = 1000009999;
ll pow1[ M ], pow2[ M ];
void PreCal()
    pow1[ 0 ] = pow2[ 0 ] = 1;
    for(int i = 1; i < M; i += 1)
    {
        pow1[ i ] = (pow1[ i - 1 ] * base1) % mod1;
        pow2[ i ] = (pow2[ i - 1 ] * base2) % mod2;
    }
struct PolyHash
     vector<pair<ll, ll>> h;
    PolyHash(vector<int>&v)
    {
        ll x = 0, y = 0;
        for(ll it : v)
        {
            x = (x * base1 + it) % mod1;
            y = (y * base2 + it) % mod2;
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
    string a,b;
    int i,j,la,lb,x;
    vector<int>ans,va,vb;
    set<int>apos[26],bpos[26];
    PreCal();
    cin >> la >> lb >> a >> b;
    for(i=0;i<la;i++)
    {
        if(apos[a[i]-'a'].empty())va.emplace_back(0);
        else va.emplace_back(i-*(--apos[a[i]-'a'].end()));
        apos[a[i]-'a'].insert(i);
    }
    for(i=0;i<lb;i++)
    {
        if(bpos[b[i]-'a'].empty())vb.emplace_back(0);
        else vb.emplace_back(i-*(--bpos[b[i]-'a'].end()));
        bpos[b[i]-'a'].insert(i);
    }
    PolyHash aHash(va),bHash(vb);
    pair<ll,ll>aNeed,bNeed=bHash.GetHash(0,lb-1);
    for(i=0;i+lb<=la;i++)
    {
        set<char>cnt[26];
        aNeed=aHash.GetHash(i,i+lb-1);
        for(j=0;j<26;j++)
        {
            if(!apos[j].empty())
            {
                auto it=apos[j].lower_bound(i);
                if(it == apos[j].end())continue;
                x=*(it);
                if(x >= i  &&  x < i+lb)
                {
                    if(a[x] != b[x-i])
                    {
                        cnt[a[x]-'a'].insert(b[x-i]);
                        cnt[b[x-i]-'a'].insert(a[x]);
                    }
                    ll y=va[x];
                    aNeed.first = (aNeed.first - (y * pow1[ lb - (x - i) -1 ]) % mod1 + mod1) % mod1;
                    aNeed.second = (aNeed.second - (y * pow2[ lb - (x - i) -1 ]) % mod2 + mod2) % mod2;
                }
            }
        }
        for(j=0;j<26;j++)
        {
            if((int)cnt[j].size() > 1)break;
        }
        if(j < 26)continue;
        if(aNeed == bNeed)ans.emplace_back(i+1);
    }
    cout << (int)ans.size() << '\n';
    for(int it : ans)cout << it << ' ';
    return 0;
}