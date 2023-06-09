#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int i,k,n;
double a[N];
bool Check(double x)
    int cnt=0;
    for(i=1;i<=n;i++)cnt+=(a[i]/x);
    return cnt >= k;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    double ans,cnt=70,high=1e7,low=0,mid;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    while(cnt--)
    {
        mid=(low+high)/2.0;
        if(Check(mid))ans=low=mid;
        else high=mid;
    }
    cout << setprecision(10) << ans;
    return 0;