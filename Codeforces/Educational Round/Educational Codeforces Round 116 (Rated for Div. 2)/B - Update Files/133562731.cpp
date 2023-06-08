#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll ans,cnt,cur,k,n;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ans=0, cnt=cur=1;
        while(cnt < n  &&  cur < k)++ans, cnt += cur, cur *= 2;
        n=max(0ll,n-cur);
        ans += (n+k-1)/k;
        cout << ans << '\n';
    }
    return 0;