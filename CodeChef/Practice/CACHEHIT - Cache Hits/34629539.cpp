#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,m,n,t,q,x,ans,cur;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> q;
        ans=cur=0;
        while(q--)
        {
            cin >> x;
            x=(x+m)/m;
            if(x != cur)++ans,cur=x;
        }
        cout << ans << '\n';
    }
    return 0;
}