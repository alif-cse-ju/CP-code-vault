#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,j,k,n,t,ans,cnt[30];
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        set<char>st;
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<n;i++)
        {
            st.insert(s[i]);
            ++cnt[s[i]-'a'];
        }
        vector<int>v;
        for(char c : st)v.emplace_back(cnt[c-'a']);
        for(i=n;i>0;i--)
        {
            for(j=1;j<=i;j++)
            {
                if((j*k)%i == 0)break;
            }
            ans=0;
            for(int x : v)ans+=(x/j)*j;
            if(ans >= i)
            {
                ans=i;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}