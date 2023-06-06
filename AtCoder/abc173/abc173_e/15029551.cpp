#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    LL x,y,ans=1;
    int i,k,n,ng,np;
    vector<LL>pos,neg;
    const LL mod=1e9+7;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> x;
        if(x < 0)neg.emplace_back(x);
        else pos.emplace_back(x);
    }
    ng=neg.size();
    np=pos.size();
    sort(neg.rbegin(),neg.rend());
    sort(pos.begin(),pos.end());
    if(ng == 0)
    {
        while(k--)
        {
            ans=(ans*pos.back())%mod;
            pos.pop_back();
        }
    }
    else if(np == 0)
    {
        if(k & 1)
        {
            for(i=0;i<k-1;i++)ans=(ans*abs(neg[i]))%mod;
            ans*=neg[k-1];
            ans%=mod;
            if(ans < 0)ans+=mod;
        }
        else
        {
            while(k--)
            {
                ans=(ans*abs(neg.back()))%mod;
                neg.pop_back();
            }
        }
    }
    else
    {
        if(k & 1)ans=pos[--np],--k;
        while(k > 1  &&  (np > 1  ||  ng > 1))
        {
            x=y=0;
            if(np > 1)x=pos[np-1]*pos[np-2];
            if(ng > 1)y=neg[ng-1]*neg[ng-2];
            if(x > y)
            {
                np-=2;
                x%=mod;
                ans=(ans*x)%mod;
            }
            else
            {
                ng-=2;
                y%=mod;
                ans=(ans*y)%mod;
            }
            k-=2;
        }
        while(k--)
        {
            if(np > 0)ans=(ans*pos[--np])%mod;
            else ans=((ans*neg[--ng])%mod+mod)%mod;
        }
    }
    cout << ans;
    return 0;
}
