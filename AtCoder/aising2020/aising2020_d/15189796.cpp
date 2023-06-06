#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

LL BigMod(LL val,LL pow,LL mod)
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

int ans[200005],pre[200005];

void PreCal()
{
    int i,x;
    for(i=1;i<200001;i++)
    {
        x=i%__builtin_popcount(i);
        pre[i]=pre[x]+1;
    }
}

int main()
{
    FAST();
    PreCal();
    int i,n,x;
    char s[200005];
    LL cnt=0,sum1=0,sum2=0,mod1,mod2;
    cin >> n >> s+1;
    reverse(s+1,s+n+1);
    for(i=1;i<=n;i++)
    {
        if(s[i] == '1')++cnt;
    }
    if(cnt == 0)
    {
        for(i=1;i<=n;i++)cout << "1\n";
        return 0;
    }
    mod1=cnt-1,mod2=cnt+1;
    for(i=1;i<=n;i++)
    {
        if(s[i] == '1')
        {
            if(mod1)sum1=(sum1+BigMod(2,i-1,mod1))%mod1;
            sum2=(sum2+BigMod(2,i-1,mod2))%mod2;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(s[i] == '1'  &&  mod1)x=(sum1-BigMod(2,i-1,mod1)+mod1)%mod1;
        else if(s[i] == '0')x=(sum2+BigMod(2,i-1,mod2))%mod2;
        else continue;
        ans[n-i+1]=pre[x]+1;
    }
    for(i=1;i<=n;i++)cout << ans[i] << '\n';
    return 0;
}
