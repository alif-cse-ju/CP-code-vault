#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
char a[N],b[N];
int fr[N],rv[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n,ans=-1;
    cin >> n >> m >> a+1 >> b+1;
    for(i=j=1;i <= n  &&  j <= m;i++)
    {
        if(a[i] == b[j])fr[j++]=i;
    }
    for(i=n,j=m;i  &&  j;i--)
    {
        if(a[i] == b[j])rv[j--]=i;
    }
    for(i=1;i<m;i++)ans=max(ans,rv[i+1]-fr[i]);
    cout << ans;
    return 0;