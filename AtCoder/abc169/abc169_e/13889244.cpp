#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int i,n,x,y,a[200005],b[200005];
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i] >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    x=a[n/2],y=b[n/2];
    if(n%2 == 0)x+=a[n/2-1],y+=b[n/2-1];
    cout << y-x+1;
    return 0;
}
