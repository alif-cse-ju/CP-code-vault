#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;
int a[M],par[M];
vector<int>idx[M];
int FindPar(int n)
{
    if(par[n] == n)return n;
    return par[n]=FindPar(par[n]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,t,px,py;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i], par[i]=i;
        for(i=0;i<31;i++)
        {
            vector<int>v;
            for(j=1;j<=n;j++)
            {
                if((a[j] >> i) & 1)v.emplace_back(j);
            }
            for(j=1;j<(int)v.size();j++)
            {
                px=FindPar(v[j-1]), py=FindPar(v[j]);
                if(px != py)par[py]=px;
            }
        }
        for(i=1;i<=n;i++)idx[FindPar(i)].emplace_back(i);
        for(i=1;i<=n;i++)
        {
            if((int)idx[i].size() < 2)continue;
            vector<int>val;
            for(int it : idx[i])val.emplace_back(a[it]);
            sort(val.begin(),val.end());
            while(!val.empty())a[idx[i].back()]=val.back(), val.pop_back(), idx[i].pop_back();
        }
        for(i=2;i<=n  &&  a[i] >= a[i-1];i++);
        if(i <= n)cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}