#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int main()
{
    FAST();
    int t;
    long long m,r,x;
    cin >> t;
    while(t--)
    {
        cin >> x >> r >> m;
        r*=60,m*=60;
        if(min(r,x)+max(0ll,r-x)*2ll <= m)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}