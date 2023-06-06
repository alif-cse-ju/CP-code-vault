#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;

int parent[N];
map<int,int>cnt[N];

int FindParent(int node)
{
    if(parent[node] == node)return node;
    return parent[node]=FindParent(parent[node]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,q,x,y,op;
    cin >> n >> q;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        ++cnt[i][x];
        parent[i]=i;
    }
    while(q--)
    {
        cin >> op >> x >> y;
        if(op == 1)
        {
            x=FindParent(x);
            y=FindParent(y);
            if(x != y)
            {
                if(cnt[x].size() >= cnt[y].size())
                {
                    parent[y]=x;
                    for(auto it : cnt[y])cnt[x][it.first]+=it.second;
                }
                else
                {
                    parent[x]=y;
                    for(auto it : cnt[x])cnt[y][it.first]+=it.second;
                }
            }
        }
        else
        {
            x=FindParent(x);
            cout << cnt[x][y] << '\n';
        }
    }
    return 0;
}
