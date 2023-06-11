#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
long long fib[55];
void PreCal()
{
    fib[1]=1;
    for(int i=2;i<51;i++)fib[i]=fib[i-1]+fib[i-2];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,t;
    PreCal();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<i;j++)cout << fib[j];
            cout << '\n';
        }
    }
    return 0;
}