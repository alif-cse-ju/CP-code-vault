#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+1;
const int N=2e5+5;
const int mod=1e9+7;
bool pos[101][101][10001];
void PreCal(int x,int y,int cost)
    if(x > 100  ||  y > 100  ||  cost > 10000)return;
    if(pos[x][y][cost])return;
    pos[x][y][cost]=1;
    PreCal(x,y+1,cost+x);
    PreCal(x+1,y,cost+y);
int main()
    FAST();
    int k,t,x,y;
    PreCal(1,1,0);
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> k;
        cout << (pos[x][y][k] ? "YES\n" : "NO\n");
    }
    return 0;
}