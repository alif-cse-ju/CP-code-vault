#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    bool ok;
    string s;
    int i,l,len,t,q,r;
    cin >> t;
    while(t--)
    {
        cin >> len >> q >> s;
        while(q--)
        {
            cin >> l >> r;
            --l,--r;
            ok=false;
            for(i=l-1;i>=0;i--)
            {
                if(s[i] == s[l])
                {
                    ok=1;
                    break;
                }
            }
            for(i=r+1;i<len;i++)
            {
                if(s[i] == s[r])
                {
                    ok=1;
                    break;
                }
            }
            if(ok)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}