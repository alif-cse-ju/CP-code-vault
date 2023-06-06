#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int i,n;
    LL xr=0,sum,rem;
    cin >> n;
    vector<LL>a(n);
    for(i=0;i<n;i++)cin >> a[i];
    sum=a[0]+a[1];
    for(i=2;i<n;i++)xr ^= a[i];
    if(sum%2 != xr%2)cout << "-1";
    else
    {
        rem=(sum-xr)/2LL;
        if(rem > a[0]  ||  (rem & xr))cout << "-1";
        else
        {
            for(i=40;i>-1;i--)
            {
                if(!((xr >> i) & 1))continue;
                if((rem | (1LL << i)) > a[0])continue;
                rem |= (1LL << i);
            }
            if(rem == 0)cout << "-1";
            else cout << a[0]-rem;
        }
    }
    return 0;
}
