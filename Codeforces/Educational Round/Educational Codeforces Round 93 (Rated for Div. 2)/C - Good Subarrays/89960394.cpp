#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    long long ans;
    char s[100002];
    int i,l,t,cnt[100002];
    cnt[0]=0;cin >> t;
    while(t--)
    {
        cin >> l >> s+1;
        for(i=1;i<=l;i++)cnt[i]=cnt[i-1]+(s[i]-'0');
        map<int,int>mp;
        mp[0]=1,ans=0;
        for(i=1;i<=l;i++)
        {
            cnt[i]-=i;
            if(mp.find(cnt[i]) != mp.end())ans+=mp[cnt[i]];
            ++mp[cnt[i]];
        }
        cout << ans << '\n';
    }
    return 0;