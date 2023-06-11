#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n;
    cin >> n;
    for(i=1;i<(n <<1);i++)
    {
        if(i <= n)
        {
            for(j=1;j<(n << 1);j++)
            {
                if(j <= n)cout << max(n-i+1,n-j+1) << ' ';
                else cout << max(j-n+1,n-i+1) << ' ';
            }
        }
        else
        {
            for(j=1;j<(n << 1);j++)
            {
                if(j <= n)cout << max(i-n+1,n-j+1) << ' ';
                else cout << max(j-n+1,i-n+1) << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}