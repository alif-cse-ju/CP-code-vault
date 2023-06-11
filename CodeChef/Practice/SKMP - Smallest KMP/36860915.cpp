#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    char check;
    string s,p;
    int i,t,cnt[26];
    cin >> t;
    while(t--)
    {
        cin >> s >> p;
        memset(cnt,0,sizeof(cnt));
        for(char c : s)++cnt[c-'a'];
        for(char c : p)--cnt[c-'a'];
        for(i=0;i<p[0]-'a';i++)
        {
            while(cnt[i]--)cout << (char)('a'+i);
        }
        check='0';
        for(char c : p)
        {
            if(c != p[0])
            {
                check=c;
                break;
            }
        }
        if(check == '0'  ||  check > p[0])
        {
            while(cnt[p[0]-'a']--)cout << (char)('a'+i);
        }
        cout << p;
        if(check != '0'  &&  check < p[0])
        {
            while(cnt[p[0]-'a']--)cout << (char)('a'+i);
        }
        for(i=p[0]-'a'+1;i<26;i++)
        {
            while(cnt[i]--)cout << (char)('a'+i);
        }
        cout << '\n';
    }
    return 0;
}