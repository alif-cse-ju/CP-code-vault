#include<bits/stdc++.h>
 using namespace std;
 const int N=1e3+5;
const long long mod=1e9+7;
 bool mark[N];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,m,n,r,x,cnt=0,pos,boro,choto;
    long long ans=1;
    cin >> n >> x >> pos;
    l=0,r=n,boro=n-x,choto=x-1;
    while(l < r)
    {
        m=(l+r) >> 1;
        mark[m]=1;
        if(m == pos)l=m+1;
        else if(m < pos)
        {
            if(!choto)
            {
                cout << "0";
                return 0;
            }
            ans=(ans*choto)%mod;
            --choto;
            l=m+1;
        }
        else
        {
            if(!boro)
            {
                cout << "0";
                return 0;
            }
            ans=(ans*boro)%mod;
            --boro;
            r=m;
        }
    }
    for(i=0;i<n;i++)cnt+=!mark[i];
    while(cnt)ans=(ans*cnt)%mod,cnt--;
    cout << ans;
    return 0;
}