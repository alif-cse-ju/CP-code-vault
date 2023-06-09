#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,x,y,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=1,y=0;
        set<int>st;
        map<int,int>mp;
        for(i=0;i<n;i++)
        {
            cin >> x;
            ++mp[x];
            st.insert(x);
        }
        for(int x : st)
        {
            y+=mp[x];
            if(ans+y-1 >= x)ans+=y,y=0;
        }
        cout << ans << '\n';
    }
    return 0;