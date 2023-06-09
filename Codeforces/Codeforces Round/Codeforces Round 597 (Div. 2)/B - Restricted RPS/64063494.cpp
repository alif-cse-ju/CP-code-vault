#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c,i,n,t,cnt;
    string s;
    char ans[102];
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b >> c >> s;
        cnt=0;
        for(i=0;i<n;i++)
        {
            ans[i]='#';
            if(s[i] == 'R'  &&  b)--b,++cnt,ans[i]='P';
            else if(s[i] == 'P'  &&  c)--c,++cnt,ans[i]='S';
            else if(s[i] == 'S'  &&  a)--a,++cnt,ans[i]='R';
        }
        if(cnt < (n+1)/2)cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(i=0;i<n;i++)
            {
                if(ans[i] != '#')cout << ans[i];
                else
                {
                    if(a)--a,cout << 'R';
                    else if(b)--b,cout << 'P';
                    else --c,cout << 'S';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}