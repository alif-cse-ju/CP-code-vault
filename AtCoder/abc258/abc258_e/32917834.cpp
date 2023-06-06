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

int cur,n;
bool visited[M];
ordered_set<ll>ost;
ll dp[M],sum[M],w[M];

ll Check(ll x)
{
    if(!cur)
    {
        ll ghurbe=x/sum[n-1];
        ll ans=ghurbe*n;
        x -= sum[n-1]*ghurbe;
        if(!x)
        {
            cur=n-1;
            return ans;
        }
        int id=ost.order_of_key(x);
        ans += id+1, cur=id;
        return ans;
    }
    else
    {
        ll neyaJabe=sum[n-1]-sum[cur-1];
        if(x <= neyaJabe)
        {
            int id=ost.order_of_key(sum[cur-1]+x);
            ll ans=id-cur+1; cur=id;
            return ans;
        }
        else
        {
            ll ans=n-cur; x-=neyaJabe, cur=n-1;
            ll ghurbe=x/sum[n-1];
            ans += n*ghurbe;
            ll rem=x-sum[n-1]*ghurbe;
            if(!rem)return ans;
            int id=ost.order_of_key(rem);
            ans += id+1, cur=id;
            return ans;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; ll x; cin >> n >> q >> x;
    for(int i=0;i<n;i++)
    {
        cin >> w[i], sum[i]=w[i];
        if(i)sum[i] += sum[i-1];
        ost.insert(sum[i]);
    }
    deque<pair<ll,int>>vals;
    vector<ll>v1, v2;
    for(int i=0; ;i++)
    {
        if(visited[cur])
        {
            while(vals.front().second != cur)v1.emplace_back(vals.front().first), vals.pop_front();
            while(!vals.empty())v2.emplace_back(vals.front().first), vals.pop_front();
            break;
        }
        int id=cur;
        visited[id]=1, dp[id]=Check(x), vals.emplace_back(dp[id],id), cur=(cur+1)%n;
    }
    while(q--)
    {
        ll k;cin >> k, --k;
        if(k < (int)v1.size())cout << v1[k] << '\n';
        else cout << v2[(k-(int)v1.size())%(int)v2.size()] << '\n';
    }
    return 0;
}
