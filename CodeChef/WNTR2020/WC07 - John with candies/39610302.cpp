#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t;
    long long ans,cnt,sum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum=0;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            sum+=a[i];
        }
        cnt=(sum/n)+(sum%n > 0);
        ans=cnt*n-sum;
        for(i=1;i<=n;i++)
        {
            if(a[i] > cnt)ans+=a[i]-cnt;
        }
        cout << ans << '\n';
    }
    return 0;
}