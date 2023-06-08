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
int a[M],fr[M],rv[M];
int main()
    FAST();
    int i,n,x,y,ans=0,cnt=0,mx=0;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        if(a[i] > a[i-1])fr[i]=fr[i-1]+1;
        else fr[i]=1;
        mx=max(mx,fr[i]);
    }
    for(i=n;i;i--)
    {
        if(a[i] > a[i+1])rv[i]=rv[i+1]+1;
        else rv[i]=1;
        mx=max(mx,rv[i]);
    }
    for(i=1;i<=n;i++)cnt+=(fr[i] == mx)+(rv[i] == mx);
    for(i=2;i<n;i++)
    {
        x=fr[i],y=rv[i];
        if((x & 1)  &&  (y & 1))ans+=(x == y  &&  x == mx  &&  cnt == 2);
    }
    cout << ans;
    return 0;
}