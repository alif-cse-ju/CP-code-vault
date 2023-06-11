#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,t,n,ans,cnt[12];
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(cnt,0,sizeof(cnt));
        while(n--)
        {
            cin >> s;
            for(i=0;i<10;i++)
            {
                if(s[i] == '1')++cnt[i];
            }
        }
        ans=0;
        for(i=0;i<10;i++)
        {
            if(cnt[i] & 1)++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}