#include<bits/stdc++.h>

using namespace std;

const int N=2e5;

int cnt[N+2],parent[N+2];

int FindParent(int n)
{
    if(parent[n] == n)return n;
    return parent[n]=FindParent(parent[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,m,n,x,y,ans=0;
    cin >> n >> m;
    for(i=1;i<=n;i++)parent[i]=i;
    while(m--)
    {
        cin >> x >> y;
        x=FindParent(x);
        y=FindParent(y);
        if(x != y)parent[y]=x;
    }
    for(i=1;i<=n;i++)
    {
        x=FindParent(i);
        ++cnt[x];
        ans=max(ans,cnt[x]);
    }
    cout << ans;
    return 0;
}
