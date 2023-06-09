#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N],b[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    for(i=j=1,k=(n+1)/2+1;i<=n;i++)
    {
        if(i & 1)b[i]=a[j++];
        else b[i]=a[k++];
    }
    for(i=2;i<=n;i+=2)
    {
        if(b[i] == b[i-1]  ||  b[i] == b[i+1])break;
    }
    if(i <= n)
    {
        if(b[i] == b[i+1])i++;
        for(j=1;j<=n;j++)
        {
            a[j]=b[i++];
            if(i > n)i=1;
        }
        for(i=2;i<=n;i+=2)
        {
            if(a[i] <= a[i-1]  ||  a[i] <= a[i+1])
            {
                cout << "-1";
                return 0;
            }
        }
        for(i=1;i<=n;i++)cout << a[i] << ' ';
    }
    else for(i=1;i<=n;i++)cout << b[i] << ' ';
    return 0;
}
//