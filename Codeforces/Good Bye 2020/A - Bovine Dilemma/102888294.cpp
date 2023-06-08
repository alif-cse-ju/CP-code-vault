#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,t,a[52];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        set<int>st;
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)st.insert(a[j]-a[j-i]);
        }
        cout << (int)st.size() << '\n';
    }
    return 0;