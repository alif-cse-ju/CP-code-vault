#include<bits/stdc++.h>
using namespace std;
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int a[5],x,y,z;
    scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
    sort(a,a+4);
    z=a[3]-a[0];
    y=a[3]-a[1];
    x=a[3]-a[2];
    printf("%d %d %d",x,y,z);
    return 0;