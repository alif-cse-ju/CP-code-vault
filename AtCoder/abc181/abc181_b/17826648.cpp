#include<bits/stdc++.h>

using namespace std;

long long F(long long x)
{
    return (x*(x+1LL))/2LL;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    long long x,y,ans=0;
    cin >> n;
    while(n--)
    {
        cin >> x >> y;
        ans+=F(y)-F(x-1);
    }
    cout << ans;
    return 0;
}