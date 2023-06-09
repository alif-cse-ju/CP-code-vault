#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,rt;
    cin >> n;
    if(n < 4)
    {
        for(i=1;i<=n;i++)cout << i << ' ';
    }
    else
    {
        rt=sqrt(n);
        if(rt*rt < n)++rt;
        for(i=rt-1;i>=0;i--)
        {
            for(j=1;j<=rt;j++)
            {
                if(i*rt+j <= n)cout << i*rt+j << ' ';
            }
        }
    }
    return 0;