#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
int ansMN[M],ansMX[M],q[M];
int main()
    FAST();
    int i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        set<int>mn,mx;
        for(i=1;i<=n;i++)
        {
            cin >> q[i];
            mn.insert(i);
            mx.insert(i);
        }
        ansMN[1]=ansMX[1]=q[1];
        for(i=1;i<=n;i++)
        {
            if(q[i] > q[i-1])mn.erase(q[i]),mx.erase(q[i]);
        }
        for(i=2;i<=n;i++)
        {
            if(q[i] > q[i-1])ansMN[i]=ansMX[i]=q[i];
            else
            {
                x=*(mn.begin());
                auto it=mx.lower_bound(q[i]);
                y=*(--it);
                ansMN[i]=x,ansMX[i]=y;
                mn.erase(x),mx.erase(y);
            }
        }
        for(i=1;i<=n;i++)cout << ansMN[i] << ' ';
        cout << '\n';
        for(i=1;i<=n;i++)cout << ansMX[i] << ' ';
        cout << '\n';
    }
    return 0;
}