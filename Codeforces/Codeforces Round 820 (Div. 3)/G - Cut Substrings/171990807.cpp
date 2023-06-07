#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

const int sz = 505;

///Hash

const long long base1 = 191, base2 = 307;
const long long mod1 = 1000001011, mod2 = 1000009999;

long long pow1[ sz ], pow2[ sz ];

void PreCal()
{
    pow1[ 0 ] = pow2[ 0 ] = 1;
    for(int i = 1; i < sz; i += 1)
    {
        pow1[ i ] = (pow1[ i - 1 ] * base1) % mod1;
        pow2[ i ] = (pow2[ i - 1 ] * base2) % mod2;
    }
}

struct PolyHash
{

    vector<pair<long long, long long>> h;
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

///Hash

bool mark[sz];
ll dp[sz][sz];
int cnt[sz],szA,szB;

ll DP(int i,int ache)
{
    if(!ache)return (!cnt[i]);
    if(cnt[i] < ache)return 0;
    ll &ans=dp[i][ache];
    if(ans > -1)return ans;
    if(!mark[i])ans=DP(i+1,ache);
    else
    {
        ans = DP(i+szB,ache-1);
        for(int j=i+1;j<i+szB;j++)
        {
            if(mark[j])ans += DP(j+szB,ache-1);
        }
    }
    return ans%=mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int t;cin >> t;
    while(t--)
    {
        string a,b;cin >> a >> b;
        szA=(int)a.size(), szB=(int)b.size();
        if(szA < szB)cout << "0 1\n";
        else
        {
            PolyHash A(a), B(b);
            for(int i=0;i<=szA+2;i++)mark[i]=cnt[i]=0;
            pair<ll,ll>need = B.GetHash(0, szB-1);
            for(int i=szB;i<=szA;i++)cnt[i-szB+1]=mark[i-szB+1]=(need == A.GetHash(i-szB, i-1));
            for(int i=szA-szB;i;i--)
            {
                if(mark[i])cnt[i] += cnt[i+szB];
                else cnt[i] = cnt[i+1];
            }
            int ans=0;
            for(int i=1;i<=szA;i++)
            {
                if(mark[i])
                {
                    ++ans;
                    int l=i+szB-1, r=l;
                    for(int j=i;j<=l;j++)
                    {
                        if(mark[j])r=j+szB-1;
                    }
                    i=r;
                }
            }
            if(!ans)cout << "0 1\n";
            else
            {
                memset(dp,-1,sizeof(dp));
                cout << ans << ' ' << DP(1,ans) << '\n';
            }
        }
    }
    return 0;
}
