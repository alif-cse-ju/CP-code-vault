#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,t,cnt;
    cin >> t;
    while(t--)
    {
        cin >> k;
        if(k & 1)cnt=max(k,k-1+max(0,k-10));
        else cnt=max(k-1,k+max(0,k-9));
        for(i=1;i<=k;i++)
        {
            if(i & 1)
            {
                for(j=0;j<cnt-i;j++)cout << ' ';
                for(j=0;j<i;j++)cout << (char)('A'+j);
            }
            else
            {
                for(j=0;j<cnt-(i+max(0,i-9));j++)cout << ' ';
                for(j=1;j<=i;j++)cout << j;
            }
            cout << '\n';
        }
    }
    return 0;
}