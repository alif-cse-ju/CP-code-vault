#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
const ll base1=191,base2=307;
const ll mod1=1000001011,mod2=1000009999;
ll pow1[N+2],pow2[N+2];
void PreCal()
    pow1[0]=pow2[0]=1;
    for(int i=1;i<N;i++)
    {
        pow1[i]=(pow1[i-1]*base1)%mod1;
        pow2[i]=(pow2[i-1]*base2)%mod2;
    }
 struct PolyHash
{
    vector<pair<ll,ll> >Hash;
     //Polyhash(string &s): a constructor, makes the hash of string S
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
     // getHash(int l, int r): gives the hash value of the substring S[l, r]
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
 string s[M],ss[M];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int m,n,x;cin >> n >> m;
    map<pair<ll,ll>,priority_queue<int>>pals_cnt, non_pals_cnt;
    map<pair<ll,ll>,pair<ll,ll>>for_and_rev_hash_pair_for_nonpals;
     ll ans=0;
     for(int i=0;i<n;i++)
    {
        cin >> s[i] >> x, ss[i]=s[i];
        reverse(ss[i].begin(), ss[i].end());
        PolyHash fHash(s[i]), rHash(ss[i]);
         int l=(int)s[i].size();
        pair<ll,ll>forH=fHash.GetHash(0,l-1);
        pair<ll,ll>revH=rHash.GetHash(0,l-1);
        if(forH != revH)for_and_rev_hash_pair_for_nonpals[forH]=revH, non_pals_cnt[forH].emplace(x);
        else pals_cnt[forH].emplace(x);
    }
     for(auto [forH,revH] : for_and_rev_hash_pair_for_nonpals)
    {
        while(!non_pals_cnt[forH].empty()  &&  !non_pals_cnt[revH].empty())
        {
            int x=non_pals_cnt[forH].top(); non_pals_cnt[forH].pop();
            int y=non_pals_cnt[revH].top(); non_pals_cnt[revH].pop();
             if(x+y > 0)ans += x+y;
            else break;
        }
    }
     int _max=0;
    for(auto [forH,pq] : pals_cnt)
    {
        while((int)pq.size() > 1)
        {
            int x=pq.top(); pq.pop();
            int y=pq.top(); pq.pop();
              if(x+y < 0)
            {
                pq.emplace(x), pq.emplace(y);
                break;
            }
             ans += x+y;
            if(y < 0)_max=max(_max, -y);
        }
         if(!pq.empty())_max=max(_max, pq.top());
    }
     cout << ans+_max;
    return 0;
}