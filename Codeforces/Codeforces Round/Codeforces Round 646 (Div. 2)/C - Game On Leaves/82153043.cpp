#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<int>adj[1005];
int main()
    FAST();
    int i,n,t,x,y,rt;
    cin >> t;
    while(t--)
    {
        cin >> n >> rt;
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        if(n == 1  ||  adj[rt].size() == 1)cout << "Ayush\n";
        else
        {
            if(n%2 == 0)cout << "Ayush\n";
            else cout << "Ashish\n";
        }
    }
    return 0;