#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    bool flag;
    int i,k,l,r,n,a[200005],b[200005];
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    while(k--)
    {
        for(i=1;i<=n;i++)b[i]=0;
        for(i=1;i<=n;i++)
        {
            l=max(1,i-a[i]);
            r=min(n+1,i+a[i]+1);
            ++b[l],--b[r];
        }
        for(i=2;i<=n;i++)b[i]+=b[i-1];
        flag=false;
        for(i=1;i<=n;i++)
        {
            if(b[i] != n)
            {
                flag=true;
                break;
            }
        }
        for(i=1;i<=n;i++)a[i]=b[i];
        if(!flag)break;
    }
    for(i=1;i<=n;i++)cout << a[i] << ' ';
    return 0;
}
