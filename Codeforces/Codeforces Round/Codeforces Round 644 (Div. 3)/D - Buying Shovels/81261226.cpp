#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,k,n,t,x,y,rt,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        rt=sqrt(n),ans=INT_MAX;
        for(i=1;i<=rt;i++)
        {
            if(n%i == 0)
            {
                x=i,y=n/i;
                if(x <= k)ans=min(ans,y);
                if(y <= k)ans=min(ans,x);
            }
        }
        cout << ans << '\n';
    }
    return 0;