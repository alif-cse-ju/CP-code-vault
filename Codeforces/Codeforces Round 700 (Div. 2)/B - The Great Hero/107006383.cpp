#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
long long a[N],b[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    bool possible;
    long long A,B,total;
    cin >> t;
    while(t--)
    {
        cin >> A >> B >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)cin >> b[i];
        total=possible=0;
        for(i=1;i<=n;i++)total+=((b[i]+A-1)/A)*a[i];
        for(i=1;i<=n;i++)
        {
            if(B-total+a[i] > 0)possible=1;
        }
        if(possible)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;