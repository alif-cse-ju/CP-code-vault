#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int m,n,t,x,mx,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        ans=mx=0;
        set<int>st;;
        while(n--)
        {
            cin >> x;
            if(x < m)++ans,mx=max(x,mx),st.insert(x);
            else if(x > m)++ans;
        }
        if(mx < m-1  ||  (int)st.size() < m-1)cout << "-1\n";
        else cout << ans << '\n';
    }
    return 0;
}