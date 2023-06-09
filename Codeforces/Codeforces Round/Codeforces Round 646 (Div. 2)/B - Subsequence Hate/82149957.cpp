#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    string s;
    int i,n,t,ans,one,zero,cnt0[1005],cnt1[1005];
    cin >> t;
    while(t--)
    {
        cin >> s;
        n=s.size();
        one=cnt1[0]=(s[0] == '1');
        zero=cnt0[0]=(s[0] == '0');
        for(i=1;i<n;i++)
        {
            cnt0[i]=cnt0[i-1];
            cnt1[i]=cnt1[i-1];
            if(s[i] == '1')++one,++cnt1[i];
            else ++zero,++cnt0[i];
        }
        if(!one  ||  !zero)cout << "0\n";
        else
        {
            ans=INT_MAX;
            for(i=0;i<n;i++)
            {
                ans=min(ans,cnt1[i]+cnt0[n-1]-cnt0[i]);
                ans=min(ans,cnt0[i]+cnt1[n-1]-cnt1[i]);
            }
            cout << ans << '\n';
        }
    }
    return 0;