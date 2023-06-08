#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,l,m,mx,n,r,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << "1 " << n-1 << " 1";
        for(i=2;i<=n;i++)cout << ' ' << i;
        cout << endl;
        cin >> mx;
        l=2,r=n;
        while(l <= r)
        {
            m=(l+r) >> 1;
            cout << "1 " << m-1 << " 1";
            for(i=2;i<=m;i++)cout << ' ' << i;
            cout << endl;
            cin >> x;
            if(x == mx)r=m-1;
            else l=m+1;
        }
        x=r+1;
        cout << "1 " << n-1 << " " << x;
        for(i=1;i<=n;i++)
        {
            if(i != x)cout << ' ' << i;
        }
        cout << endl;
        cin >> mx;
        cout << "-1 " << mx << endl;
    }
    return 0;
}