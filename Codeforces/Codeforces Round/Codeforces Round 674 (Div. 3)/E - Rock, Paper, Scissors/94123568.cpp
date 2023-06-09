#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a[3],b[3];
    int i,n,mn=0,mx=0;
    cin >> n;
    for(i=0;i<3;i++)cin >> a[i];
    for(i=0;i<3;i++)cin >> b[i];
    mx+=min(a[0],b[1]);
    mx+=min(a[1],b[2]);
    mx+=min(a[2],b[0]);
    if(a[0] > b[0]+b[2])mn+=a[0]-b[0]-b[2];
    if(a[1] > b[0]+b[1])mn+=a[1]-b[0]-b[1];
    if(a[2] > b[1]+b[2])mn+=a[2]-b[1]-b[2];
    cout << mn << ' ' << mx;
    return 0;