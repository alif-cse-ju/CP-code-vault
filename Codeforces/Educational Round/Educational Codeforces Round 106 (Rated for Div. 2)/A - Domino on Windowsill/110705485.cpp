#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
const int N=1e3+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int b,k1,k2,n,t,w,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n >> k1 >> k2 >> w >> b;
        z=abs(k1-k2)/2;
        x=min(k1,k2),y=n-max(k1,k2);
        w-=min(w,x+z),b-=min(b,y+z);
        if(!w && !b)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;