#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N],nxt[N],pos[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x,y,z,ans=0;
    cin >> n;
    nxt[0]=n+1;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        pos[i]=n+1;
    }
    for(i=n;i;i--)
    {
        nxt[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    x=y=0;
    for(z=1;z<=n;z++)
    {
        if(a[x] == a[z])
        {
            ans+=(a[y] != a[z]);
            y=z;
        }
        else if(a[y] == a[z])
        {
            ans+=(a[x] != a[z]);
            x=z;
        }
        else if(nxt[x] < nxt[y])x=z,++ans;
        else y=z,++ans;
    }
    cout << ans;
    return 0;
}
//