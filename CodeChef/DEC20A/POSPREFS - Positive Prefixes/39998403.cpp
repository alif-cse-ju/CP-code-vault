#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(n & 1)
        {
            if(n == k)
            {
                for(i=1;i<=n;i++)cout << i << ' ';
            }
            else if(k <= n/2)
            {
                j=2*k;
                for(i=1;i<=n;i++)
                {
                    if(i%2 == 0  &&  i <= j)cout << i << ' ';
                    else cout << -i << ' ';
                }
            }
            else
            {
                j=2*(n-k);
                for(i=1;i<=n;i++)
                {
                    if(i%2 == 0  &&  i <= j)cout << -i << ' ';
                    else cout << i << ' ';
                }
            }
        }
        else
        {
            if(k >= n/2)
            {
                j=(n-k)*2;
                for(i=1;i<=n;i++)
                {
                    if(i%2 == 0  &&  i <= j)cout << -i << ' ';
                    else cout << i << ' ';
                }
            }
            else
            {
                j=k*2;
                for(i=1;i<=n;i++)
                {
                    if(i%2 == 0  &&  i <= j)cout << i << ' ';
                    else cout << -i << ' ';
                }
            }
        }
        cout << '\n';
    }
    return 0;
}