#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[5005],b[5005];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,t;
    long long ans,temp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i],b[i]=0;
        ans=0;
        for(i=1;i<=n;i++)
        {
            temp=b[i];
            if(temp < a[i]-1)
            {
                ans+=a[i]-temp-1;
                temp+=a[i]-temp-1;
            }
            b[i+1]+=temp-a[i]+1;
            if(i+2 <= n)
            {
                for(j=i+2;j<=min(n,i+a[i]);j++)++b[j];
            }
        }
        cout << ans << '\n';
    }
    return 0;
//