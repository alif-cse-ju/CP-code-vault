#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    FAST();
    int t;
    long long c,m,n,r,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> x;
        r=x%n;
        if(!r)r=n;
        if(r == n)c=x/n;
        else c=x/n+1;
        y=(r-1)*m+c;
        cout << y << '\n';
    }
    return 0;