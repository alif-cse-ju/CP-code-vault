#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int i,n;
LL k,a[200005];

bool Check(LL val)
{
    LL cnt=0;
    for(i=1;i<=n;i++)
    {
        cnt+=a[i]/val;
        if(a[i]%val == 0)--cnt;
    }
    return cnt > k;
}

int main()
{
    FAST();
    LL l=1,m,r=0;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i],r=max(r,a[i]);
    while(l <= r)
    {
        m=(l+r) >> 1LL;
        if(Check(m))l=m+1;
        else r=m-1;
    }
    cout << l;
    return 0;
}
