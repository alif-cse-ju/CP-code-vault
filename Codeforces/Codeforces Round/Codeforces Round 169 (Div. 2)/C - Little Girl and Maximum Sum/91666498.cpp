#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N=2e5+5;
long long a[N],cnt[N];
int main()
    FAST();
    int i,n,q,l,r;
    long long ans=0;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    while(q--)
    {
        cin >> l >> r;
        ++cnt[l],--cnt[r+1];
    }
    for(i=2;i<=n;i++)cnt[i]+=cnt[i-1];
    sort(a+1,a+n+1);
    sort(cnt+1,cnt+n+1);
    for(i=n;i>0;i--)ans+=a[i]*cnt[i];
    cout << ans;
    return 0;