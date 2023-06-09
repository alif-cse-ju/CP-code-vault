#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,sum,a[55];
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum=0;
        for(i=0;i<n;i++)
        {
            cin >> a[i];
            sum+=a[i];
        }
        if(sum == 0)cout << "NO\n";
        else
        {
            sort(a,a+n);
            if(sum > 0)reverse(a,a+n);
            cout << "YES\n";
            for(i=0;i<n;i++)cout << a[i] << ' ';
            cout << '\n';
        }
    }
    return 0;