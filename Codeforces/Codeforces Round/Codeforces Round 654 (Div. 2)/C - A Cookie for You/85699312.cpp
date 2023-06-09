#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int t;
    LL a,b,m,n,x;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> n >> m;
        if(a > b)
        {
            x=min(b,m);
            b-=x,m-=x;
        }
        else
        {
            x=min(a,m);
            a-=x,m-=x;
        }
        if(m > 0)cout << "NO\n";
        else
        {
            if(a+b >= n)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;