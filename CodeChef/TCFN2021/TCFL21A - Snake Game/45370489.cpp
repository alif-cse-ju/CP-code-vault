#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M];
int main()
{
    FAST();
    int i,k,t;
    long long m,x,xx,y,yy,sum;
    cin >> t;
    while(t--)
    {
        cin >> k >> m;
        xx=yy=sum=0;
        for(i=1;i<=k;i++)cin >> a[i];
        for(i=1;i<=k;i++)
        {
            x=a[i];
            cin >> y;
            sum+=abs(xx-x)+abs(yy-y);
            xx=x,yy=y;
        }
        cout << (sum < m ? "YES\n" : "NO\n");
    }
    return 0;
}