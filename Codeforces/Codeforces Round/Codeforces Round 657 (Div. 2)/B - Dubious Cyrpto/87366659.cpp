#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    LL i,l,r,t,m,n,x;
    cin >> t;
    while(t--)
    {
        cin >> l >> r >> m;
        for(i=l;i<=r;i++)
        {
            x=max(1LL,m/i)*i;
            if(x > m)
            {
                x-=m;
                if(x <= r-l)
                {
                    cout << i << ' ' << l << ' ' << l+x << '\n';
                    break;
                }
            }
            else
            {
                x=m-x;
                if(x <= (r-l))
                {
                    cout << i << ' ' << l+x << ' ' << l << '\n';
                    break;
                }
                x=i-x;
                if(x <= (r-l))
                {
                    cout << i << ' ' << l << ' ' << l+x << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}