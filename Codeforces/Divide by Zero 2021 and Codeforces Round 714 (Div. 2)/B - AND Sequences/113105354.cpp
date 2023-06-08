#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[N];
long long fact[N];
void PreCal()
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%mod;
int main()
    FAST();
    int i,n,t;
    long long ans,cnt;
    PreCal();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1);
        for(i=2;i<=n;i++)
        {
            if((a[i] & a[1]) != a[1])break;
        }
        if(i <= n)
        {
            cout << "0\n";
            continue;
        }
        cnt=1;
        for(i=2;i<=n;i++)
        {
            if(a[i] == a[1])++cnt;
            else break;
        }
        ans=fact[n-2];
        ans=(ans*cnt--)%mod;
        ans=(ans*cnt--)%mod;
        cout << ans << '\n';
    }
    return 0;
}