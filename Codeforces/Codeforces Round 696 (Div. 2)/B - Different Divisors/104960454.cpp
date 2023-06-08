#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int d,i,j,t;
    long long x,y;
    cin >> t;
    while(t--)
    {
        cin >> d;
        x=y=0;
        for(i=d+1; ;i++)
        {
            for(j=2;j*j<=i;j++)
            {
                if(i%j == 0)break;
            }
            if(j*j > i)
            {
                x=i;
                break;
            }
        }
        for(i=d+x; ;i++)
        {
            for(j=2;j*j<=i;j++)
            {
                if(i%j == 0)break;
            }
            if(j*j > i)
            {
                y=i;
                break;
            }
        }
        cout << min(x*y,x*x*x) << '\n';
    }
    return 0;
}