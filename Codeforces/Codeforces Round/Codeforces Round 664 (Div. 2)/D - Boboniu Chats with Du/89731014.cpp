#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL sum1[100002],sum2[100002];
int main()
    FAST();
    LL ans;
    int d,i,m,n,x;
    vector<int>a,b;
    cin >> n >> d >> m;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(x <= m)a.emplace_back(x);
        else b.emplace_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    n=a.size(),m=b.size();
    for(i=0;i<n;i++)sum1[i+1]=sum1[i]+a[i];
    for(i=0;i<m;i++)sum2[i+1]=sum2[i]+b[i];
    ans=sum1[n];
    for(i=1;i<=m  &&  i+(i-1)*d<=m+n;i++)ans=max(ans,sum2[i]+sum1[min(n,n+m-i-(i-1)*d)]);
    cout << ans;
    return 0;