#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,m,n;
    cin >> n >> m;
    char s[n+2][m+2];
    for(i=1;i<=n;i++)cin >> s[i]+1;
    if(n == 1  ||  m == 1)cout << '0';
    else if(m > 3  &&  n > 3)cout << "-1";
    else
    {
        int cnt1=0,cnt2=0;
        if(m == 2)
        {
            for(i=1;i<=n;i++)
            {
                if(i & 1)
                {
                    if(s[i][1] == s[i][2])++cnt1;
                    else ++cnt2;
                }
                else
                {
                    if(s[i][1] != s[i][2])++cnt1;
                    else ++cnt2;
                }
            }
        }
        else if(n == 2)
        {
            for(i=1;i<=m;i++)
            {
                if(i & 1)
                {
                    if(s[1][i] == s[2][i])++cnt1;
                    else ++cnt2;
                }
                else
                {
                    if(s[1][i] != s[2][i])++cnt1;
                    else ++cnt2;
                }
            }
        }
        else if(n == 3)
        {
            int OE = 0, OO = 0, EO = 0, EE = 0;
            for(i = 1; i <= m; i += 2)
            {
                if(s[1][i] == '0' && s[2][i] == '0' && s[3][i] == '0')OE++, OO++, EO++;
                if(s[1][i] == '0' && s[2][i] == '0' && s[3][i] == '1')OE++, OO++, EE++;
                if(s[1][i] == '0' && s[2][i] == '1' && s[3][i] == '0')OE++, EO++, EE++;
                if(s[1][i] == '0' && s[2][i] == '1' && s[3][i] == '1')OO++, EO++, EE++;
                if(s[1][i] == '1' && s[2][i] == '0' && s[3][i] == '0')OO++, EO++, EE++;
                if(s[1][i] == '1' && s[2][i] == '0' && s[3][i] == '1')OE++, EO++, EE++;
                if(s[1][i] == '1' && s[2][i] == '1' && s[3][i] == '0')OE++, OO++, EE++;
                if(s[1][i] == '1' && s[2][i] == '1' && s[3][i] == '1')OE++, OO++, EO++;
            }
            for(i = 2; i <= m; i += 2)
            {
                if(s[1][i] == '0' && s[2][i] == '0' && s[3][i] == '0')EO++, EE++, OE++;
                if(s[1][i] == '0' && s[2][i] == '0' && s[3][i] == '1')EO++, EE++, OO++;
                if(s[1][i] == '0' && s[2][i] == '1' && s[3][i] == '0')OE++, EO++, OO++;
                if(s[1][i] == '0' && s[2][i] == '1' && s[3][i] == '1')OO++, OE++, EE++;
                if(s[1][i] == '1' && s[2][i] == '0' && s[3][i] == '0')OO++, OE++, EE++;
                if(s[1][i] == '1' && s[2][i] == '0' && s[3][i] == '1')OE++, EO++, OO++;
                if(s[1][i] == '1' && s[2][i] == '1' && s[3][i] == '0')EO++, OO++, EE++;
                if(s[1][i] == '1' && s[2][i] == '1' && s[3][i] == '1')OE++, EE++, EO++;
            }
            cnt1=min(OO, OE),cnt2=min(EO, EE);
        }
        else
        {
            int OE = 0, OO = 0, EO = 0, EE = 0;
            for(i = 1; i <= n; i += 2)
            {
                if(s[i][1] == '0' && s[i][2] == '0' && s[i][3] == '0')OE++, OO++, EO++;
                if(s[i][1] == '0' && s[i][2] == '0' && s[i][3] == '1')OE++, OO++, EE++;
                if(s[i][1] == '0' && s[i][2] == '1' && s[i][3] == '0')OE++, EO++, EE++;
                if(s[i][1] == '0' && s[i][2] == '1' && s[i][3] == '1')OO++, EO++, EE++;
                if(s[i][1] == '1' && s[i][2] == '0' && s[i][3] == '0')OO++, EO++, EE++;
                if(s[i][1] == '1' && s[i][2] == '0' && s[i][3] == '1')OE++, EO++, EE++;
                if(s[i][1] == '1' && s[i][2] == '1' && s[i][3] == '0')OE++, OO++, EE++;
                if(s[i][1] == '1' && s[i][2] == '1' && s[i][3] == '1')OE++, OO++, EO++;
            }
            for(i = 2; i <= n; i += 2)
            {
                if(s[i][1] == '0' && s[i][2] == '0' && s[i][3] == '0')EO++, EE++, OE++;
                if(s[i][1] == '0' && s[i][2] == '0' && s[i][3] == '1')EO++, EE++, OO++;
                if(s[i][1] == '0' && s[i][2] == '1' && s[i][3] == '0')OE++, EO++, OO++;
                if(s[i][1] == '0' && s[i][2] == '1' && s[i][3] == '1')OO++, OE++, EE++;
                if(s[i][1] == '1' && s[i][2] == '0' && s[i][3] == '0')OO++, OE++, EE++;
                if(s[i][1] == '1' && s[i][2] == '0' && s[i][3] == '1')OE++, EO++, OO++;
                if(s[i][1] == '1' && s[i][2] == '1' && s[i][3] == '0')EO++, OO++, EE++;
                if(s[i][1] == '1' && s[i][2] == '1' && s[i][3] == '1')OE++, EE++, EO++;
            }
            cnt1=min(OO, OE), cnt2=min(EO, EE);
        }
        cout << min(cnt1,cnt2);
    }
    return 0;
}