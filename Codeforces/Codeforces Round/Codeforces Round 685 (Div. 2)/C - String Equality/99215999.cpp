#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    bool ok;
    string a,b;
    int i,k,l,t,cntA[30],cntB[30];
    cin >> t;
    while(t--)
    {
        cin >> l >> k >> a >> b;
        memset(cntA,0,sizeof(cntA));
        memset(cntB,0,sizeof(cntB));
        for(i=0;i<l;i++)++cntA[a[i]-'a'],++cntB[b[i]-'a'];
        ok=1;
        for(i=0;i<26;i++)
        {
            if(cntA[i] != cntB[i])
            {
                if(cntA[i] < cntB[i])
                {
                    ok=0;
                    break;
                }
                if((cntA[i]-cntB[i])%k > 0)
                {
                    ok=0;
                    break;
                }
                cntA[i+1]+=cntA[i]-cntB[i];
            }
        }
        if(ok)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}