#include<bits/stdc++.h>
 using namespace std;
 const int N=2005;
const int MAX=1e6+5;
 int a[N],b[N],c[N],d[N],temp[MAX];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n,mx=0,ans=INT_MAX;
    cin >> n >> m;
    for(i=0;i<n;i++)cin >> a[i] >> b[i];
    for(i=0;i<m;i++)cin >> c[i] >> d[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i] <= c[j])temp[c[j]-a[i]]=max(temp[c[j]-a[i]],d[j]-b[i]+1);
        }
    }
    for(i=MAX-1;i>=0;i--)
    {
        mx=max(mx,temp[i]);
        ans=min(ans,mx+i);
    }
    cout << ans;
    return 0;
}