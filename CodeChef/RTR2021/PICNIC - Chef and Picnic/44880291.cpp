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
int main()
{
    FAST();
    int i,n,t;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        ans=0;
        for(i=2;i<=n;i++)
        {
            if(a[i] < a[i-1])
            {
                ans+=a[i-1]-a[i];
                a[i]=a[i-1];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}