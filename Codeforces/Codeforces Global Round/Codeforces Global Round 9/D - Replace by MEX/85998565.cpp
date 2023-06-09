#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,x,y,z,check,a[1002],cnt[1002];
    cin >> t;
    while(t--)
    {
        cin >> n;
        set<int>st;
        for(i=0;i<=n;i++)cnt[i]=0,st.insert(i);
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            ++cnt[a[i]];
            if(st.find(a[i]) != st.end())st.erase(a[i]);
        }
        check=0;
        for(i=1;i<=n;i++)
        {
            if(a[i] == i-1)++check;
        }
        vector<int>ans;
        while(check < n)
        {
            x=*(st.begin());
            st.erase(x);
            z=min(n,x+1);
            if(z == n  &&  a[n] == n-1)
            {
                for(i=1;i<=n;i++)
                {
                    if(a[i] != i-1)
                    {
                        z=i;
                        break;
                    }
                }
                if(i > n)break;
            }
            y=a[z],a[z]=x;
            ++cnt[x];
            ans.emplace_back(z);
            if(x == z-1)++check;
            if(--cnt[y] == 0)st.insert(y);
        }
        cout << ans.size() << '\n';
        for(int it : ans)cout << it << ' ';
        cout << '\n';
    }
    return 0;
}