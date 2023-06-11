#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const LL N=1e5;
const LL mod=998244353;
LL fact[N+2];
void PreCal()
{
    fact[0]=1;
    for(LL i=1;i<=N;i++)fact[i]=(fact[i-1]*i)%mod;
}
LL BigMod(LL val,LL pow)
{
    LL res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
LL nCr(int n,int r)
{
    if(r > n)return 0;
    return fact[n]*BigMod(fact[r]*fact[n-r],mod-2)%mod;
}
int main()
{
    FAST();
    PreCal();
    LL cur,mx;
    int i,t,q,cntS[30],cntP[30];
    string s,p,ans;
    cin >> t;
    while(t--)
    {
        cin >> s;
        memset(cntS,0,sizeof(cntS));
        for(char c : s)++cntS[c-'a'];
        cin >> q;
        mx=0;
        ans="No Research This Month";
        while(q--)
        {
            cin >> p;
            memset(cntP,0,sizeof(cntP));
            for(char c : p)++cntP[c-'a'];
            cur=1;
            for(i=0;i<26;i++)
            {
                if(cntP[i])
                {
                    cur=cur*nCr(cntS[i],cntP[i]);
                    cur%=mod;
                }
            }
            cout << cur << '\n';
            if(cur > mx)
            {
                mx=cur;
                ans=p;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}