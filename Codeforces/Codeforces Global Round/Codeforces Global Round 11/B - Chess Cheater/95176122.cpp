#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,k,l,t,ans,cntL,cntW;
    cin >> t;
    while(t--)
    {
        cin >> l >> k >> s;
        ans=cntL=cntW=0;
        vector<int>L;
        for(i=0;i<l;i++)
        {
            if(s[i] == 'W')
            {
                ++ans;
                if(!i  ||  s[i-1] == 'L')++cntW;
            }
            else
            {
                ++cntL;
                if(!i  ||  s[i-1] == 'W')L.emplace_back(0);
                ++L.back();
            }
        }
        if(k >= cntL)cout << 2*l-1 << '\n';
        else if(!ans)cout << max(0,2*k-1) << '\n';
        else
        {
            ans+=k;
            ans <<= 1;
            if(s[0] == 'L')L[0]=INT_MAX;
            if(s[l-1] == 'L')L.back()=INT_MAX;
            sort(L.begin(),L.end());
            for(int it : L)
            {
                if(it > k)break;
                k-=it;
                --cntW;
            }
            cout << ans-cntW << '\n';
        }
    }
    return 0;
}