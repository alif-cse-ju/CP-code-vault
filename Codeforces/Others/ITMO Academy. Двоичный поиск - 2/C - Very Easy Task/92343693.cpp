#include<bits/stdc++.h>
using namespace std;
long long n,x,y;
bool Check(int k)
    if(x <= y)return ((k-x)/x+(k-x)/y)+1 >= n;
    return ((k-y)/x+(k-y)/y)+1 >= n;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long l,m,r;
    cin >> n >> x >> y;
    l=min(x,y)-1,r=n*max(x,y);
    while(r > l+1)
    {
        m=(l+r) >> 1;
        if(Check(m))r=m;
        else l=m;
    }
    cout << r;
    return 0;