#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    LL ans;
    int i,l,t,cnt;
    char s[1000005];
    cin >> t;
    while(t--)
    {
        cin >> s+1;
        l=strlen(s+1);
        ans=cnt=0;
        map<int,int>mp;
        for(i=1;i<=l;i++)
        {
            if(s[i] == '-')--cnt;
            else ++cnt;
            if(mp.find(cnt) == mp.end())mp[cnt]=i;
        }
        for(i=0; ;i++)
        {
            if(mp.find(-i-1) == mp.end())
            {
                ans+=l;
                break;
            }
            else ans+=mp[-i-1];
        }
        cout << ans << '\n';
    }
    return 0;