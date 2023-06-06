#include<bits/stdc++.h>

using namespace std;

const int N=2e5;

long long ans,a[N+2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=2;i<=n;i++)
    {
        if(a[i] < a[i-1])ans+=a[i-1]-a[i],a[i]=a[i-1];
    }
    cout << ans;
    return 0;
}