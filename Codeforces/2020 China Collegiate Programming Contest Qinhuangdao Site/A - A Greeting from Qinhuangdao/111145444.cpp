#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    FAST();
    int b,r,t,tc,x,y,z;
    cin >> t;
    for(tc=1;tc<=t;tc++)
    {
        cin >> r >> b;
        x=r*(r-1);
        y=(r+b)*(r+b-1);
        z=__gcd(x,y);
        cout << "Case #" << tc << ": " << (x/z) << '/' << y/z << '\n';
    }
    return 0;