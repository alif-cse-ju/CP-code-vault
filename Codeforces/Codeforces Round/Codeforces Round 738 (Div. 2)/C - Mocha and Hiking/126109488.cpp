#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++)cin >> a[i];
        int idx=0;
        for(int i=1;i<n;i++)
        {
            if(!a[i]  &&  a[i+1])
            {
                idx=i;
                break;
            }
        }
        if(!idx)
        {
            if(a[1])
            {
                cout << n+1;
                for(int i=1;i<=n;i++)cout << ' ' << i;
            }
            else
            {
                for(int i=1;i<=n+1;i++)cout << i << ' ';
            }
        }
        else
        {
            for(int i=1;i<=idx;i++)cout << i << ' ';
            cout << n+1;
            for(int i=idx+1;i<=n;i++)cout << ' ' << i;
        }
        cout << '\n';
    }
    return 0;
}