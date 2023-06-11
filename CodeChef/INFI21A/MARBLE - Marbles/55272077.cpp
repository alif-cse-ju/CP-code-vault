#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
char p[M],pp[M],s[M],ss[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,cnt,j,l,t;
    map<char,bool>vowelMark;
    vowelMark['a']=vowelMark['e']=vowelMark['i']=vowelMark['o']=vowelMark['u']=1;
    cin >> t;
    while(t--)
    {
        cin >> l >> s+1 >> p+1;
        ans=INT_MAX;
        for(char c='a';c<='z';c++)
        {
            for(j=1;j<=l;j++)
            {
                if(p[j] == '?')pp[j]=c;
                else pp[j]=p[j];
                if(s[j] == '?')ss[j]=c;
                else ss[j]=s[j];
            }
            cnt=0;
            for(j=1;j<=l;j++)
            {
                if(pp[j] == ss[j])continue;
                ++cnt;
                if(vowelMark.find(pp[j]) != vowelMark.end()  &&  vowelMark.find(ss[j]) != vowelMark.end())++cnt
                else if(vowelMark.find(pp[j]) == vowelMark.end()  &&  vowelMark.find(ss[j]) == vowelMark.end())
            }
            ans=min(ans,cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}