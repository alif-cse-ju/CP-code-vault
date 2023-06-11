#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N = 1e5 + 5;
const LL base1 = 191, base2 = 307;
const LL mod1 = 1000001011, mod2 = 1000009999;
LL pow1[ N ], pow2[ N ];
struct PolyHash
{
    vector<pair<LL, LL> > h;
    PolyHash(string &s)
    {
        LL x = 0, y = 0;
        for(char ch : s)
        {
            x = (x * base1 + ch) % mod1;
            y = (y * base2 + ch) % mod2;
            h.push_back({x, y});
        }
    }
    pair<LL, LL> getHash(int l, int r)
    {
        LL x = h[ r ].first;
        LL y = h[ r ].second;
        if( l == 0 )return {x, y};
        x = (x - (h[ l - 1 ].first * pow1[ r - l + 1 ]) % mod1 + mod1) % mod1;
        y = (y - (h[ l - 1 ].second * pow2[ r - l + 1 ]) % mod2 + mod2) % mod2;
        return {x, y};
    }
};
int main()
{
    FAST();
    pow1[ 0 ] = pow2[ 0 ] = 1;
    for(int i = 1; i < N; i += 1) {
        pow1[ i ] = (pow1[ i - 1 ] * base1) % mod1;
        pow2[ i ] = (pow2[ i - 1 ] * base2) % mod2;
    }
    string s;
    int i,l,t,ans;
    pair<LL,LL>x1,x2,y1,y2;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> s;
        PolyHash a(s);
        l = (int)s.size();
        for(i = 1; i < l-2; i += 2)
        {
            x1 = a.getHash(0,i/2);
            x2 = a.getHash(i/2+1,i);
            y1 = a.getHash(i+1,i+(l-i)/2);
            y2 = a.getHash(i+(l-i)/2+1,l-1);
            if(x1 == x2  &&  y1 == y2)++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}