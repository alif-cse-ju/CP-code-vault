#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
char s[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,t;
    long long ans,x;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=strlen(s);
        ans=0,x=(s[0]-'a'+1)*100;
        for(i=0;i<l;i++)ans=(ans+x+(s[i]-'a'))%mod;
        cout << ans << '\n';
    }
    return 0;
}