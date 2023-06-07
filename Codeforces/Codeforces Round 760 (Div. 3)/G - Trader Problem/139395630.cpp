#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
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
const int N=2e6+5;
const int mod=1e9+7;
int cnt[M+M],par[M+M];
ll ans[M],tempAns[M+M];
ordered_set<int>ost[M+M];
int FindParent(int p)
    if(par[p] == p)return p;
    return par[p]=FindParent(par[p]);
ll Merge(const int& x,const int& y)
    ll curAns=tempAns[y];
    int cntX=cnt[x], cntY=cnt[y], len;
    for(int it1 : ost[x])
    {
        len=(int)ost[y].size();
        if(cntY)
        {
            int it2=*ost[y].find_by_order(len-cntY);
            if(it1 > it2)curAns += it1-it2;
        }
        ost[y].insert(it1);
    }
    ost[x].clear();
    len=(int)ost[y].size();
    for(int i=1;i<=cntX;i++)curAns += *ost[y].find_by_order(len-cntY-i);
    return curAns;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll curAns=0;
    int i,m,n,q,x;
    cin >> n >> m >> q;
    vector<tuple<int,int,int>>difs;
    vector<pair<int,int>>v, queries;
    for(i=1;i<=n;i++)cin >> x, v.emplace_back(x,i), par[i]=i, ++cnt[i], curAns += x, ost[i].insert(x), tempAns[i] += x;
    for(i=1;i<=m;i++)cin >> x, v.emplace_back(x,i+n), par[i+n]=i+n, ost[i+n].insert(x);
    for(i=1;i<=q;i++)cin >> x, queries.emplace_back(x,i);
    sort(v.begin(),v.end());
    sort(queries.begin(),queries.end());
    for(i=1;i<m+n;i++)difs.emplace_back(make_tuple(v[i].first-v[i-1].first, v[i-1].second, v[i].second));
    sort(difs.begin(),difs.end());
    reverse(difs.begin(),difs.end());
    for(auto [k,qid] : queries)
    {
        while(!difs.empty()  &&  get<0>(difs.back()) <= k)
        {
            auto [v,i1,i2]=difs.back(); difs.pop_back();
            i1=FindParent(i1), i2=FindParent(i2);
            if(i1 != i2)
            {
                if((int)ost[i1].size() > (int)ost[i2].size())swap(i1,i2);
                par[i1]=i2, curAns-=(tempAns[i1]+tempAns[i2]);
                tempAns[i2]=Merge(i1,i2), cnt[i2]+=cnt[i1], curAns+=tempAns[i2];
            }
        }
        ans[qid]=curAns;
    }
    for(i=1;i<=q;i++)cout << ans[i] << '\n';
    return 0;
}