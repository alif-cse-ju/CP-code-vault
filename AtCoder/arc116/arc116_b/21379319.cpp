#include<bits/stdc++.h>

using namespace std;

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e5+5;
const int mod=998244353;

long long a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    long long ans=0,sum=0;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    for(i=n;i;i--)
    {
        ans=(ans+(sum+a[i])*a[i])%mod;
        sum=(sum*2ll+a[i])%mod;
    }
    cout << ans;
    return 0;
}
//