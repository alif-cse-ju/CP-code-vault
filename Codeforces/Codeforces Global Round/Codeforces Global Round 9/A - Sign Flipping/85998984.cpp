#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(i & 1)cout << abs(x) << ' ';
            else cout << abs(x)*(-1) << ' ';
        }
        cout << '\n';
    }
    return 0;