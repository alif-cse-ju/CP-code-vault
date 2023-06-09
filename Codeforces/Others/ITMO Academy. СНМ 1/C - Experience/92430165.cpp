#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int>updates[N],childs[N];
int power[N],par[N],sz[N],Time[N];
int FindParent(int x)
    if(par[x] == x)return x;
    return par[x]=FindParent(par[x]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,m,n,x,y,ans;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        sz[i]=1;
        par[i]=i;
        childs[i].emplace_back(i);
    }
    while(m--)
    {
        cin >> s;
        if(s[0] == 'a')
        {
            cin >> x >> y;
            x=FindParent(x);
            if(updates[x].empty())updates[x].emplace_back(y);
            else updates[x].emplace_back(updates[x].back()+y);
        }
        else if(s[0] == 'j')
        {
            cin >> x >> y;
            x=FindParent(x);
            y=FindParent(y);
            if(x == y)continue;
            if(sz[x] >= sz[y])
            {
                sz[x]+=sz[y];
                for(int it : childs[y])
                {
                    par[it]=x;
                    childs[x].emplace_back(it);
                    if(!updates[y].empty())
                    {
                        if(!Time[it])power[it]+=updates[y].back();
                        else power[it]+=updates[y].back()-updates[y][Time[it]-1];
                    }
                    Time[it]=updates[x].size();
                }
                childs[y].clear();
                updates[y].clear();
            }
            else
            {
                sz[y]+=sz[x];
                for(int it : childs[x])
                {
                    par[it]=y;
                    childs[y].emplace_back(it);
                    if(!updates[x].empty())
                    {
                        if(!Time[it])power[it]+=updates[x].back();
                        else power[it]+=updates[x].back()-updates[x][Time[it]-1];
                    }
                    Time[it]=updates[y].size();
                }
                childs[x].clear();
                updates[x].clear();
            }
        }
        else
        {
            cin >> x;
            ans=power[x];
            y=FindParent(x);
            if(!updates[y].empty())
            {
                if(!Time[x])ans+=updates[y].back();
                else ans+=updates[y].back()-updates[y][Time[x]-1];
            }
            cout << ans << '\n';
        }
    }
    return 0;
}