#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
char s[55][55];
int main()
    FAST();
    int i,j,n,t;
    bool valid;
    cin >> t;
    while(t--)
    {
        cin >> n;
        valid=true;
        for(i=1;i<=n;i++)cin >> s[i]+1;
        for(i=n;i>0;i--)
        {
            for(j=n;j>0;j--)
            {
                if(s[i][j] == '1')
                {
                    if(i == n  ||  j == n  ||  s[i][j+1] == '1'  ||  s[i+1][j] == '1')continue;
                    valid=false;
                    break;
                }
            }
        }
        if(valid)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;