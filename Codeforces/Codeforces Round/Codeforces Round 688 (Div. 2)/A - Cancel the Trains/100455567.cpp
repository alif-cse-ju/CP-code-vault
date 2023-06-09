#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int m,n,t,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        bool mark[102]={0};
        while(n--)
        {
            cin >> x;
            mark[x]=1;
        }
        ans=0;
        while(m--)
        {
            cin >> x;
            if(mark[x])++ans;
        }
        cout << ans << '\n';
    }
    return 0;