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
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    bool ok;
    int colCnt,k,m,n,rowCnt,t,q,x,y;
    cin >> t;
    while(t--)
    {
        colCnt=rowCnt=1;
        map<int,bool>rowMark, colMark;
        cin >> n >> m >> k >> q;
        vector<pair<int,int>>queries;
        while(q--)cin >> x >> y, queries.emplace_back(x,y);
        ans=k;
        x=queries.back().first, y=queries.back().second;
        queries.pop_back(), rowMark[x]=colMark[y]=1;
        reverse(queries.begin(),queries.end());
        for(auto [x,y] : queries)
        {
            ok=1;
            if(rowMark.find(x) == rowMark.end())
            {
                ++rowCnt, rowMark[x]=1;
                if(colCnt != m)ans=(ans*k)%mod, ok=0;
            }
            if(colMark.find(y) == colMark.end())
            {
                ++colCnt, colMark[y]=1;
                if(ok  &&  rowCnt != n)ans=(ans*k)%mod;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}