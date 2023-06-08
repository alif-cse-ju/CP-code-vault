#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e3+5;
const int N=2e5+5;
const int mod=1e9+7;
int n,xr[M];
bool Check(int l,int r)
    int cur=xr[l],cnt=1;
    while(r <= n)
    {
        if((xr[l] ^ xr[r]) == cur)l=r,++cnt;
        ++r;
    }
    if(l == n)return 1;
    if(!(xr[n] ^ xr[l])  &&  cnt > 1)return 1;
    return 0;
int main()
    FAST();
    bool pos;
    int i,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            xr[i]=xr[i-1]^x;
        }
        pos=0;
        for(i=1;i<n  &&  !pos;i++)pos |= Check(i,i+1);
        cout << (pos ? "YES\n" : "NO\n");
    }
    return 0;
}