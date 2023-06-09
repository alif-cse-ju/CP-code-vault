#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N];
bool mark[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,m,n,t,gcd,mx,maxGCD,pos;
    cin >> t;
    while(t--)
    {
        cin >> n;
        maxGCD=0;
        for(i=1;i<=n;i++)
        {
            mark[i]=0;
            cin >> a[i];
            if(a[i] > maxGCD)
            {
                pos=i;
                maxGCD=a[i];
            }
        }
        m=n-1;
        mark[pos]=1;
        cout << maxGCD;
        while(m--)
        {
            mx=0;
            for(i=1;i<=n;i++)
            {
               if(mark[i])continue;
               gcd=__gcd(maxGCD,a[i]);
               if(gcd > mx)
               {
                   pos=i;
                   mx=gcd;
               }
            }
            maxGCD=mx;
            mark[pos]=1;
            cout << ' ' << a[pos];
        }
        cout << '\n';
    }
    return 0;
}