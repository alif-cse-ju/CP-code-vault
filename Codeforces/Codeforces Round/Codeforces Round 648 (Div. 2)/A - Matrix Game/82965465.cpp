#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    bool r[55],c[55];
    int i,j,m,n,t,x,ans,cnt1,cnt2;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)r[i]=0;
        for(i=1;i<=m;i++)c[i]=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin >> x;
                if(x == 1)r[i]=c[j]=1;
            }
        }
        cnt1=cnt2=0;
        for(i=1;i<=n;i++)cnt1+=(r[i] == 0);
        for(i=1;i<=m;i++)cnt2+=(c[i] == 0);
        ans=min(cnt1,cnt2);
        if(ans & 1)cout << "Ashish\n";
        else cout << "Vivek\n";
    }
    return 0;