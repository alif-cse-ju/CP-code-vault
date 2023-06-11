#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s,ans1,ans2;
    int i,k,l,t,cnt0,cnt1,grp;
    cin >> t;
    while(t--)
    {
        cin >> l >> k >> s;
        cnt0=cnt1=0;
        for(i=0;i<l;i++)
        {
            if(s[i] == '0')++cnt0;
            else ++cnt1;
        }
        grp=l/k;
        if(cnt0%grp  ||  cnt1%grp)cout << "IMPOSSIBLE\n";
        else
        {
            cnt0/=grp,cnt1/=grp;
            ans1=ans2="";
            for(i=0;i<cnt0;i++)ans1+='0',ans2+='0';
            for(i=0;i<cnt1;i++)ans1+='1',ans2+='1';
            reverse(ans2.begin(),ans2.end());
            for(i=1;i<=grp;i++)
            {
                if(i & 1)cout << ans1;
                else cout << ans2;
            }
            cout << '\n';
        }
    }
    return 0;
}