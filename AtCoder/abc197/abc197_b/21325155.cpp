#include<bits/stdc++.h>

using namespace std;

#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;

int main()
{
    FAST();
    char s[102][102];
    int i,j,h,w,x,y,ans=1;
    cin >> h >> w >> x >> y;
    for(i=1;i<=h;i++)cin >> s[i]+1;
    for(i=x-1;i;i--)
    {
        if(s[i][y] == '.')++ans;
        else break;
    }
    for(i=x+1;i<=h;i++)
    {
        if(s[i][y] == '.')++ans;
        else break;
    }
    for(j=y-1;j;j--)
    {
        if(s[x][j] == '.')++ans;
        else break;
    }
    for(j=y+1;j<=w;j++)
    {
        if(s[x][j] == '.')++ans;
        else break;
    }
    cout << ans;
    return 0;
}
