#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
char s[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,j,k,l,t,x;
    cin >> t;
    while(t--)
    {
        ans=0;
        vector<int>v;
        cin >> l >> k >> s+1;
        for(i=1;i<=k;i++)
        {
            for(j=i;j<=l;j+=k)
            {
                if(s[j] == '1')v.emplace_back(j);
            }
            while(!v.empty())
            {
                x=v.back();
                v.pop_back();
                if(x-k < 1)
                {
                    if(x+k > l)++ans,s[x]='0';
                    else
                    {
                        if(s[x+k] == '1')continue;
                        ++ans,s[x+k]='1';
                    }
                }
                else
                {
                    if(x+k <= l  &&  s[x+k] == '1')continue;
                    if(s[x-k] == '1')continue;
                    ++ans,s[x-k]='1';
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}