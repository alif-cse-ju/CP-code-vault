#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL a[100002],b[100002],tmp[100002],sum[100002];
int main()
    FAST();
    LL i,m,n,t,ans,check,pos;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n >> m;
        for(i=1;i<=m;i++)
        {
            cin >> a[i] >> b[i];
            tmp[i]=a[i];
        }
        sort(tmp+1,tmp+m+1);
        for(i=1;i<=m;i++)sum[i]=sum[i-1]+tmp[i];
        for(i=1;i<=m;i++)
        {
            pos=upper_bound(tmp+1,tmp+m+1,b[i])-tmp;
            if(pos > m)check=a[i]+(n-1)*b[i];
            else
            {
                pos=min(n,m-pos+1);
                check=sum[m]-sum[m-pos];
                if(a[i] > b[i])check+=(n-pos)*b[i];
                else check+=min(1LL,n-pos)*a[i]+max(0LL,n-pos-1LL)*b[i];
            }
            ans=max(ans,check);
        }
        cout << ans << '\n';
    }
    return 0;
}