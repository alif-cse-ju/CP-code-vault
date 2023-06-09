#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x,cnt0,cnt1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt0=cnt1=0;
        for(i=0;i<n;i++)
        {
            cin >> x;
            if(x == 0)++cnt0;
            else ++cnt1;
        }
        if(cnt0 >= n/2)
        {
            cout << n/2 << '\n';
            for(i=0;i<n/2;i++)cout << "0 ";
        }
        else
        {
            cout << n/2+((n/2) & 1) << '\n';
            for(i=0;i<n/2+((n/2) & 1);i++)cout << "1 ";
        }
        cout << '\n';
    }
    return 0;