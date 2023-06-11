#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long n,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n;
        --n;
        x=n/4;
        x=((x*(x+1LL))/2LL)*4LL;
        y=n/6;
        y=((y*(y+1LL))/2LL)*6LL;
        z=n/12;
        z=((z*(z+1LL))/2LL)*12;
        cout << x+y-z << '\n';
    }
    return 0;
}
//