#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,a[55];
    long long odd,even,sum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        odd=even=0;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            if(i & 1)odd+=a[i];
            else even+=a[i];
        }
        sum=odd+even;
        if(odd > sum/2)
        {
            for(i=1;i<=n;i++)
            {
                if(i & 1)cout << a[i] << ' ';
                else cout << 1 << ' ';
            }
        }
        else
        {
            for(i=1;i<=n;i++)
            {
                if(i & 1)cout << 1 << ' ';
                else cout << a[i] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}