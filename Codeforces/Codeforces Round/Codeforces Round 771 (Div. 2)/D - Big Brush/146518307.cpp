#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;
const int sz = 1e3+2;
bool visited[sz][sz];
int a[sz][sz],ans[sz*sz][3],ansCnt,clr[6],m,n;
void Check(int x,int y)
    if(!x  ||  !y  ||  x+1 > n  ||  y+1 > m)return;
    if(visited[x][y])return;
    int cnt=0,i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            if(a[x+i][y+j] != -1)clr[cnt++]=a[x+i][y+j];
        }
    }
    if(!cnt)return;
    sort(clr,clr+cnt);
    if(clr[0] != clr[cnt-1])return;
    ++ansCnt;
    ans[ansCnt][0]=x;
    ans[ansCnt][1]=y;
    ans[ansCnt][2]=clr[0];
    visited[x][y]=1;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok=1;
    int i,j,k,x,y;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)cin >> a[i][j];
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)Check(i,j);
    }
    for(i=1;i<=ansCnt;i++)
    {
        x=ans[i][0], y=ans[i][1];
        a[x][y]=a[x][y+1]=a[x+1][y]=a[x+1][y+1]=-1;
        for(j=-1;j<2;j++)
        {
            for(k=-1;k<2;k++)Check(x+j,y+k);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)ok &= (a[i][j] == -1);
    }
    if(!ok)cout << "-1";
    else
    {
        cout << ansCnt << '\n';
        for(i=ansCnt;i;i--)cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << '\n';
    }
    return 0;
}