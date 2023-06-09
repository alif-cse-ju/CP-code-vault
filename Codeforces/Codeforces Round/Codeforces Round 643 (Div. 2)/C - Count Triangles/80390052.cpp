#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL ans,cnt[1000005];
int main()
    FAST();
    int i,a,b,c,d,mx;
    cin >> a >> b >> c >> d;
    for(i=a;i<=b;i++)++cnt[i+b],--cnt[i+c+1];
    mx=c+d;
    for(i=1;i<=mx;i++)cnt[i]+=cnt[i-1];
    for(i=max(a+b,c+1);i<=mx;i++)ans+=cnt[i]*(min(i-1,d)-c+1);
    cout << ans;
    return 0;