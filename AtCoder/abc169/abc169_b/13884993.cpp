#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int i,n;
    LL ans=1,a[100005];
    const LL mx=(LL)1e18;
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    if(a[0] == 0)
    {
        cout << "0";
        return 0;
    }
    for(i=0;i<n;i++)
    {
        if(ans > mx/a[i])
        {
            cout << "-1";
            return 0;
        }
        ans*=a[i];
    }
    cout << ans;
    return 0;
}
