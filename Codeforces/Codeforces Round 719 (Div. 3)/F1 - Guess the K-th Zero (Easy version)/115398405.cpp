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
    FAST();
    int ans,k,l,m,n,r,t,x,y;
    cin >> n >> t;
    while(t--)
    {
        cin >> k;
        l=1,r=n;
        while(l <= r)
        {
            m=(l+r) >> 1;
            cout << "? 1 " << m << endl;
            cin >> x;
            if(m-k >= x)ans=m,r=m-1;
            else l=m+1;
        }
        cout << "! " << ans << endl;
    }
    return 0;