#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,l,x=1,ans=-1,cnt=0,mx,my;
    cin >> s;
    s='0'+s;
    l=s.size();
    for(i=1;i<l;i++)
    {
        if(s[i] > s[i-1])cnt+=s[i]-'0';
        else
        {
            if(ans < cnt)
            {
                ans=cnt;
                mx=x,my=i-1;
            }
            x=i;
            cnt=s[i]-'0';
        }
    }
    if(ans < cnt)
    {
        ans=cnt;
        mx=x,my=i;
    }
    cout << ans << ':' << mx << '-' << my;
    return 0;
}