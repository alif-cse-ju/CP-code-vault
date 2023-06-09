#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,j,l,t,cnt;
    string s,tmp,f="abacaba";
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        cnt=0;
        for(i=0;i<=l-7;i++)
        {
            tmp=s.substr(i,7);
            if(tmp == f)++cnt;
        }
        if(cnt > 1)cout << "NO\n";
        else if(cnt == 1)
        {
            for(i=0;i<l;i++)
            {
                if(s[i] == '?')s[i]='z';
            }
            cout << "YES\n" << s << '\n';
        }
        else
        {
            for(i=0;i<=l-7;i++)
            {
                tmp=s.substr(i,7);
                for(j=0;j<7;j++)
                {
                    if(tmp[j] == '?')tmp[j]=f[j];
                }
                if(tmp == f)
                {
                    if(i+10 < l  &&  s[i+7] == 'c'  &&  s[i+8] == 'a'  &&  s[i+9] == 'b'  &&  s[i+10] == 'a')continue;
                    if(i-4 >= 0  &&  s[i-4] == 'a'  &&  s[i-3] == 'b'  &&  s[i-2] == 'a'  &&  s[i-1] == 'c')continue;
                    ++cnt;
                    for(j=i;j<i+7;j++)s[j]=f[j-i];
                    for(j=0;j<l;j++)
                    {
                        if(s[j] == '?')s[j]='z';
                    }
                    break;
                }
            }
            if(cnt)cout << "YES\n" << s << '\n';
            else cout << "NO\n";
        }
    }
    return 0;
}