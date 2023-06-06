#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    LL i,n,x,y,mn,mx,ans=0;
    cin >> n;
    for(i=1;i<=n;i++)ans+=i*(n-i+1);
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        if(x > y)swap(x,y);
        mn=min(x,n-y+1);
        mx=max(x,n-y+1)-1;
        ans-=mn*(mx+1);
    }
    cout << ans;
    return 0;
}
