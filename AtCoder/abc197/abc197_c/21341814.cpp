#include<bits/stdc++.h>

using namespace std;

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=1e3+5;
const int mod=1e9+7;

int a[20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,l,n,ans,_or,xr;
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    ans=INT_MAX;
    l=(1 << n);
    for(i=0;i<l;i++)
    {
        _or=xr=0;
        for(j=0;j<n;j++)
        {
            _or |= a[j];
            if((i >> j) & 1)xr ^= _or,_or=0;
        }
        xr ^= _or;
        ans=min(ans,xr);
    }
    cout << ans;
    return 0;
}
//