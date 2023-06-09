#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
vector<int>oddPalindromes(string const& s)
    int i,j,l=0,r=-1,len=s.size();
    vector<int>v(len);
    for(i=0;i<len;i++)
    {
        if(i > r)j=1;
        else j=min(v[l+r-i],r-i+1);
        while(i-j >= 0  &&  i+j < len  &&  s[i-j] == s[i+j])j++;
        v[i]=j--;
        if(i+j > r)l=i-j,r=i+j;
    }
    return v;
const long long base1 = 191, base2 = 307;
const long long mod1 = 1000001011, mod2 = 1000009999;
long long pow1[ N ], pow2[ N ];
void PreCal()
    pow1[ 0 ] = pow2[ 0 ] = 1;
    for(int i = 1; i < N; i += 1)
    {
        pow1[ i ] = (pow1[ i - 1 ] * base1) % mod1;
        pow2[ i ] = (pow2[ i - 1 ] * base2) % mod2;
    }
struct PolyHash
     vector<pair<long long, long long>> h;
     // Polyhash(string &s): a constructor, makes the hash of string S
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
     // getHash(int l, int r): gives the hash value of the substring S[l, r]
    pair<long long, long long> GetHash(int l, int r)
    {
        long long x = h[ r ].first;
        long long y = h[ r ].second;
        if( l == 0 ) return {x, y};
        x = (x - (h[ l - 1 ].first * pow1[ r - l + 1 ]) % mod1 + mod1) % mod1;
        y = (y - (h[ l - 1 ].second * pow2[ r - l + 1 ]) % mod2 + mod2) % mod2;
        return {x, y};
    }
};
 set<pair<long long,long long>>st[N];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,j,l;
    long long ans=0;
    pair<long long,long long>temp;
    cin >> l >> s;
    PreCal();
    PolyHash h(s);
    vector<int>pals=oddPalindromes(s);
    for(i=0;i<l;i++)
    {
        for(j=pals[i];j>1;j--)
        {
            temp=h.GetHash(i-j+1,i+j-1);
            if(st[2*j-1].find(temp) != st[2*j-1].end())break;
            st[2*j-1].insert(temp);
        }
    }
    for(i=3;i<N;i+=2)
    {
        if(st[i].empty())break;
        ans+=(int)st[i].size();
    }
    cout << ans;
    return 0;
}