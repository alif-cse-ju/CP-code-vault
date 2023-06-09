#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N];
int GetParent(int x)
    if(parent[x] == x)return x;
    return parent[x]=GetParent(parent[x]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,m,n,x,y;
    cin >> n >> m;
    for(i=1;i<=n;i++)parent[i]=i;
    while(m--)
    {
        cin >> s >> x >> y;
        x=GetParent(x);
        y=GetParent(y);
        if(s[0] == 'u')parent[x]=y;
        else
        {
            if(x == y)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;