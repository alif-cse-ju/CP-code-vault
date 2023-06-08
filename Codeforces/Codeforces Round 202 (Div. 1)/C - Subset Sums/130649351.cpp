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
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+9;
const int blockSize = 2500;
ll a[M],setSum[M],updates[M];
vector<int>light,heavy,sets[M];
int szh,szl,sz[M],hId[M],lId[M],hh[M/blockSize+5][M/blockSize+5],lh[M][M/blockSize+5];
void PreCal()
    int i,j,k,x;
    szh=(int)heavy.size();
    szl=(int)light.size();
    for(i=0;i<szh;i++)
    {
        hId[heavy[i]]=i+1;
        for(j=i+1;j<szh;j++)
        {
            for(k=0;k<sz[heavy[i]];k++)
            {
                x=sets[heavy[i]][k];
                auto it1=lower_bound(sets[heavy[j]].begin(),sets[heavy[j]].end(),x);
                auto it2=upper_bound(sets[heavy[j]].begin(),sets[heavy[j]].end(),x);
                if(it1 == it2)continue;
                ++hh[i+1][j+1],++hh[j+1][i+1];
            }
        }
    }
    for(i=0;i<szl;i++)
    {
        lId[light[i]]=i+1;
        for(j=0;j<szh;j++)
        {
            for(k=0;k<sz[light[i]];k++)
            {
                x=sets[light[i]][k];
                auto it1=lower_bound(sets[heavy[j]].begin(),sets[heavy[j]].end(),x);
                auto it2=upper_bound(sets[heavy[j]].begin(),sets[heavy[j]].end(),x);
                if(it1 == it2)continue;
                ++lh[i+1][j+1];
            }
        }
    }
}
 void Update(int k,ll v)
{
    if(sz[k] > blockSize)
    {
        updates[k] += v;
        setSum[k] += v*sz[k];
        for(int h : heavy)
        {
            if(h == k)continue;
            setSum[h] += v*hh[hId[k]][hId[h]];
        }
    }
    else
    {
        for(int i : sets[k])a[i] += v;
        for(int i=1;i<=szh;i++)setSum[heavy[i-1]] += lh[lId[k]][i]*v;
    }
}
 ll Query(int k)
{
    if(sz[k] <= blockSize)
    {
        setSum[k] = 0;
        for(int i : sets[k])setSum[k] += a[i];
        for(int i=1;i<=szh;i++)setSum[k] += lh[lId[k]][i]*updates[heavy[i-1]];
    }
    return setSum[k];
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,j,m,n,q,x;
    cin >> n >> m >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=m;i++)
    {
        cin >> sz[i];
        for(j=0;j<sz[i];j++)
        {
            cin >> x;
            setSum[i] += a[x];
            sets[i].emplace_back(x);
        }
        sort(sets[i].begin(),sets[i].end());
        if(sz[i] > blockSize)heavy.emplace_back(i);
        else light.emplace_back(i);
    }
    PreCal();
    while(q--)
    {
        cin >> s;
        if(s == "?")
        {
            cin >> x;
            cout << Query(x) << '\n';
        }
        else
        {
            cin >> i >> x;
            Update(i,x);
        }
    }
    return 0;
}