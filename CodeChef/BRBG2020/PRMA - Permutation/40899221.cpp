#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int mod=1e9+7;
int a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,n,r;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(l=1;l<=n;l++)
    {
        if(a[l] != l)break;
    }
    for(r=n;r>0;r--)
    {
        if(a[r] != r)break;
    }
    if(l > r)cout << "0 0";
    else
    {
        for(i=r;i>=l;i--)
        {
            if(a[i] != l+r-i)
            {
                cout << "0 0";
                return 0;
            }
        }
        cout << l << ' ' << r;
    }
    return 0;
}