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
const int mod=1e9+7;
 const int mx=1e3+5;
 const ll base1=191,base2=307;
const ll mod1=1000001011,mod2=1000009999;
 ll pow1[mx],pow2[mx];
 void PreCal()
{
    pow1[0]=pow2[0]=1;
    for(int i=1;i<mx;i++)
    {
        pow1[i]=(pow1[i-1]*base1)%mod1;
        pow2[i]=(pow2[i-1]*base2)%mod2;
    }
}
 struct PolyHash
{
    vector<pair<ll,ll>>Hash;
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
 int dp[M];
bool ok[M];
string ss[M];
map<pair<ll,ll>,int>hashes[mx];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int l;cin >> l;
    string s;cin >> s;
    PolyHash sHash(s);
    int q;cin >> q;
    int mx=0;
    for(int i=1;i<=q;i++)
    {
        cin >> ss[i];
        string sss=ss[i];
        for(char &c : sss)
        {
            if(c <= 'Z')c='a'+c-'A';
        }
        reverse(sss.begin(),sss.end());
        PolyHash sssHash(sss);
        int lsss=(int)sss.size();
        mx=max(mx, lsss);
        hashes[lsss][sssHash.GetHash(0,lsss-1)]=i;
    }
    ok[l+1]=1;
    for(int i=l;i;i--)
    {
        for(int j=1;i+j-1<=l  &&  j<=mx;j++)
        {
            if(!ok[i+j])continue;
            pair<ll,ll>temp=sHash.GetHash(i-1,i+j-2);
            if(hashes[j].find(temp) != hashes[j].end())
            {
                ok[i]=1, dp[i]=hashes[j][temp];
                break;
            }
        }
    }
    for(int i=1;i<=l;i+=(int)ss[dp[i]].size())cout << ss[dp[i]] << ' ';
    return 0;
}