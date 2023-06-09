#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,x,ans;
    string s;
    cin >> n;
    map<string,int>mp;
    mp["A"]=1e6;
    mp["B"]=1e6;
    mp["C"]=1e6;
    mp["AB"]=1e6;
    mp["AC"]=1e6;
    mp["BC"]=1e6;
    mp["ABC"]=1e6;
    for(i=1;i<=n;i++)
    {
        cin >> x >> s;
        sort(s.begin(),s.end());
        mp[s]=min(mp[s],x);
    }
    ans=mp["ABC"];
    ans=min(ans,mp["A"]+mp["B"]+mp["C"]);
    ans=min(ans,mp["A"]+mp["BC"]);
    ans=min(ans,mp["B"]+mp["AC"]);
    ans=min(ans,mp["C"]+mp["AB"]);
    ans=min(ans,mp["AB"]+min(mp["AC"],mp["BC"]));
    ans=min(ans,mp["AC"]+min(mp["AB"],mp["BC"]));
    ans=min(ans,mp["BC"]+min(mp["AB"],mp["AC"]));
    if(ans >= 1e6)cout << "-1";
    else cout << ans;
    return 0;