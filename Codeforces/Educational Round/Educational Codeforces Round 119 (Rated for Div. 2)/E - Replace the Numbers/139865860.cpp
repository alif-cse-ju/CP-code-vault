#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int ans[M],par[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n=0,t,q,x,y;
    vector<tuple<int,int,int>>queries;
    cin >> q;
    while(q--)
    {
        cin >> t;
        if(t == 1)++n, cin >> x, queries.emplace_back(make_tuple(1,x,0));
        else
        {
            cin >> x >> y;
            if(n)queries.emplace_back(make_tuple(2,x,y));
        }
    }
    m=n;
    for(i=1;i<M;i++)par[i]=i;
    while(!queries.empty())
    {
        auto [t,x,y]=queries.back();
        queries.pop_back();
        if(t == 1)ans[m--]=par[x];
        else par[x]=par[y];
    }
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;