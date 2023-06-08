#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N=2e5+5;
const int mod=1e9+7;
int n,a[N];
long long cnt[N];
long long Solve(int i)
    if(i > n)return 0;
    if(cnt[i] > 0)return cnt[i];
    return cnt[i]=a[i]+Solve(i+a[i]);
int main()
    FAST();
    int i,j,t;
    long long ans,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            cnt[i]=0;
        }
        ans=0;
        for(i=1;i<=n;i++)
        {
            x=Solve(i);
            ans=max(ans,x);
        }
        cout << ans << '\n';
    }
    return 0;
}