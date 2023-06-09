#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,j,n,t,xr,bitCnt[2],a[100002];
    cin >> t;
    while(t--)
    {
        xr=0;
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i],xr ^= a[i];
        if(xr == 0)cout << "DRAW\n";
        else
        {
            for(j=30;j>=0;j--)
            {
                if((xr >> j) & 1)
                {
                    bitCnt[0]=bitCnt[1]=0;
                    for(i=1;i<=n;i++)++bitCnt[(a[i] >> j) & 1];
                    if(bitCnt[1]%4 == 3  &&  bitCnt[0]%2 == 0)cout << "LOSE\n";
                    else cout << "WIN\n";
                    break;
                }
            }
        }
    }
    return 0;