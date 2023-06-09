#include<bits/stdc++.h>
using namespace std;
#define SZ size()
#define FI first
#define SE second
#define PPB pop_back()
#define PII pair<int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>odd,even;
        for(i=1;i<=2*n;i++)
        {
            cin >> x;
            if(x & 1)odd.emplace_back(i);
            else even.emplace_back(i);
        }
        n--;
        vector<PII>ans;
        while(ans.SZ < n  &&  even.SZ > 1)
        {
            x=even.back(),even.PPB;
            y=even.back(),even.PPB;
            ans.emplace_back(x,y);
        }
        while(ans.SZ < n  &&  odd.SZ > 1)
        {
            x=odd.back(),odd.PPB;
            y=odd.back(),odd.PPB;
            ans.emplace_back(x,y);
        }
        for(PII bal : ans)cout << bal.FI << ' ' << bal.SE << '\n';
    }
    return 0;
}