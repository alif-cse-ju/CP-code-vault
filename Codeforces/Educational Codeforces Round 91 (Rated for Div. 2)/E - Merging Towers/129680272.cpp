#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
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