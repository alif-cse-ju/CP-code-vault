#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,x;
    long long ans=0,cnt=0,mx=0,sum=0;
    cin >> n;
    while(n--)
    {
        cin >> x;
        sum+=x;
        mx=max(mx,sum);
        ans=max(ans,cnt+mx);
        cnt+=sum;
        ans=max(ans,cnt);
    }
    cout << ans;
    return 0;
}
