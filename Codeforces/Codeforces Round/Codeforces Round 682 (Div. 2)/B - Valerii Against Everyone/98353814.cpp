#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        set<int>st;
        for(i=0;i<n;i++)
        {
            cin >> x;
            st.insert(x);
        }
        if((int)st.size() == n)cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;