#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    LL i,n,a[85],ans=1000,cnt=0,cur=1000;
    bool buy[85],sell[85];
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i],buy[i]=sell[i]=true;
    for(i=1;i<n;i++)
    {
        if(a[i] >= a[i+1])buy[i]=sell[i+1]=false;
        else buy[i+1]=sell[i]=false;
    }
    for(i=1;i<=n;i++)
    {
        if(buy[i])cnt=cur/a[i],cur%=a[i];
        else if(sell[i])cur+=cnt*a[i],cnt=0,ans=max(ans,cur);
    }
    cout << ans;
    return 0;
}
