#include<bits/stdc++.h>

using namespace std;

const int N=3e5+5;

long long a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    long long ans=0;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        if(!(i & 1))a[i]=-a[i];
        a[i]+=a[i-1];
    }
    map<long long,int>cnt;
    cnt[0]=1;
    for(i=1;i<=n;i++)ans+=cnt[a[i]],++cnt[a[i]];
    cout << ans;
    return 0;
}