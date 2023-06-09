#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    char ans[305][305];
    int i,j,k,n,t,x,y,cnt[302];
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        x=k/n,y=k%n;
        for(i=1;i<=n;i++)cnt[i]=x+(i <= y);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)ans[i][j]='0';
            j=i-1;
            while(cnt[i]--)
            {
                ans[i][j%n+1]='1';
                j++;
            }
        }
        x=k/n+(k%n > 0),y=k/n;
        cout << 2*(x-y)*(x-y) << '\n';
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)cout << ans[i][j];
            cout << '\n';
        }
    }
    return 0;