#include<bits/stdc++.h>
using namespace std;
const int mx = 25005;
int cnt[mx][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        map<string,int>mp;
        int ache=0;
        while(n--)
        {
            string s;cin >> s;
            if(mp.find(s) == mp.end())mp[s]=++ache, cnt[ache][0]=cnt[ache][1]=0;
            int b;cin >> b;
            ++cnt[mp[s]][b];
        }
        int ans=0;
        for(int i=1;i<=ache;i++)ans += max(cnt[i][0], cnt[i][1]);
        cout << ans << '\n';
    }
    return 0;
}