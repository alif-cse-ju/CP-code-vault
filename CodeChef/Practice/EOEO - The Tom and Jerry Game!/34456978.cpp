#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int t;
    LL m,n,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        m=n,x=1;
        while(m%2 == 0)m/=2,++x;
        x=((LL)1 << x);
        cout << n/x << '\n';
    }
    return 0;
}