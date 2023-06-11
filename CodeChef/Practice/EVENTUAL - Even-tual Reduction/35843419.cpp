#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    string s;
    int i,l,t,cnt[30];
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<l;i++)++cnt[s[i]-'a'];
        for(i=0;i<26;i++)
        {
            if(cnt[i] & 1)
            {
                cout << "NO\n";
                break;
            }
        }
        if(i == 26)cout << "YES\n";
    }
    return 0;
}