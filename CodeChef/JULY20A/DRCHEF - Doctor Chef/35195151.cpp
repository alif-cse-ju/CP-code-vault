#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    bool taken[100002];
    int i,n,t,x,y,ans,cur,pos,a[100002];
    cin >> t;
    while(t--)
    {
        cin >> n >> cur;
        for(i=1;i<=n;i++)cin >> a[i],taken[i]=false;
        sort(a+1,a+n+1);
        ans=n;
        while(true)
        {
            pos=lower_bound(a+1,a+n+1,cur)-a;
            if(pos > n)break;
            if(a[pos] == cur)
            {
                while(pos <= n  &&  a[pos] <= cur)cur=a[pos]*2,taken[pos++]=true;
            }
            else
            {
                if(pos > 1  &&  (a[pos-1]*2 >= a[pos]  ||  cur*2 < a[pos])  &&  !taken[pos-1])cur=a[pos-1]*2,taken
                else
                {
                    while(cur < a[pos])++ans,cur*=2;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}