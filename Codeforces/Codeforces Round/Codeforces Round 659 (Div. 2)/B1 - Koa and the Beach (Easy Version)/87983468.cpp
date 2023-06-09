#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int depths[300005];
int main()
    FAST();
    bool ok,dec;
    int i,j,k,l,n,t,curTide;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> l;
        vector<int>safe;
        safe.emplace_back(0);
        for(i=1;i<=n;i++)
        {
            cin >> depths[i];
            if(depths[i]+k <= l)safe.emplace_back(i);
        }
        safe.emplace_back(n+1);
        ok=true;
        for(i=1;i<(int)safe.size()  &&  ok;i++)
        {
            curTide=k,dec=true;
            for(j=safe[i-1]+1;j<safe[i];j++)
            {
                if(dec)--curTide;
                else ++curTide;
                if(dec)curTide-=max(0,depths[j]+curTide-l);
                if(curTide < 0  ||  depths[j]+curTide > l)
                {
                    ok=false;
                    break;
                }
                if(curTide == 0)dec=false;
            }
        }
        if(ok)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}