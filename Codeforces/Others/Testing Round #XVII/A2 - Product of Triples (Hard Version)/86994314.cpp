#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,j,k,n,x,cnt[10002]={0};
    cin >> n;
    for(i=1;i<31;i++)
    {
        for(j=i;j<=sqrt(n);j++)
        {
            for(k=j;k<=n;k++)
            {
                x=i*j*k;
                if(x <= n)++cnt[x];
                else break;
            }
        }
    }
    for(i=1;i<=n;i++)cout << cnt[i] << '\n';
    return 0;