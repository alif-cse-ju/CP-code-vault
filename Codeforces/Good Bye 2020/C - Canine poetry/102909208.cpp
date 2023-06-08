#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
bool mark[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,t,ans;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        ans=0;
        l=(int)s.size();
        for(i=0;i<l;i++)mark[i]=0;
        for(i=1;i<l;i++)
        {
            mark[i] |= (s[i] == s[i-1]  &&  !mark[i-1]);
            if(i > 1)mark[i] |= (s[i] == s[i-2]  &&  !mark[i-2]);
            ans+=mark[i];
        }
        cout << ans << '\n';
    }
    return 0;