#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int b[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    bool valid;
    int i,k,m,n,t,x,cnt,rem;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> m;
        for(i=1;i<=n;i++)b[i]=0;
        for(i=1;i<=m;i++)
        {
            cin >> x;
            b[x]=1;
        }
        rem=(n-m);
        if(rem == 0)cout << "YES\n";
        else if(rem%(k-1) > 0)cout << "NO\n";
        else
        {
            cnt=valid=0;
            for(i=1;i<=n;i++)
            {
                if(!b[i])++cnt;
                else valid |= (cnt >= k/2  &&  rem-cnt >= k/2);
            }
            cout << (valid ? "YES\n" : "NO\n");
        }
    }
    return 0;
}