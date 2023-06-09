#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,l,t,x;
    string s,ans;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        ans="";
        for(i=0;i<l;i++)
        {
            if(s[i] == '1')break;
            else ans+=s[i];
        }
        x=i;
        for(i=i+1;i<l;i++)
        {
            if(s[i] == '0'  &&  s[i-1] == '1')x=i;
        }
        if(x > ans.size())ans+='0';
        while(x < l  &&  s[x] == '0')x++;
        for(i=x;i<l;i++)ans+=s[i];
        cout << ans << '\n';
    }
    return 0;