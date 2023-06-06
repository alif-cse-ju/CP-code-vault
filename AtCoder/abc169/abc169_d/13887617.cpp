#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    LL i,n,x,y,ans=0;
    cin >> n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            x=0,y=1;
            while(n%i == 0)++x,n/=i;
            while(x >= y)
            {
                x-=y;
                ++y,++ans;
            }
        }
    }
    if(n > 1)++ans;
    cout << ans;
    return 0;
}
