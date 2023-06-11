#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int mod=1e9+7;
long long a[N][N],b[N][N],cc[N][N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag;
    long long temp;
    int c,i,j,r,t,x;
    cin >> t;
    while(t--)
    {
        cin >> r >> c >> x;
        for(i=0;i<x;i++)
        {
            for(j=0;j<x;j++)cc[i][j]=0;
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)cin >> a[i][j];
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)cin >> b[i][j];
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cc[i%x][j%x]+=a[i][j];
                cc[i%x][j%x]-=b[i][j];
            }
        }
        flag=1;
        for(i=1;i<x  &&  flag;i++)
        {
            temp=cc[i][0]-cc[0][0];
            for(j=1;j<x;j++)
            {
                if(temp != cc[i][j]-cc[0][j])
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
//