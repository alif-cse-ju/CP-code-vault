#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e6+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    FAST();
    int i,k,n,t,x,a[105];
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<n  &&  k;i++)
        {
            x=min(a[i],k);
            k-=x,a[i]-=x,a[n]+=x;
        }
        for(i=1;i<=n;i++)cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;