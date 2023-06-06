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

int main()
{
    FAST();
    int i,l,n,r,a[102],b[102];
    cin >> n;
    l=0,r=INT_MAX;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)cin >> b[i];
    for(i=1;i<=n;i++)
    {
        l=max(l,min(a[i],b[i]));
        r=min(r,max(a[i],b[i]));
    }
    cout << max(0,r-l+1);
    return 0;
}
