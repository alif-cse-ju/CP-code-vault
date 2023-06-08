#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag;
    int i,n,t,u,U,d,D,l,L,r,R;
    cin >> t;
    while(t--)
    {
        cin >> n >> U >> R >> D >> L;
        flag=0;
        for(i=0;i<16;i++)
        {
            u=U,d=D,l=L,r=R;
            if((i >> 0) & 1)--u,--l;
            if((i >> 1) & 1)--u,--r;
            if((i >> 2) & 1)--d,--r;
            if((i >> 3) & 1)--d,--l;
            if((u >= 0  &&  u <= n-2)  &&  (d >= 0  &&  d <= n-2)  &&  (l >= 0  &&  l <= n-2)  &&  (r >= 0  &&  r <= n-2))
            {
                flag=1;
                break;
            }
        }
        if(flag)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;