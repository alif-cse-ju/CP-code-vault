#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,a[1002],fr[1002],rv[1002];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        fr[1]=1,rv[n]=n;
        for(i=2;i<=n;i++)
        {
            if(a[i] < a[fr[i-1]])fr[i]=i;
            else fr[i]=fr[i-1];
        }
        for(i=n-1;i>0;i--)
        {
            if(a[i] < a[rv[i+1]])rv[i]=i;
            else rv[i]=rv[i+1];
        }
        for(i=2;i<n;i++)
        {
            if(a[i] > a[fr[i-1]]  &&  a[i] > a[rv[i+1]])
            {
                cout << "YES\n";
                cout << fr[i-1] << ' ' << i << ' ' << rv[i+1] << '\n';
                break;
            }
        }
        if(i == n)cout << "NO\n";
    }
    return 0;