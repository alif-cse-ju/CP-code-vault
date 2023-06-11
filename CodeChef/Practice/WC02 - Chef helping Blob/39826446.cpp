#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int mod=1e9+7;
long long fact[N],inv[N];
long long BigMod(long long val,long long pow)
{
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
void PreCal()
{
    fact[0]=inv[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        inv[i]=BigMod(fact[i],mod-2);
    }
}
void Solve(string& s)
{
    int cnt=0;
    vector<int>v;
    long long ans=1;
    while(!s.empty()  &&  s.back() == 'b')
    {
        ++cnt;
        s.pop_back();
    }
    if(cnt)
    {
        v.emplace_back(cnt);
        ans=(ans*inv[cnt])%mod;
    }
    cnt=0;
    reverse(s.begin(),s.end());
    while(!s.empty()  &&  s.back() == 'b')
    {
        ++cnt;
        s.pop_back();
    }
    if(cnt)
    {
        v.emplace_back(cnt);
        ans=(ans*inv[cnt])%mod;
    }
    while(!s.empty())
    {
        while(!s.empty()  &&  s.back() == 'a')s.pop_back();
        cnt=0;
        while(!s.empty()  &&  s.back() == 'b')++cnt,s.pop_back();
        if(cnt)
        {
            v.emplace_back(cnt);
            ans=(ans*inv[cnt])%mod;
            ans=(ans*BigMod(2,cnt-1))%mod;
        }
    }
    cnt=0;
    for(int it : v)cnt+=it;
    ans=(ans*fact[cnt])%mod;
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    PreCal();
    int l,t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        Solve(s);
    }
    return 0;
}