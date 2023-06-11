#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,n,t,l,r;
    long long cur,mn,mx,mxProduct,a[100002];
    cin >> t;
    while(t--)
    {
        r=0;
        cin >> n;
        for(i=0;i<n;i++)cin >> a[i];
        mn=mx=mxProduct=a[0];
        for(i=1;i<n;i++)
        {
            if(a[i] < 0)swap(mn,mx);
            mn=min(a[i],a[i]*mn);
            mx=max(a[i],a[i]*mx);
            if(mx >= mxProduct)r=i,mxProduct=mx;
        }
        cur=1;
        for(i=r;i>-1;i--)
        {
            cur*=a[i];
            if(cur == mxProduct){l=i;break;}
        }
        cout << mxProduct << ' ' << l << ' ' << r << '\n';
    }
    return 0;
}