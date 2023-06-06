#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    LL d,k,n,x;
    cin >> n >> k >> d;
    n=abs(n),x=n;
    n-=min(k,n/d)*d;
    k-=min(x/d,k);
    if(n <= abs(n-d))
    {
        if(k & 1)cout << abs(n-d);
        else cout << n;
    }
    else
    {
        --k,n-=d;
        if(k & 1)cout << abs(n+d);
        else cout << abs(n);
    }
    return 0;
}
