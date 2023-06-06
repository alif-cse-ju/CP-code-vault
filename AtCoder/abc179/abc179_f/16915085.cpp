#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
long long a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long i,H,n,q,W,x,y,black;
    cin >> n >> q;
    for(i=1;i<=n;i++)a[i]=b[i]=n;
    H=W=n;
    black=(n-2)*(n-2);
    while(q--)
    {
        cin >> x >> y;
        if(x == 1)
        {
            if(y < W)
            {
              for(i=y;i<W;i++)b[i]=H;
              W=y;
            }
            black-=b[y]-2;
        }
        else
        {
            if(y < H)
            {
              for(i=y;i<H;i++)a[i]=W;
              H=y;
            }
            black-=a[y]-2;
        }
    }
    cout << black;
    return 0;
}
