#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,x,ans=0;
    map<int,bool>mp;
    cin >> n;
    while(n--)
    {
        cin >> x;
        mp[x]=1;
        while(mp.find(ans) != mp.end())++ans;
        cout << ans << '\n';
    }
    return 0;
}
