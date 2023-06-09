#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
const int mod=1e9+7;
char s[N],p[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,ls,lp=0,cnt;
    long long ans=1;
    cin >> s+1;
    ls=strlen(s+1);
    for(i=1;i<=ls;i++)
    {
        if(s[i] == 'a'  ||  s[i] == 'b')p[++lp]=s[i];
    }
    cnt=0;
    for(i=1;i<=lp;i++)
    {
        if(p[i] == 'a')++cnt;
        else ans=(ans*(cnt+1))%mod,cnt=0;
    }
    if(cnt > 0)ans=(ans*(cnt+1))%mod;
    cout << ans-1;
    return 0;