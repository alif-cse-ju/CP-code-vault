#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,t,a[4];
    cin >> t;
    while(t--)
    {
        for(i=0;i<4;i++)cin >> a[i];
        sort(a,a+4);
        cout << a[0]*a[2] << '\n';
    }
    return 0;