#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=2e5+5;
int a[M],b[M],c[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        ll sum=0;
        for(int i=1; i<=n; i++)cin >> c[i], sum += c[i], a[i]=0;
        int cnt1=sum/n, l=n-cnt1+1;
        for(int i=l;i<=n;i++)b[i]=n;
        for(int i=n;i  &&  l<=i;i--)
        {
            if(b[i] == c[i])a[i]=1;
            else if(b[i] == c[i]+i-1)a[i]=0, b[--l]=i-1;
        }
        for(int i=1; i<=n; i++)cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;