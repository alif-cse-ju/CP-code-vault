#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n;
    double x,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf",&x);
        ans+=(x/100.00);
    }
    printf("%.12lf",(ans/n)*100.00);
    return 0;