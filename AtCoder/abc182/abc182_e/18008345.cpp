#include<bits/stdc++.h>

using namespace std;

const int N=1500+5;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int H,W;
bool block[N][N],vis1[N][N],vis2[N][N][4];

void DFS(int x,int y,int dir)
{
    vis1[x][y]=1;
    vis2[x][y][dir]=1;
    int xx=x+dx[dir],yy=y+dy[dir];
    if(xx >= 1  &&  xx <= H  &&  yy >= 1  &&  yy <= W)
    {
        if(!block[xx][yy]  &&  !vis2[xx][yy][dir])DFS(xx,yy,dir);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n,x,y,ans=0;
    cin >> H >> W >> n >> m;
    vector<pair<int,int>>v;
    for(i=0;i<n;i++)
    {
        cin >> x >> y;
        v.emplace_back(x,y);
    }
    for(i=0;i<m;i++)
    {
        cin >> x >> y;
        block[x][y]=1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<4;j++)DFS(v[i].first,v[i].second,j);
    }
    for(i=1;i<=H;i++)
    {
        for(j=1;j<=W;j++)ans+=vis1[i][j];
    }
    cout << ans;
    return 0;
}
