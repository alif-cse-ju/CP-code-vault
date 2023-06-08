#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod=1e9+7;
long long c[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,m,n,t,x;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<int>k;
        for(i=0;i<n;i++)
        {
            cin >> x;
            k.emplace_back(x);
        }
        sort(k.begin(),k.end());
        reverse(k.begin(),k.end());
        set<int>st;
        for(i=1;i<=m;i++)
        {
            cin >> c[i];
            st.insert(i);
        }
        ans=0;
        for(int val : k)
        {
            auto it=st.begin();
            if(it == st.end()  ||  *(it) > val)ans+=c[val];
            else
            {
                ans+=c[*(it)];
                st.erase(it);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}