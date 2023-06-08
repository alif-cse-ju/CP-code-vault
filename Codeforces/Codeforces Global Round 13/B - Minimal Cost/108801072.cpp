#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag;
    int i,n,t,u,v,a[102];
    cin >> t;
    while(t--)
    {
        flag=0;
        cin >> n >> u >> v;
        set<int>st;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            st.insert(a[i]);
            if(i > 1  &&  abs(a[i]-a[i-1]) > 1)flag=1;
        }
        if((int)st.size() == 1)cout << min(u,v)+v << '\n';
        else if(!flag)cout << min(u,v) << '\n';
        else cout << "0\n";
    }
    return 0;