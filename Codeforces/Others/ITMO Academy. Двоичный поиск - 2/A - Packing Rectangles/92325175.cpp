#include<bits/stdc++.h>
using namespace std;
long long h,n,w;
bool Check(long long x)
    return (x/w)*(x/h) >= n;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long low=0,mid,high=1;
    cin >> w >> h >> n;
    while(!Check(high))high*=2;
    while(high-low > 1)
    {
        mid=(low+high) >> 1;
        if(Check(mid))high=mid;
        else low=mid;
    }
    cout << high;
    return 0;