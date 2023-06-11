#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,t,x,y,ans;
    bool flag,mark[66];
    cin >> t;
    while(t--)
    {
        x=0;
        cin >> n;
        memset(mark,0,sizeof(mark));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                ++x;
                cin >> y;
                if((i > j)  &&  (x != y))mark[i]=1;
            }
        }
        ans=flag=0;
        for(i=n;i>1;i--)
        {
            if(mark[i] != flag)++ans,flag ^= 1;
        }
        cout << ans << '\n';
    }
    return 0;
}