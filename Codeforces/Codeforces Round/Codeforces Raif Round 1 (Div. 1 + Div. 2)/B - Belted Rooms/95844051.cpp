#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,l,t,ans,cnt1,cnt2,cnt3;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        cnt1=cnt2=cnt3=0;
        for(i=0;i<l;i++)
        {
            cnt1+=s[i] == '>';
            cnt2+=s[i] == '<';
            cnt3+=s[i] == '-';
        }
        if((cnt1+cnt3) == l  ||  (cnt2+cnt3) == l)cout << l << '\n';
        else
        {
            s+=s[0];
            ans=0;
            for(i=0;i<l;i++)ans+=(s[i] == '-'  ||  s[i+1] == '-');
            cout << ans << '\n';
        }
    }
    return 0;