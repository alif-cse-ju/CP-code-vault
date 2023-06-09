#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,a[105];
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int check=0,mark;
    for(i=1;i<=n;i++)
    {
        if(a[i] > check)
        {
            check=a[i];
            mark=i;
        }
    }
    for(i=mark;i>1;i--)
    {
        swap(a[i],a[i-1]);
    }
    int ans=mark-1;
    check=110;
    for(i=1;i<=n;i++)
    {
        if(a[i] <= check)
        {
            check=a[i];
            mark=i;
        }
    }
    ans+=n-mark;
    cout << ans;
    return 0;
}