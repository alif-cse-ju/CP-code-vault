#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
char s[10000002];
int ans[10000002];
int main()
{
    FAST();
    int i,l,t,q,x;
    cin >> t;
    while(t--)
    {
        cin >> s+1;
        stack<int>st;
        l=strlen(s+1);
        for(i=1;i<=l;i++)
        {
            ans[i]=-1;
            if(s[i] == '(')st.push(i);
            else
            {
                if(!st.empty())
                {
                    ans[st.top()]=i;
                    st.pop();
                }
            }
        }
        for(i=l-1;i>0;i--)
        {
            if(s[i] == ')')ans[i]=ans[i+1];
        }
        cin >> q;
        while(q--)
        {
            cin >> x;
            cout << ans[x] << '\n';
        }
    }
    return 0;
}