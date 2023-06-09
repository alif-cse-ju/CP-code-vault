#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k,m,n,t,x,y;
    cin >> n >> k >> m >> t;
    while(t--)
    {
        cin >> x >> y;
        if(x == 1)
        {
            ++n;
            if(y <= k)++k;
        }
        else
        {
            if(y >= k)n=y;
            else n-=y,k-=y;
        }
        cout << n << ' ' << k << '\n';
    }
    return 0;