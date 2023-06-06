#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

LL a[200000];

int main()
{
    FAST();
    int i,n;
    LL x,xr=0;
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i],xr^=a[i];
    for(i=0;i<n;i++)x=xr^a[i],cout << x << ' ';
    return 0;
}
