#include<bits/stdc++.h>
 using namespace std;
 const int N=2e5+5;
const int mod=1e9+7;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,t,ans,cnt1,cnt2;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        ans=cnt1=cnt2=0;
        l=(int)s.size();
        for(i=0;i<l;i++)
        {
            if(s[i] == '(')++cnt1;
            else if(s[i] == ')')
            {
                if(cnt1)++ans,--cnt1;
            }
            else if(s[i] == '[')++cnt2;
            else
            {
                if(cnt2)++ans,--cnt2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}