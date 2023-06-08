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
int ans[502][502];
int main()
    FAST();
    int i,j,k,n,cnt,x;
    cin >> n;
    for(i=1;i<=n;i++)cin >> ans[i][i];
    for(i=1;i<=(n+1)/2;i++)
    {
        j=k=i;
        x=ans[i][i];
        cnt=ans[i][i]-1;
        while(cnt--)
        {
            if(k-1  &&  !ans[j][k-1])ans[j][--k]=x;
            else ans[++j][k]=x;
        }
        if(i == n-i+1)continue;
        j=k=n-i+1;
        x=ans[j][k];
        cnt=ans[j][k]-1;
        while(cnt--)
        {
            if(j+1 <= n  &&  !ans[j+1][k])ans[++j][k]=x;
            else ans[j][--k]=x;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}