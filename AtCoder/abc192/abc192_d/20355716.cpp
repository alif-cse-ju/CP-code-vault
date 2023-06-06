#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
const int mod=1e9+7;

bool Check(const string& s,__int128_t m,__int128_t base)
{
    __int128_t ans=0;
    for(char c : s)
    {
        ans=ans*base+(c-'0');
        if(ans > m)return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    long long l,m,r,ans,mid,mx=0;
    cin >> s >> m;
    for(char c : s)mx=max(mx,(long long)(c-'0'));
    l=mx+1,r=m;
    while(l <= r)
    {
        mid=(l+r) >> 1LL;
        if(Check(s,m,mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    if(!Check(s,m,mx+1))cout << "0";
    else if((int)s.size() == 1)cout << "1";
    else cout << ans-mx;
    return 0;
}
//
