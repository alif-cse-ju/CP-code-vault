#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int a[200002];
bool mark[1000002];

int main()
{
    FAST();
    int i,j,n,ans=0;
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        if(!mark[a[i]])
        {
            if(i+1 < n  &&  a[i] == a[i+1])
            {
                for(j=a[i];j<=1000000;j+=a[i])mark[j]=1;
            }
            else
            {
                ans++;
                for(j=a[i]+a[i];j<=1000000;j+=a[i])mark[j]=1;
            }
        }
    }
    cout << ans;
    return 0;
}
