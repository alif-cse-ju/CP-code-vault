#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int dist[10][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,n,ans=0,cnt;
    cin >> n >> k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)cin >> dist[i][j];
    }
    vector<int>v;
    for(i=2;i<=n;i++)v.emplace_back(i);
    do
    {
        cnt=0;
        for(i=1;i<n-1;i++)cnt+=dist[v[i]][v[i-1]];
        cnt+=dist[1][v[0]]+dist[1][v.back()];
        if(cnt == k)++ans;
    }
    while(next_permutation(v.begin(),v.end()));
    cout << ans;
    return 0;
}
