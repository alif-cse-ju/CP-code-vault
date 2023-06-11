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
    int i,k,m,n;
    long long ans=0;
    cin >> m >> n >> k;
    for(i=1;i<=m;i++)cin >> a[i];
    sort(a+1,a+m+1);
    for(i=1;i<=m;i++)
    {
        if(i <= k)ans+=n-a[i];
        else ans+=a[i];
    }
    cout << ans << '\n';
    return 0;
}