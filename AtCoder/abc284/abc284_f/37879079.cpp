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

const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;

const ll base1=191,base2=307;
const ll mod1=1000001011,mod2=1000009999;

ll pow1[N],pow2[N];

void PreCal()
{
    pow1[0]=pow2[0]=1;
    for(int i=1;i<N;i++)
    {
        pow1[i]=(pow1[i-1]*base1)%mod1;
        pow2[i]=(pow2[i-1]*base2)%mod2;
    }
}

struct PolyHash
{
    vector<pair<ll,ll> >Hash;
    PolyHash(string &s)
    {
        ll x = 0, y = 0;
        for(char ch : s)
        {
            x = (x * base1 + ch) % mod1;
            y = (y * base2 + ch) % mod2;
            Hash.emplace_back(x, y);
        }
    }
    pair<ll,ll>GetHash(int l, int r)
    {
        ll x = Hash[ r ].first;
        ll y = Hash[ r ].second;
        if(l == 0)return {x, y};
        x = (x - (Hash[ l - 1 ].first * pow1[ r - l + 1 ]) % mod1 + mod1) % mod1;
        y = (y - (Hash[ l - 1 ].second * pow2[ r - l + 1 ]) % mod2 + mod2) % mod2;
        return {x, y};
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int l;cin >> l, l+=l;
    string s;cin >> s;
    string rs=s; reverse(rs.begin(),rs.end());
    PolyHash sHash(s),rHash(rs);
    if(sHash.GetHash(0,l/2-1) == rHash.GetHash(0,l/2-1))
    {
        for(int i=0;i<l/2;i++)cout << s[i];
        cout << '\n' << l/2;
        return 0;
    }
    for(int i=1;i<l/2;i++)
    {
        if(sHash.GetHash(0,i-1) == rHash.GetHash(l/2-i,l/2-1)  &&  sHash.GetHash(l-(l/2-i),l-1) == rHash.GetHash(l/2,l-i-1))
        {
            for(int j=0;j<i;j++)cout << s[j];
            for(int j=l-(l/2-i);j<l;j++)cout << s[j];
            cout << '\n' << i;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}