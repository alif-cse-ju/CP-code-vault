#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll mn,mx,n,v;
    cin >> t;
    while(t--)
    {
        cin >> n >> v;
        mx=(n*(n-1))/2;
        mn=min(n-1,v), n=max(0ll,n-v-1), mn += ((n+1)*(n+2))/2-1;
        cout << mx << ' ' << mn << '\n';
    }
    return 0;
}