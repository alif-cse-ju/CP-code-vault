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

const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;

int q;
ll sum[M];
vector<int>values[M];
ordered_set<int>_times[M];
vector<pair<int,int>>queries[M],updates[M];

void Update(int i,int v)
{
    while(i <= q)
    {
        sum[i] += v;
        i += (i & -i);
    }
}

ll Query(int i)
{
    ll ans=0;
    while(i)
    {
        ans += sum[i];
        i -= (i & -i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m >> q;
    for(int i=1;i<=q;i++)
    {
        int t;cin >> t;
        if(t == 1)
        {
            int l,r,x;cin >> l >> r >> x;
            updates[l].emplace_back(i,x);
            updates[r+1].emplace_back(i,-x);
        }
        else if(t == 2)
        {
            int id,x;cin >> id >> x;
            values[id].emplace_back(x);
            _times[id].insert(i);
        }
        else
        {
            int ii,jj;cin >> ii >> jj;
            queries[jj].emplace_back(i,ii);
        }
    }
    vector<pair<int,ll>>ans;
    for(int j=1;j<=m;j++)
    {
        for(auto [i,v] : updates[j])Update(i,v);
        for(auto [id,i] : queries[j])
        {
            int choto=_times[i].order_of_key(id);
            if(!choto)ans.emplace_back(id,Query(id));
            else
            {
                int last=*(_times[i].find_by_order(choto-1));
                ans.emplace_back(id,values[i][choto-1]+Query(id)-Query(last));
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(auto [x,y] : ans)cout << y << '\n';
    return 0;
}