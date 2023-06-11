#include<bits/stdc++.h>
using namespace std;
int ara[130];
void pre_cal()
{
    int i,j,x;
    ara[0]=-1;
    ara[1]=0;
    for(i=2;i<129;i++)
    {
        x=ara[i-1];
        for(j=i-2;j>0;j--)
        {
            if(ara[j] == x)break;
        }
        if(j == 0)ara[i]=0;
        else ara[i]=i-j-1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pre_cal();
    int i,t,n,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        x=ara[n],ans=0;
        for(i=1;i<=n;i++)
        {
            if(ara[i] == x)++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}