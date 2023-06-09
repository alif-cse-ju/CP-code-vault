#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,l,t;
    long long a,b,ans;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> s+1;
        l=strlen(s+1);
        vector<pair<int,int>>v;
        v.emplace_back(1,1);
        for(i=2;i<=l;i++)
        {
            if(s[i] != s[i-1])v.emplace_back(0,i);
            ++v.back().first;
        }
        ans=0;
        l=v.size();
        if(s[1] == '0')i=2;
        else i=1;
        while(i < l-1)
        {
            if(v[i].first*b <= a)
            {
                ans+=v[i].first*b;
                for(j=v[i].second;j<v[i].second+v[i].first;j++)s[j]='1';
            }
            i+=2;
        }
        l=strlen(s+1);
        for(i=1;i<=l;i++)
        {
            if(s[i] == '1'  &&  (i == 1  ||  s[i-1] == '0'))ans+=a;
        }
        cout << ans << '\n';
    }
    return 0;
}