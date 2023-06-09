#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
char s[55];
int main()
    FAST();
    int i,j,k,l,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> l >> k >> s+1;
        for(i=1;i<=l;i++)
        {
            if(s[i] == '*')break;
        }
        ans=0;
        while(i <= l)
        {
            s[i]='x';
            ++ans;
            for(j=min(l,i+k);j>i;j--)
            {
                if(s[j] == '*')break;
            }
            if(i == j)break;
            i=j;
        }
        cout << ans << '\n';
    }
    return 0;
}