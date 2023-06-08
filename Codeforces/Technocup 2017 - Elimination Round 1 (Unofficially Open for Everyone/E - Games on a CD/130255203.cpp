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
{
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
    int i,j,k,n,q,x;
    pair<ll,ll>need;
    PreCal();
    cin >> n >> k >> s >> q;
    s += s;
    PolyHash a(s);
    map<pair<ll,ll>,int>mp;
    for(i=1;i<=q;i++)
    {
        cin >> s;
        PolyHash b(s);
        need=b.GetHash(0,k-1);
        mp[need]=i;
    }
    for(i=1;i<=k;i++)
    {
        set<int>st;
        vector<int>v;
        for(j=i,q=n;q;q--,j+=k)
        {
            need=a.GetHash(j-1,j+k-2);
            if(mp.find(need) != mp.end())
            {
                x=mp[need];
                st.insert(x);
                v.emplace_back(x);
            }
        }
        if((int)st.size() == n)
        {
            cout << "YES\n";
            for(int it : v)cout << it << ' ';
            return 0;
        }
    }
    cout << "NO";
    return 0;
}