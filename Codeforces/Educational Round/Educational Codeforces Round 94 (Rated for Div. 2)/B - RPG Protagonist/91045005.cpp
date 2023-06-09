#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,t,fS,fW,pS,pW,ans;
    long long p,f,cS,cW,S,W;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> p >> f >> cS >> cW >> S >> W;
        for(i=0;i<=cS  &&  i*S <= p;i++)
        {
            pS=i,pW=min(cW,(p-i*S)/W);
            if(S <= W)
            {
                fS=min(cS-i,f/S);
                fW=min(cW-pW,(f-fS*S)/W);
            }
            else
            {
                fW=min(cW-pW,f/W);
                fS=min(cS-pS,(f-fW*W)/S);
            }
            ans=max(ans,fS+fW+pS+pW);
        }
        cout << ans << '\n';
    }
    return 0;