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
const int M=2e5+5;
const int N=4e6+5;
const int mod=1e9+7;
set<int>towers[M];
int tNum[M],par[M];
int FindParent(int n)
    if(par[n] == n)return n;
    return par[n]=FindParent(par[n]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,m,n,x,y;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        par[i]=i;
        cin >> tNum[i];
        towers[tNum[i]].insert(i);
    }
    ans=n-1;
    for(i=1;i<n;i++)
    {
        if(towers[tNum[i]].find(i+1) != towers[tNum[i]].end())--ans;
    }
    cout << ans << '\n';
    for(i=1;i<m;i++)
    {
        cin >> x >> y;
        x=FindParent(x);
        y=FindParent(y);
        if((int)towers[x].size() < (int)towers[y].size())swap(x,y);
        par[y]=x;
        for(int it : towers[y])
        {
            if(towers[x].find(it-1) != towers[x].end())--ans;
            if(towers[x].find(it+1) != towers[x].end())--ans;
        }
        for(int it : towers[y])towers[x].insert(it);
        towers[y].clear();
        cout << ans << '\n';
    }
    return 0;
}
//https://codeforces.com/contest/1380/problem/E