#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,t,n,k,h[150],cnt;
    h[0]=0;
    cin >> t;
    for(i=1; i<=t; i++)
    {
        cnt=0;
        cin >> n >> k;
        for(j=1; j<=n; j++)
        {
            cin >> h[j];
            if(h[j]-h[j-1]>k)
            {
                cnt+=(h[j]-h[j-1])/k;
                if((h[j]-h[j-1])%k==0)
                {
                    cnt--;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}