#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,l,n,r,ans=0;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=k;i++)cin >> b[i];
    b[k+1]=n+1,a[0]=INT_MIN,a[n+1]=INT_MAX;
    for(i=1;i<=n;i++)a[i]-=i;
    for(i=0;i<=k;i++)
    {
        l=b[i],r=b[i+1];
        if(a[l] > a[r])
        {
            cout << "-1";
            return 0;
        }
        vector<int>lis;
        for(j=l+1;j<r;j++)
        {
            if(a[l] <= a[j]  &&  a[j] <= a[r])
            {
                auto pos=upper_bound(lis.begin(),lis.end(),a[j]);
                if(pos == lis.end())lis.emplace_back(a[j]);
                else *pos=a[j];
            }
        }
        ans+=(r-l-1)-(int)lis.size();
    }
    cout << ans;
    return 0;
}