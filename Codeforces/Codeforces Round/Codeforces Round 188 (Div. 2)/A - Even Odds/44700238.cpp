#include<bits/stdc++.h>
using namespace std;
int main()
    long long int n,k,ans;
    cin >> n >> k ;
    if(k==1)
    {
        ans=1;
    }
    else if(n%2==0)
    {
        if(k<=n/2)
        {
            ans=2*k-1;
        }
        else
        {
            ans=2*(k-n/2);
        }
    }
    else
    {
        if(k<=n/2+1)
        {
            ans=2*k-1;
        }
        else
        {
            ans=2*(k-n/2-1);
        }
    }
    cout << ans << endl;
    return 0;