#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int clr[N];
bool mark[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int c,i,j,k,l,n,t,ans,cnt;
    cin >> t;
    while(t--)
    {
        c=0;
        ans=INT_MAX;
        cin >> n >> l;
        for(i=1;i<=n;i++)cin >> clr[i],c=max(c,clr[i]);
        for(i=1;i<=c;i++)
        {
            cnt=0;
            for(j=1;j<=n;j++)
            {
                if(clr[j] == i)mark[j]=1;
                else mark[j]=0;
            }
            for(j=1;j<=n;j++)
            {
                if(!mark[j])
                {
                    ++cnt;
                    for(k=j;k<=n  &&  k<=j+l-1;k++)mark[k]=1;
                }
            }
            ans=min(ans,cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}