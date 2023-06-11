#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int q;
    LL a,b,s,x,ans=0,mod=1LL << 32;
    vector<bool>v(mod/2LL+1LL,false);
    cin >> q >> s >> a >> b;
    while(q--)
    {
        x=s/2LL;
        if(s & 1LL)
        {
            if(!v[x])
            {
                ans+=x;
                v[x]=1;
            }
        }
        else
        {
            if(v[x])
            {
                ans-=x;
                v[x]=0;
            }
        }
        s=(a*s+b)%mod;
    }
    cout << ans;
    return 0;
}