#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=2;i<=n;i++)
        {
            if(a[i] <= a[i-1])++a[i];
        }
        set<int>st;
        for(i=1;i<=n;i++)st.insert(a[i]);
        cout << (int)st.size() << '\n';
    }
    return 0;