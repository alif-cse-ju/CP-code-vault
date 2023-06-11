#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a[4],i,n,ans=0;
    pair<pair<int,int>,int>p;
    map<pair<pair<int,int>,int>,int>mp;
    cin >> n;
    while(n--)
    {
        for(i=0;i<3;i++)cin >> a[i];
        sort(a,a+3);
        p.first.first=a[0];
        p.first.second=a[1];
        p.second=a[2];
        ++mp[p];
    }
    for(auto it : mp)
    {
        if(it.second == 1)++ans;
    }
    cout << ans;
    return 0;
}