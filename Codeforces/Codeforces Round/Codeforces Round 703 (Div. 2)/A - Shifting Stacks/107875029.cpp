#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
long long a[105];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<n;i++)cin >> a[i];
        for(i=0;i<n;i++)
        {
            if(a[i] < i)break;
            a[i+1]+=a[i]-i;
        }
        if(i == n)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;