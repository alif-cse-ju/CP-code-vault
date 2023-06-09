#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,t,x;
    bool invalid;
    char s[N+2],ans[N+2];
    cin >> t;
    while(t--)
    {
        cin >> s+1 >> x;
        l=strlen(s+1);
        for(i=1;i<=l;i++)ans[i]='1';
        for(i=1;i<=l;i++)
        {
            if(s[i] == '0')
            {
                if(i-x > 0)ans[i-x]='0';
                if(i+x <= l)ans[i+x]='0';
            }
        }
        invalid=0;
        for(i=1;i<=l;i++)
        {
            if(s[i] == '1')
            {
                if((i <= x  ||  ans[i-x] == '0')  &&  (i+x > l  ||  ans[i+x] == '0'))
                {
                    invalid=1;
                    break;
                }
            }
        }
        if(invalid)cout << "-1\n";
        else
        {
            for(i=1;i<=l;i++)cout << ans[i];
            cout << '\n';
        }
    }
    return 0;
}