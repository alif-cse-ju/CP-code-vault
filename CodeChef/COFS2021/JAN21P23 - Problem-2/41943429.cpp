#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long i,j,l,x,y;
    cin >> x >> l;
    for(i=1,y=--x;i<=l;i++)
    {
        x+=i;
        for(j=x;j>y;j--)cout << j << ' ';
        cout << '\n';
        y+=i;
    }
    return 0;
}